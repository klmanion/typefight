/** main.cpp: typefight
 * created by: Kurt L. Manion
 * on: 20 Sept 2022
 */

#include <cstdlib>
#include <clocale>
#include <iostream>
#include <ncurses.h>

using namespace std;

int
main(
    int		argc,
    char *const	argv[])
{
	int ch;
	int y,x;

	setlocale(LC_ALL, "");

	initscr();
	halfdelay(2);
	noecho();
	nonl();
	intrflush(stdscr, FALSE);
	keypad(stdscr, TRUE);

	y = x = 0;

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

	endwin();

	return EXIT_SUCCESS;
}

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
