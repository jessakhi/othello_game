 /**
 * \file JEU_CalculerScore.h
 * \brief Implementation de la fonction qui permet de  calculer le score de chaque joueur
 * \author Charles Foyer Benchekroun Essakhi
 * \version 1.0
 * \date 28/12/2022
 *
 */
#ifndef __CALCULER_SCORE__
#define __CALCULER_SCORE__
/**
 * \fn void JEU_calculerScore(Plateau pl, unsigned int* score_blanc, unsigned int* score_noir)
 * \brief fonction qui permet de déterminer calculer score pour trouver vainqueur
 *
 * \param pl : le plateau
 * \param score_blanc : un joueur
 * \param score_noir : l'autre joueur
 * \return void
 */

void JEU_calculerScore(Plateau pl, unsigned int* score_blanc, unsigned int* score_noir);

#endif
