/** keymap.cpp
 */

#include "keymap.h"

#ifdef DEBUG
#include <iostream>
#endif /* !DEBUG */

using std::move;

Keymap::~Keymap()
{
//	for (auto it = _kbds.begin(); it != _kbds.end(); ++it)
//	    delete *it;
}

void
Keymap::keybind_add(
    const Keybind	&&keybind)
{
	_kbds.push_back(keybind);
}

void
Keymap::keybind_add(
    const Keyseq	&kseq,
    const Command	&com)
{
	keybind_add(Keybind(kseq, com));
}

void
Keymap::keybind_add(
    const string	&str,
    const Command	&com)
{
	keybind_add(Keybind(str, com)); // this advances to decompose the string
}

int
Keymap::invoke(
    const Keyseq	&kseq) const
{
#ifdef DEBUG
			std::cerr << "invoke: " << kseq.to_string() << std::endl;
#endif /* !DEBUG */
	for (auto it = _kbds.begin(); it != _kbds.end(); ++it)
	    {
		if (*it == kseq)
		    {
#ifdef DEBUG
			std::cerr << "match" << std::endl;
#endif /* !DEBUG */
			return it->call();
		    }
	    }

	return 0;
}
	


/* vi: set ts=8 sw=8 noexpandtab tw=79: */
