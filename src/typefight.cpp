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
	char s[80];
	Entity hero(0,0);
	Keymap keymap;
	keymap.keybind_add(Keybind("j", [&]() {hero.move(1,0); return 1;}));
	keymap.keybind_add("k", [&]() {hero.move(-1,0); return 1;});

	for (bool running=true; running; )
	    {
		switch ((ch=getch())) {
		case ERR:	/* no input */
			break;;

		case KEY_F(1):
			running = false;
			break;;

		default:
			s[0] = (char)ch & 0x7F;
			s[1] = '\0';
			keymap.invoke(Keyseq(s));
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
