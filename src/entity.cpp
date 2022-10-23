/** entity.cpp
 */

#include "entity.h"

int
Entity::pos_y()
{
	return _pos_y;
}

int
Entity::pos_x()
{
	return _pos_x;
}

void
Entity::move(
    const int	dy,
    const int	dx)
{
	_pos_y += dy;
	_pos_x += dx;

	return;
}



/* vi: set ts=8 sw=8 noexpandtab tw=79: */
