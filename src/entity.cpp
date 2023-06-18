/** entity.cpp
 */

#include "entity.h"

#include <ncurses.h>

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

void
Entity::move(
    direction_t	d)
{
	move(direction_coord_y(d),direction_coord_x(d));
}

void
Entity::draw()
{
	return;
}

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
