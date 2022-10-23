/** keymap.cpp
 */

#include "keymap.h"

#ifdef DEBUG
#include <iostream>
#endif /* !DEBUG */

Keymap::~Keymap()
{
	for (auto it = _kbds.begin(); it != _kbds.end(); ++it)
	    delete *it;
}

const Keybind*
Keymap::keybind_add(
    const Keybind *const	keybind)
{
	_kbds.push_back(keybind);

	return keybind;
}

const Keybind*
Keymap::keybind_add(
    const Keyseq	&kseq,
    const Command	&com)
{
	return keybind_add(new Keybind(kseq, com));
}

const Keybind*
Keymap::keybind_add(
    const string	&str,
    const Command	&com)
{
	return keybind_add(new Keybind(str, com));
}

int
Keymap::invoke(
    const Keyseq	&kseq) const
{
	for (auto it = _kbds.begin(); it != _kbds.end(); ++it)
	    {
		if (**it == kseq)
		    {
#ifdef DEBUG
			std::cerr << "match" << std::endl;
#endif /* !DEBUG */
			return (*it)->call();
		    }
	    }

	return 0;
}
	


/* vi: set ts=8 sw=8 noexpandtab tw=79: */
