/** keybind.h
 * 	Element of the keymap
 */

#ifndef _KEYBIND_H_
#define _KEYBIND_H_

#include <cstdlib>
#include <string>
#include "keyseq.h"
#include "command.h"

class Keybind
{
	Keyseq	_seq;
	Command	_com;
public:
	Keybind (const Keyseq seq,const Command com)
		: _seq(seq), _com(com) {}
	Keybind (const char *const cstr,const Command com)
		: Keybind(string(cstr), com) {}
	~Keybind();

	bool	operator== (const Keyseq &) const;

	int	call (void) const;
};

#endif /* !_KEYBIND_H_ */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
