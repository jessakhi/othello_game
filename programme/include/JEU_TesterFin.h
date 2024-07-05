 /**
 * \file IA_TesterFin.h
 * \brief Implementation de la fonction qui permet à l IA de vérifier si la partie est terminée
 * \author Charles Foyer Benchekroun Essakhi
 * \version 1.0
 * \date 11/12/2022
 *
 */


#ifndef __TESTER_FIN__
#define  __TESTER_FIN__
#include "TAD_Plateau.h"
#include "TAD_Couleur.h"
/**
 * \fn JEU_testerFin(Plateau p, Couleur couleur_joueur)
 * \brief Fonction qui vérifie si la partie est terminée 
 *
 * \param p : le plateau
 * \param pion : le pion du joueur courant (IA)
 * \return int
 */
bool JEU_testerFin(Plateau p);

#endif
