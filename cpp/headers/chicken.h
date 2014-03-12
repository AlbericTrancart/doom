#pragma once

#include "utils.h"
#include "map.h"

class Map;

class Chicken {
public:
    Point pos;
    int health;
};

void cInitChicken(Chicken chicken[], Map& map);
void chicken_display(Chicken chicken[], Image& img, Player& player, Map& map);
void cAI(Chicken chicken[]); //Gère l'AI des poulets