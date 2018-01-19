#ifndef SPRITEHANDLER_H
#define SPRITEHANDLER_H

#include "GrowingArray.h"
#include "GSprite.h"
#include "SFML\Graphics.hpp"

class SpriteHandler
{
public:
	SpriteHandler();
	~SpriteHandler();

	static sf::RenderWindow* Window;

	void SortDepth();
	void DrawSprites();

};

#endif // !SPRITEHANDLER_H
