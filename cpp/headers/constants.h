#pragma once

#include <Imagine/Graphics.h>
using namespace Imagine;

#include <cmath>
//#define _USE_MATH_DEFINES


//Fenetre
const int W = 640;
const int H = 480;
const int A_MINIMAP = 20; //Dimensions de la minimap en %

//Mouvements
const float PAS = 0.3; //Pas de d?placement
const float THETA = 3.14/80; //Pas de rotation

//Graphismes
const float FOV = 45*3.1415/180; //Field of view ? 90
const float H_WALLS = 500; //Coefficient de hauteur des murs
const float INFINITE = 9000*42; //IT'S OVER 9000! /*Il suffit qu'INFINITE depasse la taille de la map*/
const float PAS_RAYCAST = 0.05;

const Color FLOOR_DEBUG(100, 100, 100);
const Color SKY_DEBUG(165, 200, 255);
const Color WALL_DEBUG(123, 60, 46);
const Color TRANSPARENT(0, 255, 255);



