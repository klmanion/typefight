/** world.h
 */

#ifndef _WORLD_H_
#define _WORLD_H_

#include <cstdlib>
#include <vector>
#include "entity.h"
#include "direction.h"

using std::vector;

class World
{
	vector<Entity *>	_entity_lst;	/* TODO free in dtor */

public:
	Entity*	add_entity (Entity *const);

	bool	move_check (const int,const int);
	int	move_to (Entity *const,const int,const int);
	int	move (Entity *const,const int,const int);
	int	move (Entity *const,const direction_t);

	void	draw (void);
};

#endif /* !_WORLD_H_ */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
