#include "headers/utils.h"

//***CLASS POINT DEFINITIONS***/

//--------------------------------------------------------------------//
Point::Point(float X, float Y) //constructeur
{
	x=X;
	y=Y;
}

Point::Point() //constructeur vide
{
}
//--------------------------------------------------------------------//


//--------------------------------------------------------------------//
Point Point::operator+(Point Q) //opérateur +
{
	Point S;
	S.x=x+Q.x;
	S.y=y+Q.y;
	return S;
}

float Point::operator*(Point Q) //produit scalaire
{
	return x*Q.x+y*Q.y;
}

Point Point::operator-(Point Q) //opérateur -
{
	Point S;
	S.x=x-Q.x;
	S.y=y-Q.y;
	return S;
}
//--------------------------------------------------------------------//


//--------------------------------------------------------------------//
float Point::norm() //norme euclidienne du Point
{
	return sqrt(x*x+y*y);
}
//--------------------------------------------------------------------//


//***FONCTIONS RELATIVES AU POINT***//

//--------------------------------------------------------------------//
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
//--------------------------------------------------------------------//
bool Edge::sameSide(Point a, Point b){
    //Soit la droite formée par les deux points extremes de l'arête
    //On détermine l'équation de la droite pour savoir si les points sont "en dessous" ou "au dessus"
    bool test1, test2;
    if(A.x != B.x){
        test1 = (a.y <= (a.x-A.x)*(B.y-A.y)/(B.x-A.x)+A.y);
        test2 = (b.y <= (b.x-A.x)*(B.y-A.y)/(B.x-A.x)+A.y);
    }
    else{
        test1 = (a.x <= A.x);
        test2 = (b.x <= A.x);
    }
    return (test1 && test2);
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
//--------------------------------------------------------------------//
bool Face::isInFace(Point p){
    return (E1.sameSide(P1, p) && E2.sameSide(P2, p) && E3.sameSide(P3, p));
}

void Face::loadPoints(){
    //On va chercher les arêtes et les points correspondants et on les ordonne
    Point p2 = E1.A, p3 = E1.B;
    P1 = (E2.A == p2 || E2.A == p3)?E2.B:E2.A; //x=(test)?1:2 <-> if(test) {x=1;} else {x=2;}
    P2 = (p2 == E2.A || p2 == E2.B)?p3:p2;
    P3 = (p3 == E3.A || p3 == E3.B)?p2:p3;
}

bool operator==(Face a, Face b)
{
    return (a.E1 == b.E1 && a.E2 == b.E2); //Il suffit qu'il y ait deux arêtes en commun pour avoir l'égalité
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

//Charge les images à partir de fichiers
Image::Image(string src){
    loadColorImage(src, cols, w, h);
}

//Removed Herobrine
Image::~Image(){
    delete [] cols;
}

//Obtenir un pixel
Color Image::get(int x, int y){
    return cols[y + x*W];
}

//Donner une valeur à un pixel
void Image::set(int x, int y, Color value){
    cols[y + x*W] = value;
}

//Afficher l'image
void Image::display(){
    putColorImage(0, 0, cols, w, h);
}

void Image::addSprite(Image& sprite, int x, int y){ //ecran.addSprite(sprite,x,y) points (x,y) point en haut à gauche du rectangle
    for(int i = y; i < min(y+sprite.h, H); ++i)
        for(int j = x; j < min(x+sprite.w, W); ++j)
            if(sprite.get(i,j) != WHITE)
                set(i, j, sprite.get(i, j));
}
//--------------------------------------------------------------------//
