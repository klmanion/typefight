/** main.cpp: typefight
 * created by: Kurt L. Manion
 * on: 20 Sept 2022
 */

#include <cstdlib>
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
	return Typefight.begin();
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

	return;
}

void 
ncurses_deinitialize()
{
	endwin();

	return;
}

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
