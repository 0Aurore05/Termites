#include <iostream>
#include <cassert>
#include "grille.hpp"
#include "termites.hpp"

using namespace std;

void initGrilleVide(Grille &G){
    for(int i=0; i<taille; i++){
        for(int j=0; j<taille; j++){
            G.g[i][j] = {false, -1};
        }
    }
}

bool estVide(Grille G, Coord C){
    Case c = G.g[C.x][C.y];
    return ( !c.brindille and c.termite==-1 );
}

bool dansGrille(Grille G, Coord C){
    return ( C.x<taille and C.x>=0 and C.y<taille and C.y>=0 );
}

bool contientBrindille(Grille G, Coord C){
    return (G.g[C.x][C.y].brindille);
}

int numTermite(Grille G, Coord C){
    return G.g[C.x][C.y].termite;
}

void poseBrindille(Grille &G, Coord C){
    G.g[C.x][C.y].brindille = true;
}

void enleveBrindille(Grille &G, Coord C){
     G.g[C.x][C.y].brindille = false;
}

void poseTermite(Grille &G, Coord C, int n){
    tabT[n].C = C; //change la coo de la termite dans le tableau de termite
    G.g[C.x][C.y].termite = n;
}

void enleveTermite(Grille &G, Coord C){
    G.g[C.x][C.y].termite = -1;
}

void initGrille(Grille &G){
    initGrilleVide(G);
    for(int i=0; i<taille; i++){
        for(int j=0; j<taille; j++){
            if(alea(probaT)) {
                poseTermite(G,{i,j},nbT) ;//rentre termite dans la case
                tabT[nbT] = {{i,j}, Direction(rand()%8), false, 0, nbT}; //crée le termite dans le tableau
                nbT++;
            } else if(alea(probaT+probaB)) G.g[i][j].brindille = true;
        }
    }
    return;
}

void afficheGrille(Grille G){
    for(int i=0; i<taille; i++){
        for(int j=0; j<taille; j++){
            if(G.g[i][j].brindille) cout<<" * ";
            else if(G.g[i][j].termite!= -1) afficheTermite(tabT[G.g[i][j].termite]);
            else cout << "  ";
        }
        cout<<endl;
    }
}

void controle(Grille G, int n){
    Coord c = tabT[n].C;
    Case Ca = G.g[c.x][c.y]; //case du termite

    if(numTermite(G,c) != n) cout << "Le termite " << n << " n'est pas a sa place dans le tableau" << endl;
    if(Ca.brindille and Ca.termite!=-1) cout <<"Un termite et une brindille partagent la même case"<<endl;
}
