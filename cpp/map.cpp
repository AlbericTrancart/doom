#include "headers/map.h"

//Utilitaire pour la lecture du fichier: prend une ligne et renvoie dans un array tous les entiers de la ligne dans l'ordre
//L'index 0 est la position du dernier élément et la recherche commence à partir de la position 1 de la chaine string.
//Les curseurs prennent comme valeur la position des espaces.
void getInts(string line, int result[7]){ //Prend la première ligne du test.map et la met dans un string nommé line
    int curs1 = 1, curs2;
    int i = 1; //Compteurs: i est le numéro de l'entier trouvé
    
    while(line.find_first_of(' ', curs1+1) != string::npos){ //Cherche le premier espace à partir de curs1=2
															 //npos valeur renvoyée si fin de la chaîne atteinte sans trouver d'espace
        curs2 = line.find_first_of(' ', curs1+1);
        result[i] = atoi(line.substr(curs1+1, curs2-curs1-1).c_str()); //On sélectionne ce qu'il y a entre curs1 et curs2 et on convertit en int
																	   //atoi convertit le tableau de char en int. c_str() convertit string en tableau de char chaque case du tableau =1 caractère. line_substr renvoie le string (de tel caractère, sur telle longueur).
        ++i;
        curs1 = curs2;
    }
    //On rajoute la fin de la ligne
    result[i] = atoi(line.substr(curs1+1).c_str());
    ++i;
    result[0] = i;
}

//***CLASS MAP***//
//--------------------------------------------------------------------//

Map::Map(string src){ //Map map("test");
    ifstream fichier(("maps/"+src+".map").c_str(), ios::in); //ifstream ouvre un fichier en lecture. ios::in méthode d'ouverture
    assert(fichier);
    
    string line;
    int result[7];
    
    getline(fichier, line); //met dans "line" la ligne sous la forme d'un string puis saute une ligne (curseur virtuel)
    getline(fichier, line); //(line est modifié -passé par référence-) à cette ligne propriétés générales de la map
    getInts(line, result);
    w = result[1];
    h = result[2];
    nbPoint = result[3];
    nbEdge = result[4];
    nbFace = result[5];
    cout << "Chargement d'une map de " << w << "x" << h << " comportant " << nbPoint << " points, " << nbEdge << " aretes et " << nbFace << " faces..." << endl;

    pnt = new Point[nbPoint];
    edg = new Edge[nbEdge];
    fac = new Face[nbFace];
    
   do{
        switch(line[0]){
            case 'P':
                getInts(line, result);
                pnt[result[1]].x = result[2];
                pnt[result[1]].y = result[3];
                break;
                
            case 'A':
                getInts(line, result);
                edg[result[1]].A = pnt[result[2]];
                edg[result[1]].B = pnt[result[3]];
                edg[result[1]].type = result[4];
                if(!(result[5] >= 0 && result[5] < nbFace))
                    edg[result[1]].F1 = -1;
                else
                    edg[result[1]].F1 = result[5];
                if(!(result[6] >= 0 && result[6] < nbFace))
                    edg[result[1]].F2 = -1;
                else
                    edg[result[1]].F2 = result[6];
                break;
                
            case 'F':
                getInts(line, result);
                fac[result[1]].E1 = edg[result[2]];
                fac[result[1]].E2 = edg[result[3]];
                fac[result[1]].E3 = edg[result[4]];
                fac[result[1]].loadPoints();
                break;
        }
    } while(getline(fichier, line));
    cout << "Map chargée." << endl;
    
    fichier.close();
}

Map::~Map(){
    delete [] pnt;
    delete [] edg;
    delete [] fac; //On supprime, nous Peillon déjà trop cher pour ca
}

float Map::findWall(Player player, float angle){  
    //On lance le rayon et on passe de face en face jusqu'à ce que l'on se cogne contre un mur
    Point p; //Point où se trouve le rayon
    p=player.pos;
    Face f = player.face; //Face dans laquelle se trouve le rayon
    Edge e; //Arête traversée par le rayon

    for(int i = 0; i < sqrt(w*w+h*h)/PAS_RAYCAST; ++i){
	//On avance le rayon. Au pire on se trouve dans un coin de la map et on regarde vers le coin opposé.
	//On doit alors voir le mur à l'autre bout de la map se rapprocher quand on avance.
        p.x = p.x + PAS_RAYCAST*cos(angle);
        p.y = p.y + PAS_RAYCAST*sin(angle);
        if(!f.E1.sameSide(player.pos, p)) //S'il traverse l'arête E1, !sameSide passe à true true
            e = f.E1;
        else if(!f.E2.sameSide(player.pos, p))
            e = f.E2;
        else if(!f.E3.sameSide(player.pos, p))
            e = f.E2;
        else //Sinon on ne traverse pas d'arête
            continue;

        //Si il n'y a rien, on avance, sinon c'est un mur
        if(e.type == 0){
            if(f.E1.F1 != -1 && fac[f.E1.F1].isInFace(p))
                f = fac[f.E1.F1];
            else if(f.E1.F2 != -1 && fac[f.E1.F2].isInFace(p))
                f = fac[f.E1.F2];
            else if(f.E2.F1 != -1 && fac[f.E2.F1].isInFace(p))
                f = fac[f.E2.F1];
            else if(f.E2.F2 != -1 && fac[f.E2.F2].isInFace(p))
                f = fac[f.E2.F2];
            else if(f.E3.F1 != -1 && fac[f.E3.F1].isInFace(p))
                f = fac[f.E3.F1];
            else if(f.E3.F2 != -1 && fac[f.E3.F2].isInFace(p))
                f = fac[f.E3.F2];
            else
                break; //Le point n'est pas dans une face à proximité, il est en dehors de la map
        }
        else
            break; //Si e est un mur, on s'arrête
    }
    return (p-player.pos).norm(); //On renvoie la distance entre le joueur et le rayon
}
//--------------------------------------------------------------------//
