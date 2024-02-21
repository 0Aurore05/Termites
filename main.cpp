#include <iostream>
#include "coord.cpp"
#include "grille.cpp"
#include "termites.cpp"

using namespace std;

int main(){
    srand (time(NULL));
    Grille G; int step;
    initGrille(G); afficheGrille(G);
    cout<<"entrez 0 pour arreter la simulation, ou entrez le nombre d'itérations"<<endl;
    do{
        cin>>step;
        for(int k=0; k<step; k++){ //nombre d'itérations entrées par l'utilisateur
            for(int i=0; i<nbT; i++){ //parcours le tableau de termite
                controle(G, i);
                unTour(G,tabT[i]);
            }
        }
        cout<<"_________________________________________________________"<<endl;
        afficheGrille(G);
    } while(step >0 );
    return 0;
}
