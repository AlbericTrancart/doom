#include "headers/player.h"

//***CLASS PLAYER DEFINITIONS***//

//--------------------------------------------------------------------//

Player::Player(Map& map) //Constructeur
{
    pos.x=map.w/2;
    pos.y=map.h/2;
    yaw=0*3.1415/180;
    health=100;
    face=map.fac[what_face(map)];
}

//--------------------------------------------------------------------//


//--------------------------------------------------------------------//

void Player::test_and_move(Point nextpos, Map& map) //Teste si le déplacement est possible dans la map, et l'effectue si c'est le cas
{
    /*"Le point où le joueur est et celui où il s'apprête à aller sont-ils sur la même face?" equivalent à "Le point où le
    joueur est et celui où il s'apprête à aller sont-ils dans le même demi-plan défini par l'arête 1, 2 et 3 ?"*/

    bool test1=face.E1.sameSide(pos,nextpos);
    bool test2=face.E2.sameSide(pos,nextpos);
    bool test3=face.E3.sameSide(pos,nextpos);

    if(test1 && test2 && test3) //Si les trois sont vrais, le joueur ne s'apprête pas à quitter la face
        pos=nextpos; //Le joueur ne s'apprête pas à quitter la face, RAS, il avance

    //Si test1 est faux, le joueur s'apprête à traverser E1. si ce n'est pas un mur, il le fait
    //Si test2 est faux, le joueur s'apprête à traverser E2. si ce n'est pas un mur, il le fait
    //Si test3 est faux, le joueur s'apprête à traverser E3. si ce n'est pas un mur, il le fait
    //Il s'agit du même type de mouvement

    if((test1=false && face.E1.type==0) || (test2=false && face.E2.type==0) || (test3=false && face.E3.type==0)){
        pos=nextpos; //Le joueur s'apprête à traverser une arête qui n'est pas un mur, RAS, il avance
        face=map.fac[what_face(map)]; //On réactualise ici la face dans laquelle se trouve maintenant le joueur
    }
 //Cas où le joueur veut traverser une arête qui est un mur : il ne se passe rien
}



void Player::move_left(Map& map)
{
    Point nextpos; //Point position vers lequel le joueur s'apprête à aller
    nextpos.x=pos.x+PAS*sin(yaw);
    nextpos.y=pos.y-PAS*cos(yaw);

    test_and_move(nextpos,map);

    return;
}

void Player::move_right(Map& map)
{
    Point nextpos; //Point position vers lequel le joueur s'apprête à aller
    nextpos.x=pos.x-PAS*sin(yaw);
    nextpos.y=pos.y+PAS*cos(yaw);

    test_and_move(nextpos,map);

    return;
}

void Player::move_up(Map& map){

    Point nextpos; //Point position vers lequel le joueur s'apprête à aller
    nextpos.x=pos.x+PAS*cos(yaw);
    nextpos.y=pos.y+PAS*sin(yaw);

    test_and_move(nextpos, map);

    return;
}

void Player::move_down(Map& map)
{
    Point nextpos; //Point position vers lequel le joueur s'apprête à aller
    nextpos.x=pos.x-PAS*cos(yaw);
    nextpos.y=pos.y-PAS*sin(yaw);

    test_and_move(nextpos,map);

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

int Player::what_face(Map& map)
{
    for (int i=0; i<map.nbFace; ++i)
    {
        if(map.fac[i].isInFace(pos)){ //Si le joueur se trouve dans la ième face du tableau de fac de la map, on retourne l'indice
            return i;
        }
        cout << endl;
    }
    return -1;
}

//--------------------------------------------------------------------//
    