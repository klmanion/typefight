/** keyseq.cpp
 */

#include "keyseq.h"

bool
Keyseq::operator==(
    const Keyseq	&keyseq) const
{
	return _seq == keyseq.to_string();
}

bool
Keyseq::operator==(
    const string	&str) const
{
	return *this == Keyseq(str);
}

const string
Keyseq::to_string() const
{
	return _seq;
}

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
