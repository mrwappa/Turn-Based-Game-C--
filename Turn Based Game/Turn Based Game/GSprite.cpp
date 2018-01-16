#include "stdafx.h"
#include "GSprite.h"

sf::Shader* GSprite::DepthShader;
sf::RenderWindow* GSprite::Window;

GSprite::GSprite()
{
	myWidth = 0;
	myHeight = 0;
	myTextureHeight = 0;
	myTextureWidth = 0;

	myNrOfFrames = 1;
	myAnimationCounter = 0;
	myAnimationSpeed = 0;
	myAnimationIndex = 0;
}


GSprite::~GSprite()
{

}
void GSprite::Draw(float aX, float aY, float aXScale, float aYScale, float aAngle , float aDepth, sf::Color aColor)
{
	if (myAnimationSpeed > 0)
	{
		myAnimationCounter += myAnimationSpeed;
		if (myAnimationCounter >= 1)
		{
			myAnimationIndex++;
			myAnimationCounter--;
			if (myAnimationIndex >= myNrOfFrames)
			{
				myAnimationIndex = 0;
			}
		}
	}

	mySprite.setTextureRect(sf::IntRect(myAnimationIndex * myTextureWidth / myNrOfFrames, 0, myTextureWidth / myNrOfFrames, myTextureHeight));
	mySprite.setPosition(aX, aY);
	mySprite.setOrigin(myTextureWidth / myNrOfFrames / 2, myTextureHeight / 2);
	mySprite.setRotation(aAngle);
	mySprite.setScale(aXScale, aYScale);
	mySprite.setColor(aColor);

	myWidth = myTextureWidth * aXScale;
	myHeight = myTextureHeight * aYScale;

	DepthShader->setUniform("depth", aDepth);
	Window->draw(mySprite,DepthShader);
}

//Modifiers
#pragma region
void GSprite::SetTexture(std::string aFileName , int aNrOfFrames)
{
	if (!myTexture.loadFromFile(aFileName)) { throw "file not found"; }

	mySprite.setTexture(myTexture);
	myNrOfFrames = aNrOfFrames;
	myTextureWidth = myTexture.getSize().x;
	myTextureHeight = myTexture.getSize().y;
}

void GSprite::SetSprite(sf::Sprite aSprite)
{
	mySprite = aSprite;
}

/*void GSprite::SetX(float aX)
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
}*/

void GSprite::SetAnimationIndex(int aIndex)
{
	myAnimationIndex = aIndex;
}

void GSprite::SetAnimationSpeed(float aSpeed)
{
	myAnimationSpeed = aSpeed;
}

#pragma endregion