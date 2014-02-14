#include "headers/events.h" 

bool key_z=false; //Si Z est appuyé, key_z passe à true
bool key_d=false; //Si D est appuyé, key_d passe à true
bool key_s=false; //Si S est appuyé, key_s passe à true
bool key_q=false; //Si Q est appuyé, key_q passe à true
bool mouse_on = false;
double e0=W/2; //(e0-e1) Représente la différence entre la coordonnée x de la position de la souris à un instant n et celle à l'instant n+1
double e1=W/2; //Si le joueur déplace sa souris vers la gauche, cette différence est positive et le joueur tourne à gauche
    
void event_move(Player& player, Map& map, bool key_z, bool key_q, bool key_d, bool key_s)
{
	/*if(key_z) {player.move_up(map);}
	if(key_q) {player.move_left(map);}
	if(key_d) {player.move_right(map);}
	if(key_s) {player.move_down(map);}

	return;*/ //Semble plus simple. Mais on appelle des fonctions inutilement. Quand il y a Z et S enfoncé on appelle move_down et move_up pour ne rien faire.
			  //La proposition qui suit me paraît donc plus compliquée mais plus rapide.

	//1 touche est appuyée
	if(key_z && !key_q && !key_d && !key_s){player.move_up(map); return;}
	if(!key_z && key_q && !key_d && !key_s){player.move_left(map); return;}
	if(!key_z && !key_q && key_d && !key_s){player.move_right(map); return;}
	if(!key_z && !key_q && !key_d && key_s){player.move_down(map); return;}
	//------------------
	//2 touches sont appuyées
	if(key_z && key_q && !key_d && !key_s){player.move_up(map,1/sqrt(2));player.move_left(map,1/sqrt(2));return;}
	if(key_z && !key_q && key_d && !key_s){player.move_up(map,1/sqrt(2));player.move_right(map,1/sqrt(2));return;}
	if(key_z && !key_q && !key_d && key_s){return;}
	if(!key_z && key_q && key_d && !key_s){return;}
	if(!key_z && key_q && !key_d && key_s){player.move_down(map,1/sqrt(2));player.move_left(map,1/sqrt(2));return;}
	if(!key_z && !key_q && key_d && key_s){player.move_down(map,1/sqrt(2));player.move_right(map,1/sqrt(2));return;}
	//------------------
	//3 touches sont appuyées
	if(key_z && key_q && key_d && !key_s){player.move_up(map); return;}
	if(key_z && !key_q && key_d && key_s){player.move_right(map); return;}
	if(key_z && key_q && !key_d && key_s){player.move_left(map); return;}
	if(!key_z && key_q && key_d && key_s){player.move_down(map); return;}
	//------------------
	//4 touches sont appuyées
	if(key_z && key_q && key_d && key_s){return;}
	//------------------

	return; //Aucune touche n'est appuyée

}

//Gère les armes du joueur
void eWeapons(Player& player){
    if(player.weapon == 5 && mouse_on) //Machine gun: demande un tir continu
        ++player.weapon_state;
    else if(player.weapon == 5 && !mouse_on)
        player.weapon_state = 0;
    
    if(player.weapon != 5) //Toutes les autres armes on un avencement normal
        if(player.weapon_state != 0) //Si le joueur est en train de tirer on continue de le faire tirer
            ++player.weapon_state;

    //Pour chaque arme on définit un temps de fin de tir au bout duquel on remet à zero l'arme
    switch(player.weapon){
        case 1: //Poings
        if(player.weapon_state >= 5)
            player.weapon_state = 0;
        break;
    
        case 2: //Gun
        if(player.weapon_state >= 5)
            player.weapon_state = 0;
        break;
    
        case 3: //Shotgun
        if(player.weapon_state >= 11)
            player.weapon_state = 0;
        break;
    
        case 4: //Carabine
        if(player.weapon_state >= 13)
            player.weapon_state = 0;
        break;
    
        case 5: //Machine gun
        if(player.weapon_state >= 13)
            player.weapon_state = 10;
        break;
    
        case 6: //Plasma gun
        if(player.weapon_state >= 10)
            player.weapon_state = 0;
        break;
    } 
}

//Gère toutes les combinaisons de touches possibles
void handleEvent(int& endgame, Player& player,Map& map){
    
    Event e;

    do{
        getEvent(0,e);

        if(e.type == EVT_KEY_ON){
            switch(e.key){
                case KEY_ESCAPE:
                    endgame = 1;
                    break;
                    
                case KEY_ALT:
                    if(endgame == 3)
                        endgame = 1;
                    else
                        endgame = 2;
                    break;
                    
                case KEY_F4:
                    if(endgame == 2)
                        endgame = 1;
                    else
                        endgame = 3;
                    break;

				case 'Z':
					key_z=true;
					break;

				case 'Q':
					key_q=true;
					break;

				case 'D':
					key_d=true;
					break;

				case 'S':
					key_s=true;
					break;

				case 'A':
					player.turn_left();
					break;
                    
				case 'E':
					player.turn_right();
					break;
                    
                case '&':
                    player.weapon = 1;
                    player.weapon_state = 0;
                    break;
                    
                case 201: // 201 <-> 'é' (e accent aigu agencement linux) mais le compilateur veut pas d'accent.
                    player.weapon = 2;
                    player.weapon_state = 0;
                    break;

				case 233: // 233 <-> 'é' (e accent aigu agencement windows) mais le compilateur veut pas d'accent.
                    player.weapon = 2;
                    player.weapon_state = 0;
                    break;
                
                case '"':
                    player.weapon = 3;
                    player.weapon_state = 0;
                    break;
                    
                case '\'':
                    player.weapon = 4;
                    player.weapon_state = 0;
                    break;

                case '(':
                    player.weapon = 5;
                    player.weapon_state = 0;
                    break;
                    
                case '-':
                    player.weapon = 6;
                    player.weapon_state = 0;
                    break;
                    
                case KEY_SPACE:
                    sPunchline();
                    break;
            }
        }

        if(e.type == EVT_KEY_OFF){
            switch(e.key){
                case KEY_ALT:
                    endgame = 0;
                    break;
                    
                case KEY_F4:
                    endgame = 0;
                    break;

				case 'Z':
					key_z=false;
					break;

				case 'Q':
					key_q=false;
					break;


				case 'D':
					key_d=false;
					break;


				case 'S':
					key_s=false;
					break;
            }
        }

		if(e.type == EVT_MOTION) {

			e0=e1;
			e1=e.pix[0];

			player.motion(e0, e1);

		}
			

        if(e.type == EVT_BUT_ON){
            mouse_on = true;
            if(player.weapon_state == 0){
                ++player.weapon_state;
                if(player.weapon != 5)
                    sWeapon(player.weapon);
            }
        }
        
		if(e.type == EVT_BUT_OFF){
            mouse_on= false;
        }

		event_move(player, map, key_z, key_q, key_d, key_s);

    } while(e.type != EVT_NONE);
}
