 /**
 * \file JEU_ObtenirCoup.h
 * \brief Implementation de la fonction obtenir coup, côté humain 
 * \author Charles Foyer Benchekroun Essakhi
 * \version 1.0
 * \date 11/12/2022
 *
 */
#ifndef __OBTENIR_COUP_H__
#define __OBTENIR_COUP_H__
#include "TAD_Plateau.h"
#include "TAD_Couleur.h"
#include "TAD_Coup.h"
/**
 * \fn JEU_obtenirCoupH(Plateau p,Couleur couleur_joueur, unsigned int profondeur)
 * \brief Fonction qui retourne le coup à jouer
 *
 * \param p : le plateau
 * \param couleur_joueur : la couleur du joueur courant
 * \param profondeur : la profondeur
 * \return Coup
 */
Coup JEU_obtenirCoupH(Plateau p,Couleur couleur_joueur, int ligne, char colonne, unsigned int profondeur);

#endif
