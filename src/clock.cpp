/** clock.cpp
 */

#include "clock.h"

int
Clock::ticks()
{
	return _ticks;
}

int
Clock::steps()
{
	return _steps;
}

void
Clock::tick()
{
	if (_running)
	    step();

	++_ticks;
}

void
Clock::step()
{
	/* TODO callbacks */

	++_steps;
}

bool
Clock::toggle()
{
	return (_running = !_running);
}

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
