/** movement.cpp
 */

#include "movement.h"

bool
Movement::is_done()
{
	return (_duration == 0);
}

void
Movement::step()
{
	if (_duration == -1)
	    {
		_target->move(_direction);
	    }
	else if (_duration > 0)
	    {
		_target->move(_direction);
		--_duration;
	    }
	else
	    {
		return;
	    }
}

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
