/** direction.cpp
 * 	Assumes origin at top left.
 */

#include "direction.h"

int
direction_coord_y(
    const direction_t	d)
{
	return IS_NORTH(d)? -1 : !!IS_SOUTH(d);
}

int
direction_coord_x(
    const direction_t	d)
{
	return IS_WEST(d)? -1 : !!IS_EAST(d);
}

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
