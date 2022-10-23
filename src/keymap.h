/** keymap.h
 * 	Vector of keybinds for keysequences to be checked against.
 * 	Key sequences bind surjectively to named commands,
 * 	which are names (strings) associated to lambdas.
 */

#ifndef _KEYMAP_H_
#define _KEYMAP_H_

#include <cstdlib>
#include <vector>
#include <string>
#include "keybind.h"

using std::vector;
using std::string;

class Keymap
{
	vector<const Keybind *>	_kbds;

public:
	~Keymap();

	const Keybind*	keybind_add (const Keybind *const);
	const Keybind*	keybind_add (const Keyseq &,const Command &);
	const Keybind*	keybind_add (const string &,const Command &);

	int	invoke (const Keyseq &) const;
};

#endif /* !_KEYMAP_H_ */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
