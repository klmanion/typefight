/** typefight.cpp
 */

#include "typefight.h"

#include <ncurses.h>

Typefight::Typefight()
{
	y = x = 0;
}

Typefight::~Typefight()
{

}

int
Typefight::begin()
{
	int ch;

	for (bool running=true; running; )
	    {
		switch ((ch=getch())) {
		case ERR:	/* no input */
			break;;

		case KEY_F(1):
			running = false;
			break;;

		case 'j':
			++y;
			break;;

		case 'k':
			--y;
			break;;

		case 'h':
			--x;
			break;;

		case 'l':
			++x;
			break;;
		}

		clear();
		mvaddch(y,x, 'o');
	    }

	return EXIT_SUCCESS;
}

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
