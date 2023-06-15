/** world.h
 */

#ifndef _WORLD_H_
#define _WORLD_H_

#include <cstdlib>
#include <vector>
#include "entity.h"
#include "hero.h"
#include "direction.h"

using std::vector;

class World
{
	Hero	*_h0;

	vector<Entity>	entity_lst;	// TODO this should be a Entity *

public:
	World () : _h0((Hero *)nullptr) {}

	Hero*	player (void);
	Hero*	player_set (Hero *const);	// TODO change to move ctor

	bool	move_check (const int,const int);
	int	move_to (Entity *const,const int,const int);
	int	move (Entity *const,const int,const int);
	int	move (Entity *const,const direction_t);

	void	draw (void);
};

#endif /* !_WORLD_H_ */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
