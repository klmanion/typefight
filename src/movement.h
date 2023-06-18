/** movement.h
 * 	Class to define types of movements.
 */

#ifndef _MOVEMENT_H_
#define _MOVEMENT_H_

#include "direction.h"
#include "entity.h"

class Movement
{
	Entity		*_target;

	direction_t	_direction;
	int		_duration;

public:
	Movement (Entity *t,direction_t dir,int dur)
		: _target(t), _direction(dir), _duration(dur) {}

	bool	is_done (void);

	void	step (void);
};

#endif /* !_MOVEMENT_H_ */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
