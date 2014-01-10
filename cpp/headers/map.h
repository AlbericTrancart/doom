#pragma once
#include "player.h"

struct Arrete {
    Point A, B;
};

struct Face {
    Point A, B, C;
};

class Map {
    Arrete* arr;
    Face* faces;
    
public:
    bool isInFace(Point p);
};

 //Dit si le point est dans la face (wesh si on s'est pris un pain dans la gueule)
float findWall(Player p); //Donne la distance au mur le plus proche