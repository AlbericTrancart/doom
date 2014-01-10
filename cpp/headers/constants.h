#pragma once

#include <Imagine/Graphics.h>
using namespace Imagine;
#include <cmath>
#define _USE_MATH_DEFINES

const int W = 512;
const int H = 512;
const int PAS = 1; //Pas de déplacement
const float THETA = M_PI/10; //Pas de rotation

const float FOV = 90; //Field of view à 90
const float H_WALLS = 500; //Coefficient de hauteur des murs

const Color FLOOR(100, 100, 100);
const Color SKY(165, 200, 255);
const Color WALL(123, 60, 46);