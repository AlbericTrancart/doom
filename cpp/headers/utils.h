#pragma once
#include "constants.h"

class Point;
class Edge;
class Face;

class Point
{
public:
	double x,y;

	Point(double X, double Y);
	Point();

	Point operator+(Point Q);
	double operator*(Point Q);
	Point operator-(Point Q);
	double norm();
};

Point operator*(float lambda, Point Q);
Point operator*(Point Q, float lambda);
bool operator==(Point a, Point b);
bool operator!=(Point a, Point b);





class Edge {
public:
    Point A, B; //Bord de l'aeête
    int type, F1, F2; // /!\Pas les faces mais leur identifiants
    
    bool sameSide(Point a, Point b); //Vérifie si les points a et b sont dans le même demi plan formé par la droite définie à partir de l'arete E1.sameSide(P1,A)
};

bool operator==(Edge a, Edge b);
bool operator!=(Edge a, Edge b);





class Face {
public:
    Edge E1, E2, E3;
    Point P1, P2, P3; //Le point P1 est opposé à l'arête E1, etc. Sommets de la face
    
    bool isInFace(Point p); //Dit si le point est dans la face (wesh si on s'est pris un pain dans la gueule) (coûte 3 fois sameSide)
    void loadPoints(); //Charge les points correspondants aux arêtes, utilisé lors de l'initialisation de la map
};

bool operator==(Face a, Face b);
bool operator!=(Face a, Face b);






class Image {
    Color* cols;
    
public:
    int w, h;
    
    Image();
    Image(string src); //Image I("/.../img.png");
    ~Image();
    
    Color get(int x, int y);
    void set(int x, int y, Color value);
    void display(); //Afficher l'image
    void addSprite(Image& sprite, int x, int y); //Place une image en x, y en tenant compte de la transparence
};

void uInitRandom();
int uRandom(int a, int b);