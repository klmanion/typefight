/** entity.h
 * 	A spatial representation.
 * 	Represents the body and position of an entity.
 */

#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "direction.h"

class Entity
{
	int	_pos_y;
	int	_pos_x;

	direction_t	_facing;

	char	_ch;

public:
	Entity (const int pos_y,const int pos_x,const direction_t facing,const char ch)
		: _pos_y(pos_y), _pos_x(pos_x),
		  _facing(facing), _ch(ch) {}

		virtual ~Entity () {}

	int		pos_y (void);
	int		pos_x (void);
	direction_t	facing (void);
	char		ch (void);

	void	move_to (const int,const int);
	void	move (const int,const int);
	void	move (const direction_t);

	void	draw (void);
};

#endif /* !_ENTITY_H_ */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
