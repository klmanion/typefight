/** model.h
 */

#ifndef _MODEL_H_
#define _MODEL_H_

#include "keymap.h"
#include "world.h"
#include "clock.h"
#include "hero.h"

struct Model
{
	Keymap	keymap;

	World	world;

	Clock	clock;

	Hero	*plr;

	Model() {
		plr = (Hero *)nullptr;
	}

	~Model() {

	}

	Model&	step (void);
};

#endif /* !_MODEL_H_ */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
