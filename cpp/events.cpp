#include "headers/events.h" 

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
	if(key_z && key_q && !key_d && !key_s){player.move_up(map);player.move_left(map);return;}
	if(key_z && !key_q && key_d && !key_s){player.move_up(map);player.move_right(map);return;}
	if(key_z && !key_q && !key_d && key_s){return;}
	if(!key_z && key_q && key_d && !key_s){return;}
	if(!key_z && key_q && !key_d && key_s){player.move_down(map);player.move_left(map);return;}
	if(!key_z && !key_q && key_d && key_s){player.move_down(map);player.move_right(map);return;}
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

//Gère toutes les combinaisons de touches possibles
void handleEvent(int& endgame, Player& player,Map& map){
    
    Event e;
    int key;

	bool key_z=false; //Si Z est appuyé, key_z passe à true
	bool key_d=false; //Si D est appuyé, key_d passe à true
	bool key_s=false; //Si S est appuyé, key_s passe à true
	bool key_q=false; //Si Q est appuyé, key_q passe à true

    do{
        getEvent(0,e);
		cout << "key_z=" << key_z << endl << "key_q=" << key_q << endl << "key_d=" << key_d << endl << "key_s=" << key_s << endl << endl;
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
        else if(e.type == EVT_BUT_ON){
            if(player.weapon_state == 0)
                ++player.weapon_state;
        }

		event_move(player, map, key_z, key_q, key_d, key_s);
        
        //Armes
        if(player.weapon_state != 0) //Si le joueur est en train de tirer on continue de le faire tirer
            ++player.weapon_state;
        //Pour chaque arme on définit un temps de fin de tir
        if(player.weapon == 0){ //Poings
            if(player.weapon_state >= 8)
                player.weapon_state = 0;
        }

    } while(e.type != EVT_NONE);
    

}
