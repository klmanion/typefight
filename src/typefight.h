/** typefight.h
 */

#ifndef _TYPEFIGHT_H_
#define _TYPEFIGHT_H_

#include <cstdlib>
#include "keymap.h"
#include "world.h"
#include "hero.h"

struct Model
{
	Keymap	keymap;

	World	world;

	Hero	*plr;

	int	steps;

	Model() {
		plr = (Hero *)nullptr;
		steps = 0;
	}

	~Model() {
		delete plr;
	}
};

__BEGIN_DECLS
int	typefight (Model &);
__END_DECLS

#endif /* !_TYPEFIGHT_H_ */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
