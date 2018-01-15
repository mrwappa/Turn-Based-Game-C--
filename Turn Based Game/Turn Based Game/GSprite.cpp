#include "stdafx.h"
#include "GSprite.h"


GSprite::GSprite()
{

}


GSprite::~GSprite()
{

}
//Modifiers
#pragma region
void GSprite::SetTexture(sf::Texture aTexture)
{
	myTexture = aTexture;
}

void GSprite::SetSprite(sf::Sprite aSprite)
{
	mySprite = aSprite;
}

void GSprite::SetX(float aX)
{
	myX = aX;
}

void GSprite::SetY(float aY)
{
	myY = aY;
}

void GSprite::SetXScale(float aXScale)
{
	myXScale = aXScale;
}

void GSprite::SetYScale(float aYScale)
{
	myYScale = aYScale;
}

void GSprite::SetNrOfFrames(int aNrOfFrames)
{
	myNrOfFrames = aNrOfFrames;
}

void GSprite::SetAnimationIndex(int aIndex)
{
	myAnimationIndex = aIndex;
}

void GSprite::SetAnimationSpeed(float aSpeed)
{
	myAnimationSpeed = aSpeed;
}

#pragma endregion