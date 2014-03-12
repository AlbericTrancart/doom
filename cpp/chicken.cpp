#include "headers/chicken.h"

Image Ch1("chicken/kicked.jpg"); //Ch2("chicken/kicked.jpg"), Ch3("chicken/roasted.jpg");

void cInitChicken(Chicken chicken[], Map& map){
    
    for(int i = 0; i < NB_CHICKEN; ++i){
        chicken[i].health = CHICKEN_LIFE;
        chicken[i].pos.x = uRandom(0, map.w);
        chicken[i].pos.y = uRandom(0, map.h);
    }
}

void chicken_display(Chicken chicken[], Image& img, Player& player, Map& map){

    double coeff_chicken_size=1; //Multiple de la taille de l'image pour la taille des poulets que l'on affiche 
	double dist=0; //Distance entre le joueur et le poulet

	double chicken_angle=0;

	int keq=0;
	int jeq=0;

	double j_begin=0;

    for(int i = 0; i < NB_CHICKEN; ++i){ //Pour chacun des poulets
        
        dist = (chicken[i].pos-player.pos).norm();
        assert(dist != 0);
		coeff_chicken_size = H_CHICKEN/dist;

		chicken_angle = atan2((chicken[i].pos-player.pos).y,(chicken[i].pos-player.pos).x)+M_PI;

		j_begin=fmod(-(M_PI+player.yaw-chicken_angle-FOV/2)*W/FOV,2*M_PI*W/FOV);
		if(j_begin<0)
		{
			j_begin=j_begin+2*M_PI*W/FOV;
		}

		cout << "[" << fmod(-chicken_angle+4*M_PI, 2*M_PI) << "," << player.yaw << "," << j_begin << "]" << endl;

		if(map.findWall(player, fmod(-chicken_angle+4*M_PI, 2*M_PI)+M_PI/2)>dist)
		{
			if(j_begin<W && j_begin>0)
			{

				for(int i=0; i<H; ++i)
				{
					img.set(i,j_begin,RED);
				}
			}
		}



		//Si le poulet est dans le FOV ou en partie dans le FOV, on l'affiche
		/*if (-(coeff_chicken_size*Ch1.w/2)<chicken_angle && chicken_angle<FOV+(coeff_chicken_size*Ch1.w/2)){

			for(int k = max(0, int(H/2-coeff_chicken_size*Ch1.h/2)); k < min(int(H/2+coeff_chicken_size*Ch1.h/2), H); ++k){

				keq=floor(k/coeff_chicken_size);
				
					for(int j = max(int(j_begin-coeff_chicken_size*Ch1.w/2),0); j<min(int(j_begin+coeff_chicken_size*Ch1.w/2),W); ++j){

						jeq=floor(j/coeff_chicken_size);
				
							if(jeq<Ch1.w && keq<Ch1.h && Ch1.get(jeq,keq) != TRANSPARENT){
								img.set(j, k, Ch1.get(jeq,keq));
							}

					}
			}
		}*/

	}
}


void cAI(Chicken chicken[]){
    
    
}