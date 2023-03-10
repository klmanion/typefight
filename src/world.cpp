/** world.cpp
 */

#include "world.h"

bool
World::move_check(
    const int	y,
    const int	x)
{
	return 1;
}

int
World::move_to(
    Entity	&e,
    const int	 y,
    const int	 x)
{
	if (!move_check(y,x))
	    return 0;

	/* TODO check from entity's side */

	e.move_to(y,x);
	return 1;
}

int
World::move(
    Entity	&e,
    const int	 dy,
    const int	 dx)
{
	int ny,nx;

	ny = e.pos_y() + dy;
	nx = e.pos_x() + dx;

	return move_to(e, ny,nx);
}

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
