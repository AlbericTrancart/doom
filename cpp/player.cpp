#include "headers/player.h"

//***CLASS PLAYER DEFINITIONS***//

//--------------------------------------------------------------------//

Player::Player(Map& map) //Constructeur
{
	pos.x=map.w/2;
	pos.y=map.h/2;
	yaw=0;
	health=100;
	face=map.fac[what_face(map)];
}

//--------------------------------------------------------------------//


//--------------------------------------------------------------------//

void Player::move_up(Map& map) //Pas sûr que ma méthode de test soit optimisée, mais elle devrait fonctionner comme ça
{
	Point nextpos; //Point position vers lequel le joueur s'apprête à aller
	nextpos.x=pos.x+PAS*sin(yaw);
	nextpos.y=pos.y-PAS*cos(yaw);

	/*"Le point où le joueur est et celui où il s'apprête à aller sont-ils sur la même face?" equivalent à "Le point où le
	joueur est et celui où il s'apprête à aller sont-ils dans le même demi-plan défini par l'arête 1, 2 et 3 ?"*/

	bool test1=face.E1.sameSide(pos,nextpos);
	bool test2=face.E2.sameSide(pos,nextpos);
	bool test3=face.E3.sameSide(pos,nextpos);

	if (test1 && test2 && test3) //Si les trois sont vrais, le joueur ne s'apprête pas à quitter la face
	{
	pos.x=pos.x+PAS*sin(yaw);
	pos.y=pos.y-PAS*cos(yaw);
	}
	if (test1=false && face.E1.type==0) //Si test1 est faux, le joueur s'apprête à traverser E1
										//si ce n'est pas un mur, il le fait
	{
	pos.x=pos.x+PAS*sin(yaw);
	pos.y=pos.y-PAS*cos(yaw);
	face=map.fac[what_face(map)]; //Et on réactualise la face dans laquelle se trouve le joueur
	}
	if (test2=false && face.E2.type==0) //Idem pour test2
	{
	pos.x=pos.x+PAS*sin(yaw);
	pos.y=pos.y-PAS*cos(yaw);
	face=map.fac[what_face(map)];
	}
	if (test3=false && face.E3.type==0) //Idem pour test3
	{
	pos.x=pos.x+PAS*sin(yaw);
	pos.y=pos.y-PAS*cos(yaw);
	face=map.fac[what_face(map)];
	}
	else //Cas où le joueur veut traverser une arête qui est un mur : il ne se passe rien
	{
	}

	return;
}

void Player::move_down(Map& map) //Pas sûr que ma méthode de test soit optimisée, mais elle devrait fonctionner comme ça
{
	Point nextpos; //Point position vers lequel le joueur s'apprête à aller
	nextpos.x=pos.x-PAS*sin(yaw);
	nextpos.y=pos.y+PAS*cos(yaw);

	/*"Le point où le joueur est et celui où il s'apprête à aller sont-ils sur la même face?" equivalent à "Le point où le
	joueur est et celui où il s'apprête à aller sont-ils dans le même demi-plan défini par l'arête 1, 2 et 3 ?"*/

	bool test1=face.E1.sameSide(pos,nextpos);
	bool test2=face.E2.sameSide(pos,nextpos);
	bool test3=face.E3.sameSide(pos,nextpos);

	if (test1 && test2 && test3) //Si les trois sont vrais, le joueur ne s'apprête pas à quitter la face
	{
	pos.x=pos.x-PAS*sin(yaw);
	pos.y=pos.y+PAS*cos(yaw);
	}
	if (test1=false && face.E1.type==0) //Si test1 est faux, le joueur s'apprête à traverser E1
										//si ce n'est pas un mur, il le fait
	{
	pos.x=pos.x-PAS*sin(yaw);
	pos.y=pos.y+PAS*cos(yaw);
	face=map.fac[what_face(map)]; //Et on réactualise la face dans laquelle se trouve le joueur
	}
	if (test2=false && face.E2.type==0) //Idem pour test2
	{
	pos.x=pos.x-PAS*sin(yaw);
	pos.y=pos.y+PAS*cos(yaw);
	face=map.fac[what_face(map)];
	}
	if (test3=false && face.E3.type==0) //Idem pour test3
	{
	pos.x=pos.x-PAS*sin(yaw);
	pos.y=pos.y+PAS*cos(yaw);
	face=map.fac[what_face(map)];
	}
	else //Cas où le joueur veut traverser une arête qui est un mur : il ne se passe rien
	{
	}

	return;
}

void Player::move_right(Map& map) //Pas sûr que ma méthode de test soit optimisée, mais elle devrait fonctionner comme ça
{
	Point nextpos; //Point position vers lequel le joueur s'apprête à aller
	nextpos.x=pos.x+PAS*cos(yaw);
	nextpos.y=pos.y+PAS*sin(yaw);

	/*"Le point où le joueur est et celui où il s'apprête à aller sont-ils sur la même face?" equivalent à "Le point où le
	joueur est et celui où il s'apprête à aller sont-ils dans le même demi-plan défini par l'arête 1, 2 et 3 ?"*/

	bool test1=face.E1.sameSide(pos,nextpos);
	bool test2=face.E2.sameSide(pos,nextpos);
	bool test3=face.E3.sameSide(pos,nextpos);

	if (test1 && test2 && test3) //Si les trois sont vrais, le joueur ne s'apprête pas à quitter la face
	{
	pos.x=pos.x+PAS*cos(yaw);
	pos.y=pos.y+PAS*sin(yaw);
	}
	if (test1=false && face.E1.type==0) //Si test1 est faux, le joueur s'apprête à traverser E1
										//si ce n'est pas un mur, il le fait
	{
	pos.x=pos.x+PAS*cos(yaw);
	pos.y=pos.y+PAS*sin(yaw);
	face=map.fac[what_face(map)]; //Et on réactualise la face dans laquelle se trouve le joueur
	}
	if (test2=false && face.E2.type==0) //Idem pour test2
	{
	pos.x=pos.x+PAS*cos(yaw);
	pos.y=pos.y+PAS*sin(yaw);
	face=map.fac[what_face(map)];
	}
	if (test3=false && face.E3.type==0) //Idem pour test3
	{
	pos.x=pos.x+PAS*cos(yaw);
	pos.y=pos.y+PAS*sin(yaw);
	face=map.fac[what_face(map)];
	}
	else //Cas où le joueur veut traverser une arête qui est un mur : il ne se passe rien
	{
	}

	return;
}

void Player::move_left(Map& map) //Pas sûr que ma méthode de test soit optimisée, mais elle devrait fonctionner comme ça
{
	Point nextpos; //Point position vers lequel le joueur s'apprête à aller
	nextpos.x=pos.x-PAS*cos(yaw);
	nextpos.y=pos.y-PAS*sin(yaw);

	/*"Le point où le joueur est et celui où il s'apprête à aller sont-ils sur la même face?" equivalent à "Le point où le
	joueur est et celui où il s'apprête à aller sont-ils dans le même demi-plan défini par l'arête 1, 2 et 3 ?"*/

	bool test1=face.E1.sameSide(pos,nextpos);
	bool test2=face.E2.sameSide(pos,nextpos);
	bool test3=face.E3.sameSide(pos,nextpos);

	if (test1 && test2 && test3) //Si les trois sont vrais, le joueur ne s'apprête pas à quitter la face
	{
	pos.x=pos.x-PAS*cos(yaw);
	pos.y=pos.y-PAS*sin(yaw);
	}
	if (test1=false && face.E1.type==0) //Si test1 est faux, le joueur s'apprête à traverser E1
										//si ce n'est pas un mur, il le fait
	{
	pos.x=pos.x-PAS*cos(yaw);
	pos.y=pos.y-PAS*sin(yaw);
	face=map.fac[what_face(map)]; //Et on réactualise la face dans laquelle se trouve le joueur
	}
	if (test2=false && face.E2.type==0) //Idem pour test2
	{
	pos.x=pos.x-PAS*cos(yaw);
	pos.y=pos.y-PAS*sin(yaw);
	face=map.fac[what_face(map)];
	}
	if (test3=false && face.E3.type==0) //Idem pour test3
	{
	pos.x=pos.x-PAS*cos(yaw);
	pos.y=pos.y-PAS*sin(yaw);
	face=map.fac[what_face(map)];
	}
	else //Cas où le joueur veut traverser une arête qui est un mur : il ne se passe rien
	{
	}

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

int Player::what_face(Map map)
{
	for (int i=0; i<map.nbFace; ++i)
		{
			if(map.fac[i].isInFace(pos)) //Si le joueur se trouve dans la ième face du tableau de fac de la map, on retourne l'indice
				return i;
		}
}

//--------------------------------------------------------------------//
	
