#include "headers/utils.h"

//***CLASS POINT DEFINITIONS***/

Point::Point(double X, double Y) //constructeur
{ 
	x=X;
	y=Y;
}
Point::Point() //constructeur vide
{}



Point Point::operator+(Point Q) //operateur +
{
	Point S;
	S.x=x+Q.x;
	S.y=y+Q.y;
	return S;
}

double Point::operator*(Point Q) //produit scalaire
{
	return x*Q.x+y*Q.y;
}

Point Point::operator-(Point Q) //operateur -
{
	Point S;
	S.x=x-Q.x;
	S.y=y-Q.y;
	return S;
}


double Point::norm() //norme euclidienne du Point
{
	return sqrt(x*x+y*y);
}



//***FONCTIONS RELATIVES AU POINT***//

Point operator*(float lambda, Point Q)
{
	Point S;
	S.x=lambda*Q.x;
	S.y=lambda*Q.y;
	return S;
}

Point operator*(Point Q, float lambda)
{
	return lambda*Q;
}

bool operator==(Point a, Point b)
{
    return (a.x == b.x && a.y == b.y);
}

bool operator!=(Point a, Point b)
{
    return !(a == b);
}

//***CLASS EDGE***//

bool Edge::sameSide(Point a, Point b){
    //Soit la droite formee par les deux points extremes de l'arete
    //On determine l'equation de la droite pour savoir si les points sont "en dessous" ou "au dessus"
    bool test1, test2;
    if(A.x != B.x){
        test1 = (a.y <= (a.x-A.x)*(B.y-A.y)/(B.x-A.x)+A.y);
        test2 = (b.y <= (b.x-A.x)*(B.y-A.y)/(B.x-A.x)+A.y);
    }
    else{
        test1 = (a.x <= A.x);
        test2 = (b.x <= A.x);
    }
    return !(test1 ^ test2);
}

bool operator==(Edge a, Edge b)
{
    return (a.A == b.A && a.B == b.B);
}

bool operator!=(Edge a, Edge b)
{
    return !(a == b);
}

//***CLASS FACE***//

bool Face::isInFace(Point p){
    return (E1.sameSide(P1, p) && E2.sameSide(P2, p) && E3.sameSide(P3, p));
}

void Face::loadPoints(){
    //On va chercher les aretes et les points correspondants et on les ordonne
    Point p2 = E1.A, p3 = E1.B; //p2 et p3 appartiennent a E1
    if(p3 == E2.A || p3 == E2.B) //Si p3 appartient a E2
        P3 = p3; //Alors p3 est oppose a E3
    else //Sinon p3 n'appartient pas a E2 donc est oppose a E2
        P2 = p3;
    
    if(p2 == E3.A || p2 == E3.B) //Si p2 appartient a E3
        P2 = p2; //Alors p2 est oppose a E2
    else //Sinon p2 n'appartient pas a E3 donc est oppose a E3
        P3 = p2;
    
    //P1 est donc le dernier point
    if(E2.A != P3)
        P1 = E2.A;
    else{
        P1 = E2.B;
    }
}

bool operator==(Face a, Face b)
{
    return (a.E1 == b.E1 && a.E2 == b.E2); //Il suffit qu'il y ait deux aretes en commun pour avoir l'egalite
}

bool operator!=(Face a, Face b)
{
    return !(a == b);
}

//***CLASS IMAGE***//
//Lance une image vide
Image::Image(){
    cols = new Color[W*H];
    w = W;
    h = H;
    for(int i = 0; i < W*H; i++)
        cols[i] = WHITE;
}

//Charge les images a partir de fichiers
Image::Image(string src){
    loadColorImage("images/"+src, cols, w, h);
}

//Removed Herobrine
Image::~Image(){
    delete [] cols;
}

//Obtenir un pixel
Color Image::get(int x, int y){
    return cols[y + x*w];
}

//Donner une valeur a un pixel
void Image::set(int x, int y, Color value){
    cols[y + x*w] = value;
}

//Afficher l'image
void Image::display(){
    putColorImage(0, 0, cols, w, h);
}

void Image::addSprite(Image& sprite, int x, int y){ //ecran.addSprite(sprite,x,y) points (x,y) point en haut a gauche du rectangle
    for(int i = 0; i < min(sprite.w, W-x); ++i)
        for(int j = 0; j < min(sprite.h, H-y); ++j)
            if(sprite.get(j,i) != TRANSPARENT)
                set(y+j, x+i, sprite.get(j, i));
}
//--------------------------------------------------------------------//

void uInitRandom(){
  srand((unsigned int)time(0));
}

int uRandom(int a, int  b){
  return rand()%(b+1-a)+a;
}