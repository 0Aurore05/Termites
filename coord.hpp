#ifndef COORD_HPP_INCLUDED
#define COORD_HPP_INCLUDED

const int taille = 20;

struct Coord{
int x, y;
};
enum Direction{NE, N, NO, O, SO, S, SE, E};

/** cr�e une coordonn�e
*@param [in] int i et j
*@return coordonn�e avec x=i de la grille et y=j de la grille (x la largeur de l'�cran // et y la longueur)
*/
Coord creeCoord(int i, int j);
//OK

/**affiche une coordonn�e sous la forme "x ; y" */
void afficheCoord(Coord c);
//OK

/**r�cup�re le x d'une coordonn�e
*@param [in] coordonn�e c
*@return int c.x
*/
int getX(Coord c);
/**r�cup�re le y d'une coordonn�e
*@param [in] coordonn�e c
*@return int c.y
*/
int getY(Coord c);
//OK

/**v�rifie si deux coordonn�es sont �gales
*@param [in] coordonn�es c1 et c2
*@return true si �gales, false sinon
*/
bool egalCoord(Coord c1, Coord c2);
//OK

/**affiche une direction en toute lettre*/
void afficheDirection(Direction d);
//OK

/**renvoie la direction � gauche d'une direction donn�e
*@param [in] la direction d
*@return la direction � gauche
**/
Direction agauche(Direction d);
//OK
/**renvoie la direction � droite d'une direction donn�e
*@param [in] la direction d
*@return la direction � droite
*/
Direction adroite(Direction d);
//OK

/**renvoie la coordonn�e devant celle donn�e, par rapport � la direction donn�e
*@param [in] coordonn�e c et direction d
*@return coordonn�e devant
*/
Coord devantCoord(Coord c, Direction d);
//OK

#endif // COORD_HPP_INCLUDED
