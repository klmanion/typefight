/** ball.h
 * 	Ki ball shot by hero.
 */

#ifndef _BALL_H_
#define _BALL_H_

#include "entity.h"

class Ball : public Entity
{
public:
	Ball (const int pos_y,const int pos_x,const direction_t direction,const char ch)
		: Entity(pos_y,pos_x, direction, ch) {}

	Ball (Entity *entity)
		: Ball(entity->pos_y(),entity->pos_x(), entity->facing(), '*') {}
};

#endif /* !_BALL_H_ */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
