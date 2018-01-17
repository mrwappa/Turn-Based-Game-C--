#include "stdafx.h"
#include "Player.h"



Player::Player(float aX, float aY) : Entity(myX,myY)
{
	myX = aX;
	myY = aY;
	mySprite.SetTexture("Sprites/spr_link_sheet.png",9);
	myAnimationSpeed = 0.5f;
	myXScale = 4;
	myYScale = 4;
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
	
}


void Player::Draw()
{
	myAngle += 1;
	Entity::Draw();
}

