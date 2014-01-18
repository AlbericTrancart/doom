#include "headers/graphics.h" 

void raycast(Image& img, Player player, Map& map){ //Remplit l'image avec le sol et les murs
    float angle;
    int height; //Hauteur du mur
    for(int j = 0; j <= W; j++){ //On parcoure les colonnes de pixel
        angle = player.yaw+FOV*j/W-FOV/2;
        height = int(H_WALLS/map.findWall(player, angle));
        
        for(int i = 0; i < H/2-height/2; i++)
            img.set(i, j, SKY);
        for(int i = H/2-height/2; i < H/2+height/2; i++)
            img.set(i, j, WALL);
        for(int i = H/2+height/2; i < H; i++)
            img.set(i, j, FLOOR);
    }
}

void minimap(Player player, Map& map){

	int w=W*A_MINIMAP/100;
	int h=W*A_MINIMAP/100;
    
    fillRect(0, 0, w, h, WHITE);
	drawLine(0, h, w, h, BLACK, 4);
    drawLine(w, 0, w, h, BLACK, 4);
    fillCircle(player.pos.x*w/map.w, player.pos.y*h/map.h, 3, BLUE);
    drawLine(player.pos.x*w/map.w, player.pos.y*h/map.h, player.pos.x*w/map.w+int(INFINITE*cos(player.yaw)), player.pos.y*h/map.h+int(INFINITE*sin(player.yaw)), GREEN, 2);
    for(int i = 0; i < map.nbEdge; ++i){
        if(map.edg[i].type == 1)
            drawLine(map.edg[i].A.x*w/map.w, map.edg[i].A.y*h/map.h, map.edg[i].B.x*w/map.w, map.edg[i].B.y*h/map.h, RED, 2);
        else
            drawLine(map.edg[i].A.x*w/map.w, map.edg[i].A.y*h/map.h, map.edg[i].B.x*w/map.w, map.edg[i].B.y*h/map.h, BLACK, 1);
    }
                
}

void graphics(Image& img, Player player, Map& map){
    raycast(img, player, map);
}
