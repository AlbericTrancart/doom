#pragma once

#include <Imagine/Graphics.h>
using namespace Imagine;

#include <cmath>
//#define _USE_MATH_DEFINES


//Fenêtre
const int W = 1300;
const int H = 700;
const int A_MINIMAP = 20; //Dimensions de la minimap en %

//Mouvements
const int PAS = 1; //Pas de déplacement
const float THETA = 3.14/100; //Pas de rotation

//Graphismes
const float FOV = 90*3.1415/180; //Field of view à 90
const float H_WALLS = 5000; //Coefficient de hauteur des murs
const float INFINITE = 9000*42; //IT'S OVER 9000! /*Il suffit qu'INFINITE dépasse la taille de la map*/
const float PAS_RAYCAST = 0.1;

const Color FLOOR(100, 100, 100);
const Color SKY(165, 200, 255);
const Color WALL(123, 60, 46);
