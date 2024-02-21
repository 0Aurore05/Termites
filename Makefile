# Fichier makefile pour projet termite
######################################

# Quelques variables de configuration du compilateur
#####################################f###############
# Le compilateur �  utiliser
CXX = g++
# Les options du compilateur
CXXFLAGS = -Wall -std=c++11 -g

# Les programmes principaux
###########################
# On donne le fichier .cpp et la liste des fichiers .o qu'ils utilisent

main.cpp: termites.o grille.o coord.o

# Les diff�rents composants
###########################
# on donne le fichier .cpp ainsi que la liste
# des fichiers .hpp dont ils d�pendent

main.o: coord.hpp termites.hpp grille.hpp
coord.o: coord.cpp coord.hpp
grille.o: grille.cpp grille.hpp coord.hpp
termites.o: termites.cpp coord.hpp grille.hpp

# Pour faire le m�nage
clean:
	rm -f ProjetFinal *.o
# Attention dans la ligne ci-dessus il faut �crire
# un seul caract�re de tabulation et pas 8 espaces.
