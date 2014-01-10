#pragma once
#include <cmath>


//***CLASS POINT DECLARATIONS***//
class Point
{
public:

	float x,y; //champs

	Point(float X, float Y);	//constructeur
	Point();					//constructeur vide

	Point operator+(Point Q);	//opérateur +
	float operator*(Point Q);	//produit scalaire
	Point operator-(Point Q);	//opérateur -
	
	float norm(); //norme euclidienne (B-A).norm() donne la norme de AB
	
};

//***FONCTIONS RELATIVES AU POINT***//
Point operator*(float lambda, Point Q);
Point operator*(Point Q, float lambda);
