#include "headers/constants.h"

#include <iostream>
#include <cmath>
using namespace std;

#include "headers/player.h"
#include "headers/events.h"
#include "headers/graphics.h"

int main(){
    openWindow(W, H, "The Quake is a lie");
    int endgame = 0; //Entier pour: 0 continue 1 fin du jeu 2 alt pressé 3 f4 pressé
    Image ecran;
    Map map("test"); 
	Player player(map);

    while(endgame != 1){
        handleEvent(endgame, player, map);
        graphics(ecran, player, map);
        
        noRefreshBegin();
        ecran.display();
        minimap(player, map); //A n'utiliser qu'à des fins de debug
        noRefreshEnd();
        
        milliSleep(30);
    }
    
    return 0;
}
