/** keybind.cpp
 */
/** keybind.cpp
 */

#include "keybind.h"

#include <iostream>

Keybind::~Keybind()
{
#ifdef DEBUG
	std::cerr << "keybind " << this << " dealloc" << std::endl;
#endif /* !DEBUG */
}

int
Keybind::call() const
{
#ifdef DEBUG
	std::cerr << "calling call()" << std::endl;
#endif /* !DEBUG */
	return _com();
}

bool
Keybind::operator==(
    const Keyseq	&seq) const
{
	return _seq == seq;
}

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
