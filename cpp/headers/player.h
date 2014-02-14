#pragma once

#include "utils.h"
#include "map.h"

class Map;

class Player
{
public:
    Point pos;
    double yaw; //Angle que fait le joueur par rapport à l'axe des x
    int health;
    int weapon, weapon_state; //Quelle arme le joueur utilise et l'avancement du tir
    Face face;

    Player(Map& map); //Construit le joueur dans la map indiquée

    void test_and_move(Point nextpos, Map& map); //Teste si le déplacement est possible dans la map, et l'effectue si c'est le cas (si pas d'argument, a=1)
    void move_up(Map& map, double a=1); //Décrémente la position dans le sens des y décroissants dans la map de a*PAS (si pas d'argument, a=1)
    void move_down(Map& map, double a=1); //Incrémente la position dans le sens des y croissants de a*PAS (si pas d'argument, a=1)
    void move_left(Map& map, double a=1); //Décrémente la position dans le sens des x décroissants de a*PAS (si pas d'argument, a=1)
    void move_right(Map& map, double a=1); //Incrémente la position dans le sens des x croissants de a*PAS (si pas d'argument, a=1)

    void turn_left(double a=1); //Décrémente l'orientation d'un angle a*THETA (si pas d'argument, a=1)
    void turn_right(double a=1); //Incrémente l'orientation d'un angle a*THETA (si pas d'argument, a=1)

	void motion(double e0, double e1);

    int what_face(Map& map); //Retourne le numéro de la face dans laquelle se trouve le joueur
};
