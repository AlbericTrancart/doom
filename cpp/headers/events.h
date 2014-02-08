#pragma once

#include <Imagine/Graphics.h>
using namespace Imagine;

#include "constants.h"
#include "player.h"
#include "sound.h"

void eWeapons(Player& player);
void handleEvent(int& endgame, Player& player, Map& map);