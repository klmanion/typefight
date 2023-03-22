/** typefight.cpp
 */

#include "typefight.h"

#include <iostream>
#include <ncurses.h>
#include "keymap.h"
#include "world.h"

int
typefight()
{
	int ch;
	Entity hero(0,0);
	World world;

	Keybind keybind_tab[] = {
		Keybind("j",	[&]() {world.move(hero, DIRCT_S); return 1;}),
		Keybind("k",	[&]() {world.move(hero, DIRCT_N); return 1;}),
		Keybind("h",	[&]() {world.move(hero, DIRCT_W); return 1;}),
		Keybind("l",	[&]() {world.move(hero, DIRCT_E); return 1;}),
		Keybind("y",	[&]() {world.move(hero, DIRCT_NW); return 1;}),
		Keybind("u",	[&]() {world.move(hero, DIRCT_NE); return 1;}),
		Keybind("b",	[&]() {world.move(hero, DIRCT_SW); return 1;}),
		Keybind("n",	[&]() {world.move(hero, DIRCT_SE); return 1;}),
	};

	Keymap keymap;
	for (size_t i = 0; i < sizeof(keybind_tab)/sizeof(*keybind_tab); ++i)
	    keymap.keybind_add(keybind_tab[i]);

	for (bool running=true; running; )
	    {
		switch ((ch=getch())) {
		case ERR:	/* no input */
			break;;

		case KEY_F(1):
			running = false;
			break;;

		default:
			keymap.invoke(Keyseq(ch));
			break;;
		}

		clear();
		mvaddch(hero.pos_y(),hero.pos_x(), 'o');
	    }

	return EXIT_SUCCESS;
}

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
