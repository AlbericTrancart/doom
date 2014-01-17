<<<<<<< HEAD
#include "headers/player.h"

//***CLASS PLAYER DEFINITIONS***//

//--------------------------------------------------------------------//
Player::Player() //constructeur vide
{
	pos.x=0;
	pos.y=0;
	yaw=0;
	health=100;
}
//--------------------------------------------------------------------//


//--------------------------------------------------------------------//
void Player::move_up()
{
	pos.x=pos.x+PAS*sin(yaw);
	pos.y=pos.y-PAS*cos(yaw);
	return;
}

void Player::move_down()
{
	pos.x=pos.x-PAS*sin(yaw);
	pos.y=pos.y+PAS*cos(yaw);
	return;
}

void Player::move_right()
{
	pos.x=pos.x+PAS*cos(yaw);
	pos.y=pos.y+PAS*sin(yaw);
	return;
}

void Player::move_left()
{
	pos.x=pos.x-PAS*cos(yaw);
	pos.y=pos.y-PAS*sin(yaw);
	return;
}
//--------------------------------------------------------------------//


//--------------------------------------------------------------------//
void Player::turn_left()
{
	yaw=yaw-THETA;
	return;
}

void Player::turn_right()
{
	yaw=yaw+THETA;
	return;
}
//--------------------------------------------------------------------//
=======
#include "headers/player.h"

//***CLASS PLAYER DEFINITIONS***//

//--------------------------------------------------------------------//
Player::Player() //constructeur vide
{
	pos.x=0;
	pos.y=0;
	yaw=0;
	health=100;
}
//--------------------------------------------------------------------//


//--------------------------------------------------------------------//
void Player::move_up()
{
	pos.x=pos.x+PAS*sin(yaw);
	pos.y=pos.y-PAS*cos(yaw);
	return;
}

void Player::move_down()
{
	pos.x=pos.x-PAS*sin(yaw);
	pos.y=pos.y+PAS*cos(yaw);
	return;
}

void Player::move_right()
{
	pos.x=pos.x+PAS*cos(yaw);
	pos.y=pos.y+PAS*sin(yaw);
	return;
}

void Player::move_left()
{
	pos.x=pos.x-PAS*cos(yaw);
	pos.y=pos.y-PAS*sin(yaw);
	return;
}
//--------------------------------------------------------------------//


//--------------------------------------------------------------------//
void Player::turn_left()
{
	yaw=yaw-THETA;
	return;
}

void Player::turn_right()
{
	yaw=yaw+THETA;
	return;
}
//--------------------------------------------------------------------//
>>>>>>> 5b2f1a49c4c0fa7e550814b3a07524a8fa8fe7ef
	