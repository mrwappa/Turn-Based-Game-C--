#include "stdafx.h"
#include "TileSet.h"

sf::Texture TileSet::Tile;

TileSet::TileSet(float aX, float aY, int aRows, int aColumns) : Entity("TileSet")
{
	myX = aX;
	myY = aY;
	Tile.loadFromFile("Sprites/32x32Block.png");
	for (int i = 0; i < aRows; i++)
	{
		myTileArray.Add(new GrowingArray<GSprite*>);
		for (int j = 0; j < aColumns; j++)
		{
			myTileArray[i]->Add(new GSprite(Tile,1));
		}
	}
}


TileSet::~TileSet()
{
	for (int i = 0; i < myTileArray.Size(); i++)
	{
		myTileArray[i]->DeleteAll();
	}
	for (int i = 0; i < myTileArray.Size(); i++)
	{
		myTileArray.DeleteAll();
	}
}

void TileSet::Update()
{
	
}

void TileSet::Draw()
{
	for (int i = 0; i < myTileArray.Size(); i++)
	{
		for (int j = 0; j < myTileArray[i]->Size(); j++)
		{
			myTileArray[i]->FindAtIndex(j)->Draw(myX + i*32,myY + j*32,1,1,0,3,1,sf::Color::White,0);
		}
	}
}
