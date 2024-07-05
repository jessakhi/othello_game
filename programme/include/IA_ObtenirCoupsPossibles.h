 /**
 * \file IA_ObtenirCoupsPossibles.h
 * \brief Implementation de la fonction qui permet à l IA d'obtenir la liste des coups qu'on peut jouer sur le plateau
 * \author Charles Foyer Benchekroun Essakhi
 * \version 1.0
 * \date 11/12/2022
 *
 */
#ifndef __OBTENIR_COUPS_POSSIBLES__
#define __OBTENIR_COUPS_POSSIBLES__
#include "TAD_Plateau.h"
#include "TAD_Couleur.h"
/**
 * \fn IA_obtenirCoupsPossibles(Plateau p,Couleur couleur_joueur)
 * \brief Fonction qui retourne la listes des coups jouables
 *
 * \param p : le plateau
 * \param couleur_joueur : la couleur du joueur courant (IA)
 * \return Coups : la liste des coups jouables
 */
Coups IA_obtenirCoupsPossibles(Plateau p,Couleur couleur_joueur);

#endif
