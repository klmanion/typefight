/** direction.h
 * 	Datatype to encode direction.
 *+
 *	The directions are indicated as so:
 *
 *		NW	N	NE
 *		W	C	E
 *		SW	S	SE
 *+
 *	Each cardinal direction is indicated by a bit.
 *
 *		|	N	S	E	W	|	Hex
 *	--------+---------------------------------------+---------------
 *	NW	|	1			1	|	0x9
 *	N	|	1				|	0x8
 *	NE	|	1		1		|	0xA
 *	W	|				1	|	0x1
 *	C	|					|	0x0
 *	E	|			1		|	0x2
 *	SW	|		1		1	|	0x5
 *	S	|		1			|	0x4
 *	SE	|		1	1		|	0x6
 *+
 *	Macros are defined to test directionalities.
 *
 *	Note: North and true-north are different;
 *		NW, N, and NE are all north.
 */

#ifndef _DIRECTION_H_
#define _DIRECTION_H_

/* bits representing each cardinal direction */
#define NORTH_BIT	0x8
#define SOUTH_BIT	0x4
#define EAST_BIT	0x2
#define WEST_BIT	0x1
#define CENTER		0x0

/* tests for cardinality */
#define IS_CENTER(d)		((d) == CENTER)

#define IS_NORTH(d)		((d) & NORTH_BIT)
#define IS_NORTH_TRUE(d)	((d) == NORTH_BIT)
#define IS_NWEST(d)		((d) == (NORTH_BIT | WEST_BIT))
#define IS_NEAST(d)		((d) == (NORTH_BIT | EAST_BIT))

#define IS_WEST(d)		((d) & WEST_BIT)
#define IS_WEST_TRUE(d)		((d) == WEST_BIT)

#define IS_EAST(d)		((d) & EAST_BIT)
#define IS_EAST_TRUE(d)		((d) == EAST_BIT)

#define IS_SOUTH(d)		((d) & SOUTH_BIT)
#define IS_SOUTH_TRUE(d)	((d) == SOUTH_BIT)
#define IS_SWEST(d)		((d) == (SOUTH_BIT | WEST_BIT))
#define IS_SEAST(d)		((d) == (SOUTH_BIT | WEST_BIT))

/* directions */
#define DIRCT_NW	((direction_t)(NORTH_BIT | WEST_BIT))
#define DIRCT_N		((direction_t)NORTH_BIT)
#define DIRCT_NE	((direction_t)(NORTH_BIT | EAST_BIT))

#define DIRCT_W		((direction_t)WEST_BIT)
#define DIRCT_C		((direction_t)CENTER)
#define DIRCT_E		((direction_t)EAST_BIT)

#define DIRCT_SW	((direction_t)(SOUTH_BIT | WEST_BIT))
#define DIRCT_S		((direction_t)SOUTH_BIT)
#define DIRCT_SE	((direction_t)(SOUTH_BIT | EAST_BIT))

enum direction_t {
	NW	=	0x9,
	N	=	0x8,
	NE	=	0xA,
	W	=	0x1,
	C	=	0x0,
	E	=	0x2,
	SW	=	0x5,
	S	=	0x4,
	SE	=	0x6
};

int	direction_coord_y (const direction_t);
int	direction_coord_x (const direction_t);

#endif /* !_DIRECTION_H_ */
