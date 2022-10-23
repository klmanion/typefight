/** typefight.cpp
 */

#include "typefight.h"

#include <iostream>
#include <ncurses.h>
#include "entity.h"
#include "keymap.h"

using std::to_string;

int
typefight()
{
	int ch;
	Entity hero(0,0);
	Keymap keymap;
	Keybind *move_down = new Keybind("j", [&]() {hero.move(1,0); return 1;});
	Keybind *move_up = new Keybind("k", [&]() {hero.move(-1,0); return 1;});

	keymap.keybind_add(move_down);
	keymap.keybind_add(move_up);

	for (bool running=true; running; )
	    {
		switch ((ch=getch())) {
		case ERR:	/* no input */
			break;;

		case KEY_F(1):
			running = false;
			break;;

		default:
		    keymap.invoke(Keyseq(to_string(ch)));
		    break;;
		}

		clear();
		mvaddch(hero.pos_y(),hero.pos_x(), 'o');
	    }


//#ifdef DEBUG
//	Keyseq kseq_foo("foo");
//	Keyseq kseq_bar("bar");
//
//	std::cerr << (kseq_foo == string("foo")) << std::endl;
//
//	Keymap keymap;
//
//	keymap.add_keybind(new Keybind(kseq_foo, nullptr));
//	keymap.add_keybind(kseq_bar, nullptr);
//
//#endif /* !DEBUG */

//	for (bool running=true; running; )
//	    {
//		switch ((ch=getch())) {
//		case ERR:	/* no input */
//			break;;
//
//		case KEY_F(1):
//			running = false;
//			break;;
//
//		case 'j':
//			hero.move(1,0);
//			break;;
//
//		case 'k':
//			hero.move(-1,0);
//			break;;
//
//		case 'h':
//			hero.move(0,-1);
//			break;;
//
//		case 'l':
//			hero.move(0,1);
//			break;;
//		}
//
//		clear();
//		mvaddch(hero.pos_y(),hero.pos_x(), 'o');
//	    }

	return EXIT_SUCCESS;
}

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
