#include "headers/graphics.h" 

void raycast(Image& img, Player player, Map& map){ //Remplit l'image avec le sol et les murs
    float angle;
    int height; //Hauteur du mur
    for(int j = 0; j < W; j++){ //On parcoure les colonnes de pixel
        angle = j*FOV/W-player.yaw/2;
        height = int(H_WALLS/map.findWall(player, angle));
        
        for(int i = 0; i < H/2-height/2; i++)
            img.set(i, j, SKY);
        for(int i = H/2-height/2; i < H/2+height/2; i++)
            img.set(i, j, WALL);
        for(int i = H/2+height/2; i < H; i++)
            img.set(i, j, FLOOR);
    }
}

void minimap(Image& img, Player player, Map& map){
    int w = W*W_MINIMAP/100;
    int h = W*W_MINIMAP/100;
    
    for(int i = 0; i < w; i++)
        for(int j = 0; j < h; j++)
            img.set(i, j, WHITE);
}

void graphics(Image& img, Player player, Map& map){
    raycast(img, player, map);
    minimap(img, player, map);
}