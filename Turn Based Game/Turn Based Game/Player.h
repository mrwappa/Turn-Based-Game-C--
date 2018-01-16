#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity
{
public:
	Player(float aX, float aY);
	~Player();

	void Draw();
};

#endif // !PLAYER_H