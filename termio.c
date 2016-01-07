/*
 * File: termio.c
 * Date: 2011-12-28
 *
 * Evsiz (evsiz@this-voice.org)
 * Essence released under the GNU GPL
 * See COPYING file for details.
 *
 * Essence is a fork of Chris Baird's ersatz emacs which was
 * in the public domain.  It was a fork of MicroEMACS 3.6
 * which was also in the public domain.  See README for 
 * more historical details.
 *
 */



/*
 * The functions in this file negotiate with the operating system for
 * characters, and write characters in a barely buffered fashion on the
 * display
 */

#undef CTRL
#include <termios.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>		/* puts(3), setbuffer(3), ... */
#include <sys/ioctl.h>		/* to get at the typeahead */

extern void exit(int);

void ttopen ();
void ttclose ();
void ttputc (int c);
void ttflush ();
int ttgetc ();
int typahead ();

#define	TBUFSIZ	128
char tobuf[TBUFSIZ];		/* terminal output buffer */
struct termios ostate, nstate;

/*
 * This function is called once to set up the terminal device streams.
 */
void ttopen ()
{
  /* save terminal flags */
  if ((tcgetattr(0, &ostate) < 0) || (tcgetattr(0, &nstate) < 0))
    {
      puts ("Can't read terminal capabilites\n");
      exit (1);
    }
  cfmakeraw(&nstate);		/* set raw mode */
  nstate.c_cc[VMIN] = 1;
  nstate.c_cc[VTIME] = 0;	/* block indefinitely for a single char */
  if (tcsetattr(0, TCSADRAIN, &nstate) < 0)
    {
      puts ("Can't set terminal mode\n");
      exit (1);
    }
  /* provide a smaller terminal output buffer so that the type ahead
   * detection works better (more often) */
  setbuffer (stdout, &tobuf[0], TBUFSIZ);
  signal (SIGTSTP, SIG_DFL);
}

/*
 * This function gets called just before we go back home to the command
 * interpreter
 */
void ttclose ()
{
  ttflush ();
  if (tcsetattr(0, TCSADRAIN, &ostate) < 0)
    {
      puts ("Can't restore terminal flags");
      exit (1);
    }
}

/*
 * Write a character to the display
 */
void ttputc (int c)
{
  fputc (c, stdout);
}

/*
 * Flush terminal buffer. Does real work where the terminal output is buffered
 * up. A no-operation on systems where byte at a time terminal I/O is done
 */
void ttflush ()
{
  tcdrain (0);
  fflush (stdout);
}

/*
 * Read a character from the terminal, performing no editing and doing no echo
 * at all
 */
int ttgetc ()
{
  return (127 & fgetc (stdin));
}

/* typahead: Check to see if any characters are already in the keyboard buffer
 */
int typahead ()
{
  int x;			/* holds # of pending chars */
  return ((ioctl (0, FIONREAD, &x) < 0) ? 0 : x);
}
