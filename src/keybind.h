/** keybind.h
 * 	Element of the keymap
 */

#ifndef _KEYBIND_H_
#define _KEYBIND_H_

#include <cstdlib>
#include <string>
#include "keyseq.h"
#include "command.h"

#ifdef DEBUG
#include <iostream>
#endif /* !DEBUG */

using std::string;

class Keybind
{
	Keyseq	_seq;
	Command	_com;

public:
	Keybind (const Keyseq &seq,const Command &com)
		: _seq(seq), _com(com)
		    {
#ifdef DEBUG
			std::cerr << "keybind alloc " << this << std::endl;
#endif /* !DEBUG */
		    }
	Keybind (const string &str,const Command &com)
		: Keybind(Keyseq(str), com) {}
	Keybind (const char *const cstr,const Command &com)
		: Keybind(string(cstr), com) {}

	~Keybind();

//	Keybind&	operator= (Keybind &&) = default;

	bool	operator== (const Keyseq &) const;

	int	call (void) const;
};

#endif /* !_KEYBIND_H_ */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
