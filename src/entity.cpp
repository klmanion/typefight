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
Entity::move_to(
    const int	y,
    const int	x)
{
	_pos_y = y;
	_pos_x = x;
}

void
Entity::move(
    const int	dy,
    const int	dx)
{
	int ny,nx;

	ny = _pos_y + dy;
	nx = _pos_x + dx;

	move_to(ny,nx);
}

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
