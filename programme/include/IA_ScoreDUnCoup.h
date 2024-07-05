 /**
 * \file IA_ScoreDUnCoup.h
 * \brief Implementation de la fonction qui permet à l IA de calculer le score d'un coup pour le jeu d'Othello
 * \author Charles Foyer Benchekroun Essakhi
 * \version 1.0
 * \date 11/12/2022
 *
 */
#ifndef __SCORE_DUN_COUP__
#define __SCORE_DUN_COUP__
#include "TAD_Plateau.h"
#include "TAD_Pion.h"
/**
 * \fn IA_scoreDUnCoup(Plateau p,Coup coup, Couleur couleur_joueur_referent,Couleur couleur_joueur_courant, unsigned int profondeur)
 * \brief Fonction qui retourne le score d'un coup
 *
 * \param p : le plateau
 * \param coup : le coup joué
 * \param couleur_joueur_courant : la couleur du joueur courant
 * \param couleur_joueur_referent : la couleur du joueur referent
 * \param profondeur : la profondeur
 * \return int
 */
int IA_scoreDUnCoup(Plateau p,Coup coup, Couleur couleur_joueur_referent,Couleur couleur_joueur_courant, unsigned int profondeur);

#endif
