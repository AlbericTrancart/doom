#include "../headers/constants.h"

#include <iostream>
#include <cmath>
using namespace std;

#include "../headers/map.h"

bool end_game, alt, f4;

void init(int& w, int& h){
    string choix; 
    cout << "Voulez-vous ouvrir une map ou en creer une nouvelle ? [o/n] ";
    cin >> choix;

    if(choix.c_str()[0] == 'o'){
    }
    else{
        cout << "Veuillez entrer une taille pour la map." << endl << "Largeur ? ";
        cin >> w;
        cout << "Hauteur ? ";
        cin >> h;
    }
    openWindow(w, h, "Map editor");  
}

int handleEvent(){
    Event e;
    do{
        getEvent(0,e);
        if(e.type == EVT_KEY_ON){
            switch(e.key){
                case KEY_ESCAPE:
                    end_game = true;
                    break;                    
                case KEY_ALT:
                    alt = true;
                    break;                  
                case KEY_F4:
                    f4 = true;
                    break;
                default:
                    return e.key;
            }
        }
        else if(e.type == EVT_KEY_OFF){
            switch(e.key){
                case KEY_ALT:
                    alt = false;
                    break;
                case KEY_F4:
                    f4 = false;
                    break;
                default:
                    return e.key;
            }
        }
        else if(e.type == EVT_BUT_ON){   
        }
    } while(e.type != EVT_NONE);
    if(alt && f4)
        end_game = true;
    return 0;
}

int main(){
    int w, h;
    init(w, h);
    
    while(end_game){
        handleEvent();
        
        noRefreshBegin();
        
        noRefreshEnd();
        
        milliSleep(30);
    }

    endGraphics();
    return 0;
}