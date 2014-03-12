#pragma once

#include "utils.h"
#include "map.h"

#include <cmath>

class Map;

class Player
{
    void testAndMove(Point nextpos, Map& map);
    
public:
    Point pos;
    double yaw; //Angle que fait le joueur par rapport à l'axe des x
    int health;
    int weapon, weapon_state; //Quelle arme le joueur utilise et l'avancement du tir
    Face face;

	Player(Map& map);

    //Fonctions de mouvement
    void moveUp(Map& map, double a = 1);
    void moveDown(Map& map, double a = 1);
    void moveLeft(Map& map, double a = 1);
    void moveRight(Map& map, double a = 1);

    void turnLeft(double a=1);
    void turnRight(double a=1);

    //Gestion de la visée au curseur
	void motion(double e0, double e1);

    //Actualise le numéro de la face dans laquelle se trouve le joueur
    int whatFace(Map& map);
};
