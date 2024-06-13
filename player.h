#ifndef PLAYER_HEADER
#define PLAYER_HEADER
#include "grid.h"

enum Direction{
	top = 'z',
	left = 'q',
	right = 'd',
	bottom = 's'
};

void move_player(struct Grid* g,enum Direction d);

#endif
