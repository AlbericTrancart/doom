#pragma once

#include "utils.h"
#include "hud.h"
#include "map.h"
#include "chicken.h"

void gGraphics(Image& img, Player& player, Map& map);
void gMinimap(Player& player, Map& map, Chicken chicken[]);