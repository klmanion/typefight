/** typefight.cpp
 */

#include "typefight.h"

#include <iostream>
#include <ncurses.h>
#include <tuple>
#include "entity.h"
#include "keymap.h"

using std::to_string;
using std::tuple, std::make_tuple;

int
typefight()
{
	int ch;
	Entity hero(0,0);

	Keybind keybind_tab[] = {
		Keybind("j",	[&]() {hero.move(1,0); return 1;}),
		Keybind("k",	[&]() {hero.move(-1,0); return 1;}),
		Keybind("h",	[&]() {hero.move(0,-1); return 1;}),
		Keybind("l",	[&]() {hero.move(0,1); return 1;}),
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
			keymap.invoke(Keyseq(string(1, (char)(ch & 0x7F))));
			break;;
		}

		clear();
		mvaddch(hero.pos_y(),hero.pos_x(), 'o');
	    }

	return EXIT_SUCCESS;
}

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
