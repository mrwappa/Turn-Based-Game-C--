#ifndef TILESET_H
#define TILESET_H

#include "Entity.h"

class TileSet : public Entity
{
public:
	TileSet(float aX, float aY, int aRows, int aColumns);
	~TileSet();
	static sf::Texture Tile;

	void Update();
	void Draw();

private:
	GrowingArray<GrowingArray<GSprite*>*> myTileArray;
	float myX;
	float myY;
	
};
#endif // !TILESET_H