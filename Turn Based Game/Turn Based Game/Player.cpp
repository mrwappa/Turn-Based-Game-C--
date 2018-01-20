#include "stdafx.h"
#include "Player.h"



Player::Player(float aX, float aY) : Entity(myX,myY)
{
	myX = aX;
	myY = aY;
	mySprite.SetTexture("Sprites/spr_link_sheet.png",9);
	myAnimationSpeed = 0.3f;
	myXScale = 2;
	myYScale = myXScale;
}

Player::~Player()
{

}
void Player::Update()
{
	if (KeyboardCheck(sf::Keyboard::A))
	{
		myX -= 4;
	}
	if (KeyboardCheck(sf::Keyboard::W))
	{
		myY -= 4;
	}
	if (KeyboardCheck(sf::Keyboard::D))
	{
		myX += 4;
	}
	if (KeyboardCheck(sf::Keyboard::S))
	{
		myY += 4;
	}
	if (KeyboardCheck(sf::Keyboard::Tab))
	{
		DestroyInstance(this);
	}
	if (KeyboardCheckPressed(sf::Keyboard::Right))
	{
		myX += 20;
	}
	if (MouseCheckPressed(sf::Mouse::Right))
	{
		myX = GameMouseX();
		myY = GameMouseY();
	}
	if (KeyboardCheckPressed(sf::Keyboard::Up))
	{
		myDepth += 1;
	}
	if (KeyboardCheckPressed(sf::Keyboard::Down))
	{
		myDepth -= 1;
	}
	
}


void Player::Draw()
{
	Entity::Draw();
	Pixel.Draw(myX, myY, 10, 2, 20, 1,myAlpha, sf::Color::White,0);
	DrawLine(myX, myY, myX, myY + 50, 0, sf::Color::White, 1);
	
	
}

