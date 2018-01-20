#include "stdafx.h"
#include "SpriteHandler.h"

sf::RenderWindow* SpriteHandler::Window;

SpriteHandler::SpriteHandler()
{
}


SpriteHandler::~SpriteHandler()
{
}

void SpriteHandler::SortDepth()
{
	bool swapped;
	if (GSprite::SpriteList.Size() > 1)
	{
		for (int i = 0; i < GSprite::SpriteList.Size() - 1; i++)
		{
			swapped = false;
			for (int j = 0; j < GSprite::SpriteList.Size() - i - 1; j++)
			{
				if (GSprite::SpriteList[j].GetDepth() > GSprite::SpriteList[j + 1].GetDepth())
				{
					GSprite::SpriteList.Swap(j, j + 1);
					swapped = true;
				}
			}

			if (swapped == false)
			{
				break;
			}
		}
	}

}

void SpriteHandler::DrawSprites()
{
	for (int i = 0; i < GSprite::SpriteList.Size(); i++)
	{
		Window->draw(GSprite::SpriteList[i].GetSprite());
	}
	GSprite::SpriteList.RemoveAll();
}
