#pragma once

#include "utils.h"
#include "map.h"

class Map;

class Player
{
public:
    Point pos;
    float yaw; //Angle que fait le joueur par rapport à l'axe des x
    int health;
    Face face;

	Player(Map& map); //Construit le joueur dans la map indiquée

	void move_up(Map& map); //Décrémente la position dans le sens des y décroissants dans la map
	void move_down(Map& map); //Incrémente la position dans le sens des y croissants
	void move_left(Map& map); //Décrémente la position dans le sens des x décroissants
	void move_right(Map& map); //Incrémente la position dans le sens des x croissants

	void turn_left(); //Décrémente l'orientation d'un angle THETA
	void turn_right(); //Incrémente l'orientation d'un angle THETA

    	int what_face(Map map); //Retourne le numéro de la face dans laquelle se trouve le joueur
};

