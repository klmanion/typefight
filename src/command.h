/** command.h
 * 	Command bound to a keysequence.
 */

#ifndef _COMMAND_H_
#define _COMMAND_H_

#include <cstdlib>
#include <functional>

using std::function;

typedef	function<int(void)>	Command;

#endif /* !_COMMAND_H_ */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
