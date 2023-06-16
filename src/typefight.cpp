/** typefight.cpp
 */

#include "typefight.h"

#include <ncurses.h>

int
typefight(
    Model	&model)
{
	int ch;

	Keymap &keymap = model.keymap;
	World &world = model.world;

	switch ((ch=getch())) {
	case ERR:	/* no input */
		break;;

	case KEY_F(1):
		return EXIT_SUCCESS;
		break;;

	default:
		keymap.invoke(Keyseq(ch));
		break;;
	}

	clear();
	world.draw();

	return typefight(model.step());
}

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
