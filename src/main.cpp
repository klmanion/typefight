/** main.cpp: typefight
 * created by: Kurt L. Manion
 * on: 20 Sept 2022
 */

#include <clocale>
#include <iostream>
#include <ncurses.h>
#include "typefight.h"

using namespace std;

__BEGIN_DECLS
void 	ncurses_initialize (void) __attribute__((constructor));
void 	ncurses_deinitialize (void) __attribute__((destructor));
__END_DECLS

int
main(
    int		argc,
    char *const	argv[])
{
	Model model;

	model.plr = (Hero *)model.world.add_entity(new Hero(0,0));

	Keymap &keymap = model.keymap;
	World &world = model.world;
	Hero *plr = model.plr;

	Keybind keybind_tab[] = {
		Keybind("j",
			[&]() {world.add_movement(Movement(plr, DIRCT_S, 1));
				return 1;}),
		Keybind("k",
			[&]() {world.add_movement(Movement(plr, DIRCT_N, 1));
				return 1;}),
		Keybind("h",
			[&]() {world.add_movement(Movement(plr, DIRCT_W, 1));
				return 1;}),
		Keybind("l",
			[&]() {world.add_movement(Movement(plr, DIRCT_E, 1));
				return 1;}),
		Keybind("y",
			[&]() {world.add_movement(Movement(plr, DIRCT_NW, 1));
				return 1;}),
		Keybind("u",
			[&]() {world.add_movement(Movement(plr, DIRCT_NE, 1));
				return 1;}),
		Keybind("b",
			[&]() {world.add_movement(Movement(plr, DIRCT_SW, 1));
				return 1;}),
		Keybind("n",
			[&]() {world.add_movement(Movement(plr, DIRCT_SE, 1));
				return 1;}),
	};

	for (size_t i = 0; i < sizeof(keybind_tab)/sizeof(*keybind_tab); ++i)
	    keymap.keybind_add(keybind_tab[i]);

	return typefight(model);
}

void 
ncurses_initialize()
{
	setlocale(LC_ALL, "");

	initscr();
	halfdelay(2);
	noecho();
	nonl();
	intrflush(stdscr, FALSE);
	keypad(stdscr, TRUE);
}

void 
ncurses_deinitialize()
{
	endwin();
}

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
