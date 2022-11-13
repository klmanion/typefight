/** keyseq.h
 * 	A sequence of keystroaks.
 */

#ifndef _KEYSEQ_H_
#define _KEYSEQ_H_

#include <cstdlib>
#include <string>

using std::string;

class Keyseq
{
	string	_seq;

public:
	Keyseq(const string str) : _seq(str) {}
	Keyseq(const int ncurs_ch)
		: Keyseq(string(1, (char)(ncurs_ch & 0x7F)))
		    {}	/* ncurses input */

	bool	operator== (const Keyseq &) const;
	bool	operator== (const string &) const;

	const string	to_string (void) const;
};

#endif /* !_KEYSEQ_H_ */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
