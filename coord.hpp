#ifndef COORD_HPP_INCLUDED
#define COORD_HPP_INCLUDED

const int taille = 20;

struct Coord{
int x, y;
};
enum Direction{NE, N, NO, O, SO, S, SE, E};

/** crée une coordonnée
*@param [in] int i et j
*@return coordonnée avec x=i de la grille et y=j de la grille (x la largeur de l'écran // et y la longueur)
*/
Coord creeCoord(int i, int j);
//OK

/**affiche une coordonnée sous la forme "x ; y" */
void afficheCoord(Coord c);
//OK

/**récupère le x d'une coordonnée
*@param [in] coordonnée c
*@return int c.x
*/
int getX(Coord c);
/**récupère le y d'une coordonnée
*@param [in] coordonnée c
*@return int c.y
*/
int getY(Coord c);
//OK

/**vérifie si deux coordonnées sont égales
*@param [in] coordonnées c1 et c2
*@return true si égales, false sinon
*/
bool egalCoord(Coord c1, Coord c2);
//OK

/**affiche une direction en toute lettre*/
void afficheDirection(Direction d);
//OK

/**renvoie la direction à gauche d'une direction donnée
*@param [in] la direction d
*@return la direction à gauche
**/
Direction agauche(Direction d);
//OK
/**renvoie la direction à droite d'une direction donnée
*@param [in] la direction d
*@return la direction à droite
*/
Direction adroite(Direction d);
//OK

/**renvoie la coordonnée devant celle donnée, par rapport à la direction donnée
*@param [in] coordonnée c et direction d
*@return coordonnée devant
*/
Coord devantCoord(Coord c, Direction d);
//OK

#endif // COORD_HPP_INCLUDED
