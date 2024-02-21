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

/**vérifie si une case de coordonnée C est vide
*@param [in] grille G et coordonnées C
*@return true si la case est vide
*/
bool estVide(Grille G, Coord C);

/** vérifie si coordonnée est bien dans la grille
*@param [in] grille G et coordonnée C
*@return true si dans la grille
*/
bool dansGrille(Grille G, Coord C);

/**vérifie si case aux coordonnées données contient une brindille
*@param [in] grille G et coordonnées C
*@return true si contient brindille
*/
bool contientBrindille(Grille G, Coord C);

/**donne le numéro du termite à une coordonnée donnée
*@param [in] Grille G, coordonnée C
*@return numero si un termite est présent, -1 sinon
*/
int numTermite(Grille G, Coord C);

/**pose une brindille aux coordonnées données
*@param [in/out] grille G
*@param [in] coordonnées C
*/
void poseBrindille(Grille &G, Coord C);
//OK

/**enleve une brindille aux coordonnées données
*@param [in/out] grille G
*@param [in] coordonnées C
*/
void enleveBrindille(Grille &G, Coord C);
//OK

/**pose le n-ième termite aux coordonnées données
*@param [in/out] grille G et tableau de termite T
*@param [in] coordonnées C, int n le numero du termite dans son tableau
*/
void poseTermite(Grille &G, Coord C, int n);
//OK

/**enleve le n-ième termite aux coordonnées données
*@param [in/out] grille G
*@param [in] coordonnées C
*/
void enleveTermite(Grille &G, Coord C);
//OK

/**initialise une grille complète (avec termites et brindilles)
*@param [out] Grille G
*/
void initGrille(Grille &G);
//OK

/**affiche une grille
*@param [in] grille G
*/
void afficheGrille(Grille G);
//OK

/**contrôle pour chaque termite la cohérence grille/termite
@param [in] grille G et numero de termite n
*/
void controle(Grille G, int n);

#endif // GRILLE_HPP_INCLUDED
