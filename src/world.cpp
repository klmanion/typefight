/** world.cpp
 */

#include "world.h"

Entity*
World::add_entity(
    Entity *const	e)
{
	_entity_lst.push_back(e);
	return e;
}

bool
World::move_check(
    const int	y,
    const int	x)
{
	return 1;
}

int
World::move_to(
    Entity *const	e,
    const int	 	y,
    const int	 	x)
{
	if (!move_check(y,x))
	    return 0;

	/* TODO check from entity's side */

	e->move_to(y,x);
	return 1;
}

int
World::move(
    Entity *const	e,
    const int		dy,
    const int		dx)
{
	int ny,nx;

	ny = e->pos_y() + dy;
	nx = e->pos_x() + dx;

	return move_to(e, ny,nx);
}

int
World::move(
    Entity *const	e,
    const direction_t	d)
{
	return move(e, direction_coord_y(d),direction_coord_x(d));
}

void
World::draw()
{
	for (auto it = _entity_lst.begin(); *it; ++it)
	    {
		Entity *e;

		e = *it;

		e->draw();
	    }
}

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
