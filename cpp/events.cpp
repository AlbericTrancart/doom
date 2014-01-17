#include "headers/events.h" 

//Gère toutes les combinaisons de touches possibles
void handleEvent(int& endgame, Player& player){
    
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

				case KEY_UP:
					player.move_up(); //Inclure les restrictions par la suite pour qu'il ne traverse pas les murs,
										//ne sorte pas de la map...
					break;

				case KEY_LEFT:
					player.move_left(); //idem
					break;

				case KEY_RIGHT:
					player.move_right();
					break;

				case KEY_DOWN:
					player.move_down();
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