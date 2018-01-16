#include "stdafx.h"
#include "Player.h"



Player::Player(float aX, float aY) : Entity(myX,myY)
{
	myX = aX;
	myY = aY;
	mySprite.SetTexture("Sprites/spr_link_sheet.png",9);
	myAnimationSpeed = 0.5f;
}

Player::~Player()
{

}

void Player::Draw()
{
	myAngle += 1;
	Entity::Draw();
}
