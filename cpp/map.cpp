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
                edg[result[1]].F1 = result[5];
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
    float dist; //Distance au mur
    
    //On lance le rayon et on passe de face en face jusqu'à ce que l'on se cogne contre un mur
    bool bang_le_mur = false;
    //On lance le rayon vers l'infini et au delà (donc très loin) pour être certain de sortir de la face
    //Ainsi on peut détécter l'arête que va traverser le rayon
    Point p;
    p.x = player.pos.x + INFINITE*cos(angle);
    p.y = player.pos.y + INFINITE*sin(angle);
    
    Face f = player.face; //Face courante, voire sprintante
    Edge e; //Elle aussi va très vite et ne s'arête pas là
    do {
        break;
        if(f.E1.sameSide(player.pos, p))
            e = f.E1;
        if(f.E2.sameSide(player.pos, p))
            e = f.E2;
        else
            e = f.E3;
        
        //Si il n'y a rien, on avance, sinon c'est un mur
        if(e.type == 0){
            //f = (f == e.F1)?e.F2:e.F1;
            continue;
        }
        else{
            bang_le_mur = true; //Aïe ca fait mal
            /*Raaaaah la géométrie
            On a deux droites (rayon et arête) qui s'intersectent en un point X,Y qu'il faut trouver
            Les deux droites on pour équations paramétriques:
            (X = a*cos(angle)+player.pos.x
            (Y = a*sin(angle)+player.pos.y
            et   
            (X = b*(x2-x1)+x1
            (Y = b*(y2-y1)+y1
            Maintenant vous avez foi dans mes compétences en géométrie*/
            float xp = player.pos.x, yp = player.pos.y, x1 = e.A.x, y1 = e.A.y, x2 = e.B.x, y2 = e.B.y;
            float x = -(cos(angle)*(-x1*y2+y1*x2+yp*(x1-x2))+sin(angle)*xp*(x2-x1))/(cos(angle)*(y2-y1)+sin(angle)*(x1-x2));
            float y = -(sin(angle)*(-x1*y2+y1*x2+xp*(y2-y1))+cos(angle)*yp*(y1-y2))/(cos(angle)*(y2-y1)+sin(angle)*(x1-x2));
            //On peut le faire en utilisant le point à l'infini mais l'expression est encore plus illisible
            dist = sqrt((xp-x)*(xp-x)+(yp-y)*(yp-y));
        }
    } while(!bang_le_mur);
    
    return 5;
}
//--------------------------------------------------------------------//
