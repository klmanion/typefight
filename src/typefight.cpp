/** typefight.cpp
 */

#include "typefight.h"

#include <iostream>
#include <ncurses.h>
#include "keymap.h"
#include "world.h"
#include "hero.h"

int
typefight()
{
	int ch;
	World world;
	Hero *plr;

	plr = (Hero *)world.add_entity(new Hero(0,0));

	Keybind keybind_tab[] = {
		Keybind("j",	[&]() {world.move(plr, DIRCT_S); return 1;}),
		Keybind("k",	[&]() {world.move(plr, DIRCT_N); return 1;}),
		Keybind("h",	[&]() {world.move(plr, DIRCT_W); return 1;}),
		Keybind("l",	[&]() {world.move(plr, DIRCT_E); return 1;}),
		Keybind("y",	[&]() {world.move(plr, DIRCT_NW); return 1;}),
		Keybind("u",	[&]() {world.move(plr, DIRCT_NE); return 1;}),
		Keybind("b",	[&]() {world.move(plr, DIRCT_SW); return 1;}),
		Keybind("n",	[&]() {world.move(plr, DIRCT_SE); return 1;}),
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
		world.draw();
	    }

	delete plr;

	return EXIT_SUCCESS;
}

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
