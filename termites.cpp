#include <iostream>
#include <vector>
#include <cassert>
#include "termites.hpp"

using namespace std;

bool alea(float p){
int res = rand()%100;
return (res < int(p*100));
}

Direction dirTermite(Termite t){
    return t.D;
}

Coord devantTermite(Termite t){
    return devantCoord(t.C, t.D);
}

bool porteBrindille(Termite t){
    return t.brindille;
}

void tourneADroite(Termite &t){
    t.D = adroite(t.D);
}
void tourneAGauche(Termite &t){
    t.D = agauche(t.D);
}

void tourneAlea(Termite &t){
    Direction res;
    do{
        res = Direction(rand()%8);
    }while(res == t.D);
    t.D = res;
}

bool voieLibre(Grille G, Termite t){
    Coord d = devantCoord(t.C, t.D);
    return estVide(G, d);
}

bool brindilleEnFace(Grille G, Termite t){
    Coord d = devantTermite(t);
    return contientBrindille(G, d);
}

bool pasEnferme(Grille G, Termite t){
    int k=0;
    for(int i=0; i<8; i++){
        if(estVide(G, devantCoord(t.C, Direction(i)))) k++;
    }
    return (k>=2); //au moins 2 cases libres autour du termite
}

void avanceTermite(Grille &G, Termite &t){
    enleveTermite(G, t.C);
    poseTermite(G, devantTermite(t), t.n);
}

void dechargeTermite(Grille &G, Termite &t){
    Coord c = devantTermite(t);
    poseBrindille(G, c);
    t.brindille = false;
}

void chargeTermite(Grille &G, Termite &t){
    Coord c = devantTermite(t);
    enleveBrindille(G,c);
    t.brindille = true;
}

void marcheAlea(Grille &G, Termite &t){
   if (voieLibre(G,t) and alea(0.9)) {
       avanceTermite(G,t);
   } else {
       tourneAlea(t);
   }
}

void afficheTermite(Termite t){
    switch(t.D){
        case NE: cout <<" /"; break;
        case N: cout <<" |"; break;
        case NO: cout<<" \\"; break;
        case O: cout<<" -"; break;
        case SO: cout<<" /"; break;
        case S: cout<<" |"; break;
        case SE: cout<<" \\"; break;
        case E: cout<<" -"; break;
    }
    if (t.brindille) cout<<".";
    else cout<<" ";
}

void afficheTabT(TAB tabT){
    Termite t;
    cout << "nombre total de termite : " << nbT << endl;
    for(int k=0; k<nbT; k++){
        t = tabT[k];
        cout << "numero: "<< t.n << " / " << "coordonnées: ";
        afficheCoord (t.C);
        cout << " / " << "direction: ";
        afficheDirection(t.D);
        cout << " / " << "pas : " << t.compteurPas << " / " <<  "brindille: ";
        if(!t.brindille) cout<<"non"; else cout << "oui" ;
        cout<<endl;
    }
}

bool termiteEnFace(Grille G, Termite t, int &n){
    Coord c = devantTermite(t);
    n = G.g[c.x][c.y].termite;
    return n!=-1;
}

void unTour(Grille &G, Termite &t){
    marcheAlea(G,t);
    int n;
    if(brindilleEnFace(G,t)) {
        if(t.brindille and t.compteurPas>=nbPasMin){ //si le termite est déja chargé
            int k=0;
            do{
                t.D=Direction((t.D+1)%8); //tourne jusqu'à tour complet / ou case vide devant
                k++;
            }while(!voieLibre(G,t) and k<8);
            if(voieLibre(G,t) and pasEnferme(G,t)) { //si le termite peut poser sa brindille
                dechargeTermite(G,t);
                t.compteurPas=0;
            } else t.compteurPas++;

        } else if(t.compteurPas>=nbPasMin){ //si le termite est déchargé
            chargeTermite(G,t);
            t.compteurPas=0;
        } else t.compteurPas++;

    }else if(termiteEnFace(G,t,n) and !tabT[n].brindille){ //s'il y a un termite déchargé en face
        t.brindille = false; t.compteurPas = 0;
        tabT[n].brindille = true; tabT[n].compteurPas = 0;
    }else t.compteurPas++;
}
