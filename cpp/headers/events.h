#pragma once
#include <Imagine/Graphics.h>
using namespace Imagine;

#include "constants.h"
#include "player.h"

int input();
void handleEvent(int& endgame, Player& player);