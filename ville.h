#ifndef VILLE_H
#define VILLE_H

#include <string>


enum Erreur_lecture {LECTURE_ARG, LECTURE_OUVERTURE, 
					 LECTURE_NB, LECTURE_FIN, LECTURE_ETAT};
					 
void lecture( char * nom_fichier);
void decodage_ligne(std::string line);
void erreur(Erreur_lecture code);

#endif
