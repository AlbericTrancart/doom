#include "headers/hud.h"

Image Wc1("carbine/1.png"), Wc2("carbine/2.png"), Wc3("carbine/3.png"), Wc4("carbine/4.png"), Wc5("carbine/5.png"), Wc6("carbine/6.png");
Image Wf1("fists/1.png"), Wf2("fists/2.png"), Wf3("fists/3.png");
Image Wg1("gun/1.png"), Wg2("gun/2.png"), Wg3("gun/3.png"), Wg4("gun/4.png");
Image Wmg1("machinegun/1.png"), Wmg2("machinegun/2.png"), Wmg3("machinegun/3.png"), Wmg4("machinegun/4.png");
Image Wpg1("plasmagun/1.png"), Wpg2("plasmagun/2.png"), Wpg3("plasmagun/3.png"), Wpg4("plasmagun/4.png");
Image Wsg1("shotgun/1.png"), Wsg2("shotgun/2.png"), Wsg3("shotgun/3.png"), Wsg4("shotgun/4.png"), Wsg5("shotgun/5.png"), Wsg6("shotgun/6.png");

void weapon(Image& img, Player player){
 
    //Pour chaque arme on définit une table avec les différentes images
    if(player.weapon == 1){ //Poings
        if(player.weapon_state == 0)
            img.addSprite(Wf1, W/2-300, H-150);
        else if(player.weapon_state > 0 && player.weapon_state < 3)
            img.addSprite(Wf2, W/2-300, H-150);
        else if(player.weapon_state >= 3 && player.weapon_state < 5)
            img.addSprite(Wf3, W/2-300, H-150);
    }
    if(player.weapon == 2){ //Gun
        if(player.weapon_state == 0)
            img.addSprite(Wg1, W/2-300, H-150);
        else if(player.weapon_state > 0 && player.weapon_state < 3)
            img.addSprite(Wg2, W/2-300, H-150);
        else if(player.weapon_state >= 3 && player.weapon_state < 4)
            img.addSprite(Wg3, W/2-300, H-150);
        else if(player.weapon_state >= 4 && player.weapon_state < 5)
            img.addSprite(Wg4, W/2-300, H-150);
    }
    if(player.weapon == 3){ //Shotgun
        if(player.weapon_state == 0)
            img.addSprite(Wsg1, W/2-300, H-150);
        else if(player.weapon_state > 0 && player.weapon_state < 2)
            img.addSprite(Wsg2, W/2-300, H-150);
        else if(player.weapon_state >= 2 && player.weapon_state < 4)
            img.addSprite(Wsg3, W/2-300, H-150);
        else if(player.weapon_state >= 4 && player.weapon_state < 5){
            img.addSprite(Wsg4, W/2-300, H-150);
            sWeapon(7);
        }
        else if(player.weapon_state >= 5 && player.weapon_state < 8)
            img.addSprite(Wsg5, W/2-300, H-150);
        else if(player.weapon_state >= 8 && player.weapon_state < 11)
            img.addSprite(Wsg6, W/2-300, H-150);
    }
    if(player.weapon == 4){ //Carbine
        if(player.weapon_state == 0)
            img.addSprite(Wc1, W/2-300, H-150);
        else if(player.weapon_state > 0 && player.weapon_state < 2)
            img.addSprite(Wc2, W/2-300, H-150);
        else if(player.weapon_state >= 2 && player.weapon_state < 4)
            img.addSprite(Wc3, W/2-300, H-150);
        else if(player.weapon_state >= 4 && player.weapon_state < 8)
            img.addSprite(Wc4, W/2-300, H-150);
        else if(player.weapon_state >= 8 && player.weapon_state < 11)
            img.addSprite(Wc5, W/2-300, H-150);
        else if(player.weapon_state >= 11 && player.weapon_state < 13)
            img.addSprite(Wc6, W/2-300, H-150);
    }
    if(player.weapon == 5){ //Machine gun
        if(player.weapon_state < 10)
            img.addSprite(Wmg1, W/2-300, H-150);
        else if(player.weapon_state >= 10 && player.weapon_state < 11){
            img.addSprite(Wmg2, W/2-300, H-150);
            sWeapon(5); //La gestion du son doit se faire en continu
        }
        else if(player.weapon_state >= 11 && player.weapon_state < 12){
            img.addSprite(Wmg3, W/2-300, H-150);
            sWeapon(5);
        }
        else if(player.weapon_state >= 12 && player.weapon_state < 13){
            img.addSprite(Wmg4, W/2-300, H-150);
            sWeapon(5);
        }
    }
    if(player.weapon == 6){ //Plasma gun
        if(player.weapon_state == 0)
            img.addSprite(Wpg1, W/2-300, H-150);
        else if(player.weapon_state > 0 && player.weapon_state < 4)
            img.addSprite(Wpg2, W/2-300, H-150);
        else if(player.weapon_state >= 4 && player.weapon_state < 7)
            img.addSprite(Wpg3, W/2-300, H-150);
        else if(player.weapon_state >= 7 && player.weapon_state < 10)
            img.addSprite(Wpg4, W/2-300, H-150);
    }
}

Image cursorimg("cursor/cursor.png");
void cursor(Image& img, Player& player){
    img.addSprite(cursorimg, W/2-cursorimg.w/2, H/2-cursorimg.h/2+30);
}

void hHud(Image& img, Player player){
    weapon(img, player);
    cursor(img,player);
}