/** world.h
 */

#ifndef _WORLD_H_
#define _WORLD_H_

#include <vector>
#include <list>
#include "entity.h"
#include "movement.h"

using std::vector;
using std::list;

class World
{
	vector<Entity *>	_entity_lst;
	list<Movement>		_movement_lst;

public:
	~World() {
		for (auto& e : _entity_lst)
		    delete e;
	}

	Entity*	add_entity (Entity *);
	void	add_movement (Movement);

	bool	move_check (const int,const int);
	int	move_to (Entity *const,const int,const int);
	int	move (Entity *const,const int,const int);
	int	move (Entity *const,const direction_t);

	void	step (void);
	void	draw (void);
};

#endif /* !_WORLD_H_ */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
