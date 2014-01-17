#pragma once
#include "player.h"

//***Structure du fichier stockant la map***//
/*M Largeur hauteur nbpoints nbaretes nbfaces
Pour les points:
P id x y
Les aretes:
A id point1 point2 type face1 face2
Les types: 0 rien 1 mur -1 bord
Faces:
F id arete1 arete2 arete3
Il faut ABSOLUMENT garder la structure:
Infos générales en ligne 2 PUIS les points PUIS les aretes PUIS les faces*/

class Map {
    Point* pnt;
    Edge* edg;
    Face* fac;
    int nbPoint, nbEdge, nbFace;
    int w, h;
    
public:
    Map(string src);
    ~Map();
    float findWall(Player player, float angle); //Donne la distance au mur le plus proche
};