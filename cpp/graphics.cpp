#include "headers/graphics.h"

Image FLOOR("floor.jpg");
Image SKY("sky.jpg");
Image WALL("wall.jpg");

void raycast(Image& img, Player player, Map& map){ //Remplit l'image avec le sol et les murs
    double angle;
    double height; //Hauteur du mur

    for(int j = 0; j < W; ++j){ //On parcoure les colonnes de pixel
        
		angle = player.yaw+FOV*j/W-FOV/2;
        double dist = map.findWall(player, angle);
        assert(dist != 0);
        height = H_WALLS/dist;
        
        for(int i = 0; i < max(0, int(H/2-height/2)); ++i)
            img.set(i, j, SKY.get(i%SKY.h,j%SKY.w));

        for(int i = max(0, int(H/2-height/2)); i < min(int(H/2+height/2), H); ++i)
		{
			Color wall_part_ij=WALL.get(int(i*TEXTURE_HEIGHT/height+WALL.h/2-TEXTURE_HEIGHT/2+(height/2-H/2)*TEXTURE_HEIGHT/height)%WALL.h,int(j*TEXTURE_WIDTH/height+WALL.w/2-TEXTURE_WIDTH/2+(height/2-W/2)*TEXTURE_WIDTH/height)%WALL.w);
			img.set(i, j, wall_part_ij);
		}

        for(int i = min(int(H/2+height/2), H); i < H; ++i)
            img.set(i, j, FLOOR.get(i%FLOOR.h,j%FLOOR.w));
    }
}

void minimap(Player player, Map& map){

	int w=W*A_MINIMAP/100;
	int h=W*A_MINIMAP/100;
    
    fillRect(0, 0, w, h, FLOOR_DEBUG);
    fillCircle(int(player.pos.x*w/map.w), int(player.pos.y*h/map.h), 3, SKY_DEBUG);
    drawLine(int(player.pos.x*w/map.w), int(player.pos.y*h/map.h), int(player.pos.x*w/map.w+int(INFINITE*cos(player.yaw))), int(player.pos.y*h/map.h+int(INFINITE*sin(player.yaw))), BLACK, 2);
    drawLine(int(player.pos.x*w/map.w), int(player.pos.y*h/map.h), int(player.pos.x*w/map.w+int(INFINITE*cos(player.yaw-FOV/2))), int(player.pos.y*h/map.h+int(INFINITE*sin(player.yaw-FOV/2))), BLACK, 2);
    drawLine(int(player.pos.x*w/map.w), int(player.pos.y*h/map.h), int(player.pos.x*w/map.w+int(INFINITE*cos(player.yaw+FOV/2))), int(player.pos.y*h/map.h+int(INFINITE*sin(player.yaw+FOV/2))), BLACK, 2);
    
    for(int i = 0; i < map.nbEdge; ++i){
        if(map.edg[i].type == 1)
            drawLine(int(map.edg[i].A.x*w/map.w), int(map.edg[i].A.y*h/map.h), int(map.edg[i].B.x*w/map.w), int(map.edg[i].B.y*h/map.h), WALL_DEBUG, 3);
        else
            drawLine(int(map.edg[i].A.x*w/map.w), int(map.edg[i].A.y*h/map.h), int(map.edg[i].B.x*w/map.w), int(map.edg[i].B.y*h/map.h), BLACK, 1);
    }
}

void graphics(Image& img, Player player, Map& map){
    raycast(img, player, map);
    hud(img, player);
}
