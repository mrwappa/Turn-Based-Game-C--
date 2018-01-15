#ifndef GSPRITE_H
#define GSPRITE_H

#include "SFML\Graphics.hpp"

class GSprite
{
public:
	GSprite();
	~GSprite();

	//Acessors
	#pragma region
	
	#pragma endregion

	//Modifiers
	#pragma region
	void SetTexture(sf::Texture aTexture);
	void SetSprite(sf::Sprite aSprite);
	void SetX(float aX);
	void SetY(float aY);
	void SetXScale(float aXScale);
	void SetYScale(float aYScale);
	void SetNrOfFrames(int aNrOfFrames);
	void SetAnimationIndex(int aIndex);
	void SetAnimationSpeed(float aSpeed);
	#pragma endregion

private:
	sf::Texture myTexture;
	sf::Sprite mySprite;
	
	sf::Color myColor;
	sf::Vector2i myOrigin;

	float myX;
	float myY;
	
	float myXScale;
	float myYScale;
	float myWidth;
	float myHeight;
	float myTextureWidth;
	float myTextureHeight;
	
	float myNrOfFrames;
	float myAnimationIndex;
	float myAnimationCounter;
	float myAnimationSpeed;
	
};
#endif // !GSPRITE_H