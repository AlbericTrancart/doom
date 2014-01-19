#include "headers/hud.h"

Image Wc1("carbine/1.png"), Wc2("carbine/2.png"), Wc3("carbine/3.png"), Wc4("carbine/4.png"), Wc5("carbine/5.png"), Wc6("carbine/6.png");
Image Wf1("fists/1.png"), Wf2("fists/2.png"), Wf3("fists/3.png");
Image Wg1("gun/1.png"), Wg2("gun/2.png"), Wg3("gun/3.png"), Wg4("gun/4.png");
Image Wmg1("machinegun/1.png"), Wmg2("machinegun/2.png"), Wmg3("machinegun/3.png"), Wmg4("machinegun/4.png");
Image Wpg1("plasmagun/1.png"), Wpg2("plasmagun/2.png"), Wpg3("plasmagun/3.png"), Wpg4("plasmagun/4.png");
Image Wsg1("shotgun/1.png"), Wsg2("shotgun/2.png"), Wsg3("shotgun/3.png"), Wsg4("shotgun/4.png"), Wsg5("shotgun/5.png"), Wsg6("shotgun/6.png");

void weapon(Image& img, Player player){
 
    //Pour chaque arme on définit une table avec les différentes images
    if(player.weapon == 0){
        if(player.weapon_state == 0)
            img.addSprite(Wf1, W/2-300, H-150);
        else if(player.weapon_state > 0 && player.weapon_state < 5)
            img.addSprite(Wf2, W/2-300, H-150);
        else if(player.weapon_state >= 5 && player.weapon_state < 8)
            img.addSprite(Wf3, W/2-300, H-150);
    }
}

void hud(Image& img, Player player){
    weapon(img, player);
}