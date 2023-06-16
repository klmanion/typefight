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
		Keybind("j",	[&]() {world.move(plr, DIRCT_S); return 1;}),
		Keybind("k",	[&]() {world.move(plr, DIRCT_N); return 1;}),
		Keybind("h",	[&]() {world.move(plr, DIRCT_W); return 1;}),
		Keybind("l",	[&]() {world.move(plr, DIRCT_E); return 1;}),
		Keybind("y",	[&]() {world.move(plr, DIRCT_NW); return 1;}),
		Keybind("u",	[&]() {world.move(plr, DIRCT_NE); return 1;}),
		Keybind("b",	[&]() {world.move(plr, DIRCT_SW); return 1;}),
		Keybind("n",	[&]() {world.move(plr, DIRCT_SE); return 1;}),
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
