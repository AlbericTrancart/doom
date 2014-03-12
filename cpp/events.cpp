#include "headers/events.h" 

//Si la touche reste appuyée, passe à true. Repasse à false quand le bouton est relâché.
bool key_z = false;
bool key_d = false;
bool key_s = false;
bool key_q = false;
bool mouse_on = false;

//(e0-e1) Représente la différence entre la coordonnée x de la position de la souris à un instant n et celle à l'instant n+1
double e0 = W/2; 
double e1 = W/2;
    
void move(Player& player, Map& map, bool key_z, bool key_q, bool key_d, bool key_s)
{
	//Avec un système touche => mouvement, quand on appuie sur deux touches opposées, on appelle des fonctions inutilement.
    //Ce système est plus compliqué mais évite des opérations coûteuses (calcul de la distance au mur le plus proche)

	//1 touche est appuyée
	if(key_z && !key_q && !key_d && !key_s){player.moveUp(map); return;}
	if(!key_z && key_q && !key_d && !key_s){player.moveLeft(map); return;}
	if(!key_z && !key_q && key_d && !key_s){player.moveRight(map); return;}
	if(!key_z && !key_q && !key_d && key_s){player.moveDown(map); return;}
	
	//2 touches sont appuyées
	if(key_z && key_q && !key_d && !key_s){player.moveUp(map,1/sqrt(2));player.moveLeft(map,1/sqrt(2));return;}
	if(key_z && !key_q && key_d && !key_s){player.moveUp(map,1/sqrt(2));player.moveRight(map,1/sqrt(2));return;}
	if(key_z && !key_q && !key_d && key_s){return;}
	if(!key_z && key_q && key_d && !key_s){return;}
	if(!key_z && key_q && !key_d && key_s){player.moveDown(map,1/sqrt(2));player.moveLeft(map,1/sqrt(2));return;}
	if(!key_z && !key_q && key_d && key_s){player.moveDown(map,1/sqrt(2));player.moveRight(map,1/sqrt(2));return;}
	
	//3 touches sont appuyées
	if(key_z && key_q && key_d && !key_s){player.moveUp(map); return;}
	if(key_z && !key_q && key_d && key_s){player.moveRight(map); return;}
	if(key_z && key_q && !key_d && key_s){player.moveLeft(map); return;}
	if(!key_z && key_q && key_d && key_s){player.moveDown(map); return;}
	
	//4 touches sont appuyées
	if(key_z && key_q && key_d && key_s){return;}

	return; //Aucune touche n'est appuyée

}

//Gère les armes du joueur
void eWeapons(Player& player){
    if(player.weapon == 5 && mouse_on) //Machine gun: demande un tir continu
        ++player.weapon_state;
    else if(player.weapon == 5 && !mouse_on)
        player.weapon_state = 0;
    
    if(player.weapon != 5) //Toutes les autres armes on un avencement normal sauf la machine gun
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
void eHandle(int& endgame, Player& player,Map& map){
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
					key_z = true;
					break;

				case 'Q':
					key_q = true;
					break;

				case 'D':
					key_d = true;
					break;

				case 'S':
					key_s = true;
					break;

				case 'A':
					player.turnLeft();
					break;
                    
				case 'E':
					player.turnRight();
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
					key_z = false;
					break;

				case 'Q':
					key_q = false;
					break;

				case 'D':
					key_d = false;
					break;

				case 'S':
					key_s = false;
					break;
            }
        }

		if(e.type == EVT_MOTION) {
			e0 = e1;
			e1 = e.pix[0];
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
            mouse_on = false;
        }

		move(player, map, key_z, key_q, key_d, key_s);

    } while(e.type != EVT_NONE);
}
