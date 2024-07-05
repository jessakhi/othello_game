/**
 * \file TAD_Coup.h
 * \brief Implementation du TAD Coup pour le jeu d'Othello
 * \author Charles Foyer Benchekroun Essakhi
 * \version 1.0
 * \date 13/12/2022
 *
 */


#ifndef __COUP__
#define __COUP__
#include "TAD_Pion.h"
#include "TAD_Plateau.h"

/**
 * \brief Le type Coup est un pion 
 *
 */
typedef struct {
	Pion pion;	
} Coup;
/**
 * \fn  LCoup TADCoup_coup(Pion pion)
 * \brief Fonction qui creer un coup à partir d un pion
 * \param pion : le pion
 * \return Coup
 */

Coup TADCoup_coup(Pion pion);

/**
 * \fn  TADCoup_jouerCoup(Plateau *p, Coup coup)
 * \brief Fonction qui place un pion sur le plateau
 * \param p : le plateau
 * \param coup : le coup
 * \return void
 */
void TADCoup_jouerCoup(Plateau *p, Coup coup);

/**
 * \fn  TADCoup_obtenirPion(Coup coup)
 * \brief Fonction qui obtient le pion associé au coup
 * \param coup : le coup dont on veut récupérer le pion
 * \return Pion
 */
Pion TADCoup_obtenirPion(Coup coup);
#endif
