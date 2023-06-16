/** model.h
 */

#ifndef _MODEL_H_
#define _MODEL_H_

#include "keymap.h"
#include "world.h"
#include "hero.h"

struct Model
{
	Keymap	keymap;

	World	world;

	Hero	*plr;

	int	ticks;

	Model() {
		plr = (Hero *)nullptr;
		ticks = 0;
	}

	~Model() {

	}

	Model&	step (void);
};

#endif /* !_MODEL_H_ */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
