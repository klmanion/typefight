/** world.h
 */

#ifndef _WORLD_H_
#define _WORLD_H_

#include <cstdlib>
#include <vector>
#include "entity.h"

using std::vector;

class World
{
	vector<Entity>	entity_lst;	// TODO this should be a Entity *
public:
	bool	move_check (const int,const int);
	int	move_to (Entity&,const int,const int);
	int	move (Entity&,const int,const int);
};

#endif /* !_WORLD_H_ */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
