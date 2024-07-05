 /**
 * \file IA_Evaluer.h
 * \brief Implementation de la fonction qui permet à l IA d'evaluer un plateau au sens d'un joueur
 * \author Charles Foyer Benchekroun Essakhi
 * \version 1.0
 * \date 11/12/2022
 *
 */


#ifndef __EVALUER__
#define __EVALUER__
#include "TAD_Plateau.h"
#include "TAD_Couleur.h"
/**
 * \fn IA_evaluer(Plateau p, Couleur couleur_joueur)
 * \brief Fonction qui permet à l'ia d'évaluer un plateau au sens d'un joueur 
 *
 * \param p : le plateau
 * \param couleur_joueur : la couleur du joueur courant (IA)
 * \return int : le score
 */
int IA_evaluer(Plateau p, Couleur couleur_joueur);

#endif
