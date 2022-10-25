/** entity.h
 * 	A spatial representation.
 * 	Represents the body and position of an entity.
 */

#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <cstdlib>

class Entity
{
	int	_pos_y;
	int	_pos_x;

public:
	Entity (const int pos_y,const int pos_x) : _pos_y(pos_y), _pos_x(pos_x) {}

	int	pos_y (void);
	int	pos_x (void);

	void	move_to (const int,const int);
	void	move (const int,const int);
};

#endif /* !_ENTITY_H_ */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
