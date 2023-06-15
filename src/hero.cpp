/** hero.cpp
 */

#include "hero.h"

#include <ncurses.h>

void
Hero::draw()
{
	mvaddch(pos_y(),pos_x(), 'o');
}

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
