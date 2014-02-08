#pragma once

#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
using namespace std;

#include <Imagine/Graphics.h>
using namespace Imagine;

#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

//Fenetre
const int W = 640;
const int H = 480;
const int A_MINIMAP = 20; //Dimensions de la minimap en %

//Mouvements
const double PAS = 0.5; //Pas de deplacement
const double THETA = M_PI/80; //Pas de rotation

//Graphismes
const double FOV = 45*3.1415/180; //Field of view
const double H_WALLS = 500; //Coefficient de hauteur des murs
const double INFINITE = 9000*42; //IT'S OVER 9000! /*Il suffit qu'INFINITE depasse la taille de la map*/
const double PAS_RAYCAST = 0.05;

const int TEXTURE_HEIGHT = 490;
const int TEXTURE_WIDTH = 600;
const Color FLOOR_DEBUG(100, 100, 100);
const Color SKY_DEBUG(165, 200, 255);
const Color WALL_DEBUG(123, 60, 46);
const Color TRANSPARENT(0, 255, 255);