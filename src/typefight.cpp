/** typefight.cpp
 */

#include "typefight.h"

#include <ncurses.h>

int
typefight(
    Model	&model)
{
	int ch;
	char b[1024];

	Keymap &keymap = model.keymap;
	World &world = model.world;
	Clock &clock = model.clock;

	switch ((ch=getch())) {
	case ERR:	/* no input */
		break;;

	case KEY_F(1):
		return EXIT_SUCCESS;
		break;;

	case ' ':
		clock.toggle();
		break;;

	default:
		keymap.invoke(Keyseq(ch));
		break;;
	}

	clear();
	world.draw();

	sprintf(b, "%d/%d", clock.steps(), clock.ticks());
	mvaddstr(LINES-1,COLS-10, b);
	
	return typefight(model.step());
}

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
