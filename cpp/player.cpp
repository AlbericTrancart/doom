#include "headers/player.h"

Player::Player(Map& map) //Constructeur
{
	pos = Point(2*map.w/3,map.h/2);
    yaw = -M_PI/2;
    health = 100;
    weapon = 1;
    weapon_state = 0;
    face = map.fac[whatFace(map)];
}

//Fonctions de mouvement
void Player::testAndMove(Point nextpos, Map& map) //Teste si le déplacement est possible dans la map, et l'effectue si c'est le cas
{
    //Le point est sorti de la map
    if(nextpos.x < 0 || nextpos.x > map.w || nextpos.y < 0 || nextpos.y > map.h) 
		return;

    //Si la distance au prochain point est plus petite que la distance au mur le plus proche
	if(map.findWall(*this, asin(((nextpos-pos).y/((nextpos-pos).norm())))) > (nextpos-pos).norm())
		pos=nextpos;
	else
        return;

	//On réactualise ici la face dans laquelle se trouve maintenant le joueur
	face=map.fac[whatFace(map)];
}

//Commandes utilisées par event.cpp
//a multiple du PAS avec lequel en bouge
void Player::moveLeft(Map& map, double a)
{
    Point nextpos(pos.x+a*PAS*sin(yaw), pos.y-a*PAS*cos(yaw));
    testAndMove(nextpos, map);
    return;
}

void Player::moveRight(Map& map, double a)
{
    Point nextpos(pos.x-a*PAS*sin(yaw), pos.y+a*PAS*cos(yaw));
    testAndMove(nextpos, map);
    return;
}

void Player::moveUp(Map& map, double a)
{
    Point nextpos(pos.x+a*PAS*cos(yaw), pos.y+a*PAS*sin(yaw)); //Point position vers lequel le joueur s'apprête à aller
    testAndMove(nextpos, map);
    return;
}

void Player::moveDown(Map& map, double a) //a multiple du PAS avec lequel en bouge
{
    Point nextpos(pos.x-a*PAS*cos(yaw), pos.y-a*PAS*sin(yaw));
    testAndMove(nextpos, map);
    return;
}

void Player::turnLeft(double a)
{
    yaw -= a*THETA;
    return;
}

void Player::turnRight(double a)
{
    yaw += a*THETA;
    return;
}

//Actualise la face dans laquelle est le joueur
int Player::whatFace(Map& map)
{
    for(int i = 0; i < map.nbFace; ++i){
        if(map.fac[i].isInFace(pos)) //Si le joueur se trouve dans la ième face du tableau de fac de la map, on retourne l'indice
            return i;
    }
    return -1;
}

//Déplacement du viseur à la souris
void Player::motion(double e0, double e1)
{
	if(e0-e1>0)
		turnLeft();

	if(e0-e1<0)
		turnRight();
}
