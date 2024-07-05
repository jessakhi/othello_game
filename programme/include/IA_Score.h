 /**
 * \file IA_Score.h
 * \brief Implementation de la fonction qui permet à l IA de calculer le score pour le jeu d'Othello
 * \author Charles Foyer Benchekroun Essakhi
 * \version 1.0
 * \date 11/12/2022
 *
 */

#ifndef __SCORE__
#define __SCORE__
#include "TAD_Plateau.h"
#include "TAD_Couleur.h"
/**
 * \fn score(Plateau p, Pion pion)
 * \brief Fonction qui retourne le score, elle compte le nombre de pions du joueur passé en entrée retournés sur le plateau
 *
 * \param p : le plateau
 * \param pion : le pion du joueur courant (IA)
 * \return int
 */
int IA_score(Plateau p,Couleur couleur_joueur);

#endif
