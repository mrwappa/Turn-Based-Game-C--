#ifndef GSPRITE_H
#define GSPRITE_H

#include "SFML\Graphics.hpp"
#include "Camera.h"
#include "GrowingArray.h"


class GSprite
{
public:
	GSprite();
	~GSprite();

	static sf::Shader* DepthShader;
	static sf::RenderWindow* Window;

	void Draw(float aX, float aY, float aXScale, float aYScale, float aAngle, float aDepth , float aAlpha, sf::Color aColor, float aAnimationSpeed);
	void Draw(float aX, float aY, float aXScale, float aYScale, sf::Vector2f aOrigin, float aAngle, float aDepth, float aAlpha, sf::Color aColor, float aAnimationSpeed);
	//Acessors
	#pragma region
	float GetDepth();
	sf::Sprite GetSprite();
	sf::Texture GetTexture();
	#pragma endregion

	//Modifiers
	#pragma region
	void SetTexture(std::string aFileName, int aNrOfFrames);
	void SetTexture(sf::Texture aTexture,  int aNrOfFrames);
	void SetSprite(sf::Sprite aSprite);
	void SetDepth(float aDepth);
	void SetNrOfFrames(int aNrOfFrames);
	void SetAnimationIndex(int aIndex);
	void SetAnimationSpeed(float aSpeed);
	#pragma endregion

	static GrowingArray<GSprite> SpriteList;

private:
	sf::Texture myTexture;
	sf::Sprite mySprite;

	float myDepth;
	float myWidth;
	float myHeight;
	float myTextureWidth;
	float myTextureHeight;
	
	float myNrOfFrames;
	float myAnimationIndex;
	float myAnimationSpeed;
	float myAnimationCounter;
};
#endif // !GSPRITE_H