#include <iostream>
#include <cassert>
#include "coord.hpp"

using namespace std;

Coord creeCoord(int i, int j){
    return {i,j};
}

void afficheCoord(Coord c){
    cout << "{"<< c.x << " ; "<< c.y<< "}";
}

int getX(Coord c){
return c.x;
}
int getY(Coord c){
return c.y;
}

bool egalCoord(Coord c1, Coord c2){
return (c1.x == c2.x and c1.y == c2.y);
}

void afficheDirection(Direction d){
    switch(d){
        case NE: cout <<"Nord-Est"; break;
        case N: cout <<"Nord"; break;
        case NO: cout<<"Nord-Ouest"; break;
        case O: cout<<"Ouest"; break;
        case SO: cout<<"Sud-Ouest"; break;
        case S: cout<<"Sud"; break;
        case SE: cout<<"Sud-Est"; break;
        case E: cout<<"Est"; break;
    }
}

Direction agauche(Direction d){
    return Direction((d+2)%8);
}
Direction adroite(Direction d){
    return Direction((d+6)%8);
}

Coord devantCoord(Coord c, Direction d){
    Coord res;
    if(d == SO) res = {c.x+1, c.y-1};
    else if(d == O) res = {c.x, c.y-1};
    else if(d == NO) res = {c.x-1, c.y-1};
    else if(d == N) res = {c.x-1, c.y};
    else if(d == NE) res = {c.x-1, c.y+1};
    else if(d == E) res = {c.x, c.y+1};
    else if(d == SE) res = {c.x+1, c.y+1};
    else if(d == S) res = {c.x+1, c.y};
    if(res.x < taille and res.y < taille and res.x >=0 and res.y >=0) return res;
    else return {c.x, c.y};
}
