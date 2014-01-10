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
//--------------------------------------------------------------------//

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

//Removed Herobrine
Image::~Image(){
    delete [] cols;
}
//--------------------------------------------------------------------//