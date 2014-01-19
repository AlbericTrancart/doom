#pragma once
#include <Imagine/Graphics.h>
using namespace Imagine;

#include "constants.h"
#include "player.h"

//int input(); // ?
void handleEvent(int& endgame, Player& player, Map& map);
void event_move(Player& player, Map& map, bool key_z, bool key_q, bool key_d, bool key_s);
