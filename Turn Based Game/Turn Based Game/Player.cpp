#include "stdafx.h"
#include "Player.h"

Player::Player(float aX,float aY) : Entity("Player")
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
	myAngle += 2;
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
		//DestroyInstance(this);
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
	if (KeyboardCheck(sf::Keyboard::Up))
	{
		myAngle += 4;
	}
	if (KeyboardCheck(sf::Keyboard::Down))
	{
		myAngle -= 4;
	}
	
}


void Player::Draw()
{

	Entity::Draw();
	//DrawLine(myX +50, myY, myX, myY + 200, 0, sf::Color::White, 1);
	
	
}

