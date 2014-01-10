#include "headers/graphics.h" 

void raycast(Image& img, Player player){ //Remplit l'image avec le sol et les murs
    int height; //Hauteur du mur
    for(int j = 0; j < W; j++){ //On parcoure les colonnes de pixel
        height = int(H_WALLS/findWall(player));
        
        for(int i = 0; i < H/2-height/2; i++)
            img.set(i, j, SKY);
        for(int i = H/2-height/2; i < H/2+height/2; i++)
            img.set(i, j, WALL);
        for(int i = H/2+height/2; i < H; i++)
            img.set(i, j, FLOOR);
    }
}

void graphics(Image& img, Player player){
    raycast(img, player);
}