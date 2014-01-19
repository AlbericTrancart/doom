#include "headers/events.h" 

//Gère toutes les combinaisons de touches possibles
void handleEvent(int& endgame, Player& player,Map& map){
    
    Event e;
    int key;
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
			player.move_up(map);
			break;

		case 'Q':
			player.move_left(map);
			break;

		case 'D':
			player.move_right(map);
			break;

		case 'S':
			player.move_down(map);
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
            }
        }


    } while(e.type != EVT_NONE);
    

}
