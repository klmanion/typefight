/** typefight.cpp
 */

#include "typefight.h"

#include <iostream>
#include <ncurses.h>
#include <tuple>
#include "keymap.h"
#include "world.h"

using std::to_string;
using std::tuple, std::make_tuple;
using std::move;

int
typefight()
{
	int ch;
	Entity hero(0,0);
	World world;

	Keybind keybind_tab[] = {
		new Keybind("j",	[&]() {world.move(hero, 1,0); return 1;}),
		new Keybind("k",	[&]() {world.move(hero, -1,0); return 1;}),
		new Keybind("h",	[&]() {world.move(hero, 0,-1); return 1;}),
		new Keybind("l",	[&]() {world.move(hero, 0,1); return 1;}),
		new Keybind("y",	[&]() {world.move(hero, -1,-1); return 1;}),
		new Keybind("u",	[&]() {world.move(hero, -1,1); return 1;}),
		new Keybind("b",	[&]() {world.move(hero, 1,-1); return 1;}),
		new Keybind("n",	[&]() {world.move(hero, 1,1); return 1;}),
	};

	Keymap keymap;
	for (size_t i = 0; i < sizeof(keybind_tab)/sizeof(*keybind_tab); ++i)
	    keymap.keybind_add(move(keybind_tab[i]));

	for (bool running=true; running; )
	    {
		switch ((ch=getch())) {
		case ERR:	/* no input */
			break;;

		case KEY_F(1):
			running = false;
			break;;

		default:
			keymap.invoke(Keyseq(string(1, (char)(ch & 0x7F))));	// TODO accept ncurses output for keyseq ctor
			break;;
		}

		clear();
		mvaddch(hero.pos_y(),hero.pos_x(), 'o');
	    }

	return EXIT_SUCCESS;
}

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
