/** clock.h
 */

#ifndef _CLOCK_H_
#define _CLOCK_H_

#include <ctime>

class Clock
{
	int	_ticks;
	int	_steps;

	bool	_running;

public:
	Clock() : _ticks(0), _steps(0), _running(true) {}

	int	ticks (void);
	int	steps (void);

	void	tick (void);
	void	step (void);

	bool	toggle (void);
};

#endif /* !_CLOCK_H_ */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
