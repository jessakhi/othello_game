 /**
 * \file IA_obtenirCoupIA.h
 * \brief Implementation de la fonction qui permet à l'IA d'obtenir un coup en utilisant l'ensemble des algorithmes préfixés IA_
 * \author Charles Foyer Benchekroun Essakhi
 * \version 1.0
 * \date 11/12/2022
 *
 */

#ifndef __OBTENIR_COUP_IA__
#define __OBTENIR_COUP_IA__
#include "TAD_Plateau.h"
#include "TAD_Couleur.h"
/**
 * \fn IA_obtenirCoupIA(Plateau p,Couleur couleur_joueur_courant,unsigned int profondeur)
 * \brief Fonction qui retourne le coup à jouer par l'IA
 *
 * \param p : le plateau
 * \param couleur_joueur_courant : la couleur du joueur courant (IA)
 * \param profondeur : la profondeur
 * \return Coup
 */
Coup IA_obtenirCoupIA(Plateau p,Couleur couleur_joueur_courant,int ligne, char colonne, unsigned int profondeur);

#endif

