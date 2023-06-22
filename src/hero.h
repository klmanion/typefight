/** hero.h
 */

#ifndef _HERO_H_
#define _HERO_H_

#include "direction.h"
#include "entity.h"
#include "ball.h"

class Hero : public Entity
{

public:
	Hero (const int pos_y,const int pos_x) : Entity(pos_y,pos_x, DIRCT_C, 'o') {}

	Ball*	shoot (void);

	void	draw (void);
};

#endif /* !_HERO_H_ */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
