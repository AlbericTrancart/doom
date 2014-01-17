#pragma once

#include "constants.h"
#include "utils.h"

class Player
{
public:

    Point pos;
    float yaw; //Angle que fait le joueur par rapport à l'axe des x
    int health;
    Face face;

	Player();

	void move_up(); //Décrémente la position dans le sens des y décroissants
	void move_down(); //Incrémente la position dans le sens des y croissants
	void move_left(); //Décrémente la position dans le sens des x décroissants
	void move_right(); //Incrémente la position dans le sens des x croissants

	void turn_left(); //Décrémente l'orientation d'un angle THETA
	void turn_right(); //Incrémente l'orientation d'un angle THETA
    
};