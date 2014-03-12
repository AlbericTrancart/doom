#include "headers/utils.h"
#include "headers/player.h"
#include "headers/events.h"
#include "headers/graphics.h"
#include "headers/sound.h"
#include "headers/chicken.h"

int main(){
    sInitAudio();
    openWindow(W, H, "The Quake is a lie");

    int endgame = 0; //Entier pour: 0 continue 1 fin du jeu 2 alt pressé 3 F4 pressé
    Image ecran;
    Map map("test"); 
	Player player(map);
    Chicken* chicken = new Chicken[NB_CHICKEN];
    cInitChicken(chicken, map);
    
    while(endgame != 1){
        eHandle(endgame, player, map);
        eWeapons(player);
        gGraphics(ecran, player, map);
        
        noRefreshBegin();
        ecran.display();
        gMinimap(player, map, chicken); //À n'utiliser qu'à des fins de debug
        noRefreshEnd();
        
        milliSleep(30);
    }
    delete [] chicken;
    sEndAudio();

    return 0;
}
