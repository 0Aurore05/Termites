#ifndef TERMITES_HPP_INCLUDED
#define TERMITES_HPP_INCLUDED

struct Termite{
Coord C;
Direction D;
bool brindille; //true si en porte une
int compteurPas; //pour vérifier si min 6 pas avant de poser brindille, et si min 6 avant d'en recharger une
int n; //sa position dans le tableau tabT
};

const int nbMaxT = taille*taille; //nombre maximal de termite accepté

const int nbPasMin = 6;

Termite tabT[nbMaxT]; //tableau de termite
int nbT = 0 ; //nombre de termite après les avoir placés dans la grille

/** utilise rand() pour évaluer si un évènement arrive selon sa proba p
*@param float p, la probabilité entre 0 et 1
*@return true si le résultat est < proba
*/
bool alea(float p);
//OK

/** return la direction d'un termite */
Direction dirTermite(Termite t);

/** renvoie la coordonnée devant le termite
*@param [in] termite t
*@return
*/
Coord devantTermite(Termite t);

/** vérifie si termite porte une brindille
*@param [in] termite t
*@return true si oui
*/
bool porteBrindille(Termite t);

/**change la direction du termite vers sa droite
*@param [in/out] termite t
*/
void tourneADroite(Termite &t);
//OK

/**idem pour la gauche*/
void tourneAGauche(Termite &t);
//OK

/**change aléatoirement la direction du termite
*@param [in/out] termite t
*/
void tourneAlea(Termite &t);
//OK

/**vérifie si la case devant le termite est vide
*@param [in] grille G et termite t
*@return true si elle est vide
*/
bool voieLibre(Grille G, Termite t);

/**vérifie si brindille en face de la termite
*@param [in] grille G et termite t
*@return true s'il y a une brindille
*/
bool brindilleEnFace(Grille G, Termite t);

/** vérifie si la termite ne s'enferme pas si elle pose une brindille
*@param [in] grille G et termite t
*@return true s'il reste au moins 2 cases de libre autour
*/
bool pasEnferme(Grille G, Termite t);

/**fait avancer le termite devant lui
*@param [in/out] grille g et termite t
*/
void avanceTermite(Grille &G, Termite &t);
//OK

/**Décharge le termite sur la case d'en face devant libre
*@param [in/out] grille G et termite t
*/
void dechargeTermite(Grille &G, Termite &t);

/**charge le termite avec le brin en face d'elle
*@param [in/out]Grille G et termite t
*/
void chargeTermite(Grille &G, Termite &t);

/** le termite avance droit avec une proba de 0,9 ; tourne sinon
*@param [in/out] grille G et termite t
*/
void marcheAlea(Grille &G, Termite &t);
//OK

/**affiche le termite selon sa direction */
void afficheTermite(Termite t);
//OK

using TAB = Termite[nbMaxT];
/**affiche le tableau de termite avec les caractéristiques de chaque termites
aide à vérifier si tableau et initialisation des termites fonctionne bien*/
void afficheTabT(TAB tabT);
//OK

/** vérifie si une termite est en face de la termite
@param [in] Grille G et Termite t
@param [int/out] int n, le numero du termite en face s'il est là, -1 sinon
@return true si n != -1
**/
bool termiteEnFace(Grille G, Termite t, int &n);

/** applique le comportement des termite pour un tour
@param [in/out] grille G, termite t
*/
void unTour(Grille &G, Termite &t);
//OK

#endif // TERMITES_HPP_INCLUDED
