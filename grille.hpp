#ifndef GRILLE_HPP_INCLUDED
#define GRILLE_HPP_INCLUDED

const float probaT = 0.05;
const float probaB = 0.1;

struct Case{
bool brindille; //true si brindille sur la case
int termite; //numero du termite si il est sur la case, -1 sinon
};

struct Grille{
    Case g[taille][taille];
};

/**initialise une grille vide
*@param [out] grille G
*/
void initialiseGrilleVide(Grille &G);

/**v�rifie si une case de coordonn�e C est vide
*@param [in] grille G et coordonn�es C
*@return true si la case est vide
*/
bool estVide(Grille G, Coord C);

/** v�rifie si coordonn�e est bien dans la grille
*@param [in] grille G et coordonn�e C
*@return true si dans la grille
*/
bool dansGrille(Grille G, Coord C);

/**v�rifie si case aux coordonn�es donn�es contient une brindille
*@param [in] grille G et coordonn�es C
*@return true si contient brindille
*/
bool contientBrindille(Grille G, Coord C);

/**donne le num�ro du termite � une coordonn�e donn�e
*@param [in] Grille G, coordonn�e C
*@return numero si un termite est pr�sent, -1 sinon
*/
int numTermite(Grille G, Coord C);

/**pose une brindille aux coordonn�es donn�es
*@param [in/out] grille G
*@param [in] coordonn�es C
*/
void poseBrindille(Grille &G, Coord C);
//OK

/**enleve une brindille aux coordonn�es donn�es
*@param [in/out] grille G
*@param [in] coordonn�es C
*/
void enleveBrindille(Grille &G, Coord C);
//OK

/**pose le n-i�me termite aux coordonn�es donn�es
*@param [in/out] grille G et tableau de termite T
*@param [in] coordonn�es C, int n le numero du termite dans son tableau
*/
void poseTermite(Grille &G, Coord C, int n);
//OK

/**enleve le n-i�me termite aux coordonn�es donn�es
*@param [in/out] grille G
*@param [in] coordonn�es C
*/
void enleveTermite(Grille &G, Coord C);
//OK

/**initialise une grille compl�te (avec termites et brindilles)
*@param [out] Grille G
*/
void initGrille(Grille &G);
//OK

/**affiche une grille
*@param [in] grille G
*/
void afficheGrille(Grille G);
//OK

/**contr�le pour chaque termite la coh�rence grille/termite
@param [in] grille G et numero de termite n
*/
void controle(Grille G, int n);

#endif // GRILLE_HPP_INCLUDED
