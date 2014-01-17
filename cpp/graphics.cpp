#include "headers/graphics.h" 

<<<<<<< HEAD
void raycast(Image& img, Player player, Map& map){ //Remplit l'image avec le sol et les murs
    float angle;
    int height; //Hauteur du mur
    for(int j = 0; j < W; j++){ //On parcoure les colonnes de pixel
        angle = j*FOV/W-player.yaw/2;
        height = int(H_WALLS/map.findWall(player, angle));
=======
void raycast(Image& img, Player player){ //Remplit l'image avec le sol et les murs
    int height; //Hauteur du mur
    for(int j = 0; j < W; j++){ //On parcoure les colonnes de pixel
        height = int(H_WALLS/findWall(player));
>>>>>>> 5b2f1a49c4c0fa7e550814b3a07524a8fa8fe7ef
        
        for(int i = 0; i < H/2-height/2; i++)
            img.set(i, j, SKY);
        for(int i = H/2-height/2; i < H/2+height/2; i++)
            img.set(i, j, WALL);
        for(int i = H/2+height/2; i < H; i++)
            img.set(i, j, FLOOR);
    }
}

<<<<<<< HEAD
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
=======
void graphics(Image& img, Player player){
    raycast(img, player);
>>>>>>> 5b2f1a49c4c0fa7e550814b3a07524a8fa8fe7ef
}