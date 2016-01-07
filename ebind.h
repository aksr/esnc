/*
 * File: ebind.h
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
 * This table is *roughly* in ASCII order, left to right across the
 * characters of the command. This expains the funny location of the
 * control-X commands.
 */

KEYTAB keytab[] = {
  {CTRL | '@', setmark},
  {CTRL | 'A', gotobol},
  {CTRL | 'B', backchar},
  {CTRL | 'D', forwdel},
  {CTRL | 'E', gotoeol},
  {CTRL | 'F', forwchar},
  {CTRL | 'G', ctrlg},
  {CTRL | 'H', backdel},
  {CTRL | 'I', tab},
  {CTRL | 'K', killtext},
  {CTRL | 'L', refresh},
  {CTRL | 'M', newline},
  {CTRL | 'N', forwline},
  {CTRL | 'O', openline},
  {CTRL | 'P', backline},
  {CTRL | 'Q', quote},
  {CTRL | 'R', backsearch},
  {CTRL | 'S', forwsearch},
  {CTRL | 'T', twiddle},
  {CTRL | 'V', forwpage},
  {CTRL | 'W', killregion},
  {CTRL | 'Y', yank},
  {CTLX | '(', ctlxlp},
  {CTLX | ')', ctlxrp},
  {CTLX | '1', onlywind},
  {CTLX | '2', splitwind},
  {CTLX | '=', showcpos},
  {CTLX | 'B', usebuffer},
  {CTLX | 'E', ctlxe},
  {CTLX | 'F', setfillcol},
  {CTLX | 'K', killbuffer},
  {CTLX | 'N', filename},
  {CTLX | 'O', nextwind},
  {CTLX | 'X', nextbuffer},
  {CTLX | '^', enlargewind},
  {CTLX | CTRL | 'B', listbuffers},
  {CTLX | CTRL | 'C', quit},
  {CTLX | CTRL | 'F', filefind},
  {CTLX | CTRL | 'I', insfile},
  {CTLX | CTRL | 'R', fileread},
  {CTLX | CTRL | 'S', filesave},
  {CTLX | CTRL | 'W', filewrite},
  {META | ' ', setmark},
  {META | '%', qreplace},
  {META | '.', setmark},
  {META | '<', gotobob},
  {META | '>', gotoeob},
  {META | 'B', backword},
  {META | 'C', capword},
  {META | 'D', delfword},
  {META | 'F', forwword},
  {META | 'G', gotoline},		/* non-standard */
  {META | 'L', lowerword},
  {META | 'N', gotoeop},
  {META | 'P', gotobop},
  {META | 'Q', fillpara},
  {META | 'R', sreplace},
  {META | 'U', upperword},
  {META | 'V', backpage},
  {META | 'W', copyregion},
  {META | 'Z', quickexit},
  {META | 0x7F, delbword},
  {META | CTRL | 'H', delbword},
  {META | CTRL | 'N', namebuffer},
  {META | CTRL | 'V', scrnextdw},
  {META | CTRL | 'Z', scrnextup},	/* non-standard */
  {0x7F, backdel},
  {META | '[', extendedcmd},
  {META | 'O', extendedcmd},
  {0, 0}
};
