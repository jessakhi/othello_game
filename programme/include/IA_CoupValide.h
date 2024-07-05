 /**
 * \file IA_CoupValide.h
 * \brief Implementation de la fonction qui permet à l IA de vérifier que un coup est bien jouable (valide)
 * \author Charles Foyer Benchekroun Essakhi
 * \version 1.0
 * \date 22/12/2022
 *
 */
#ifndef __COUP_VALIDE__
#define __COUP_VALIDE__
#include "TAD_Plateau.h"
#include "TAD_Coup.h"
/**
 * \fn IA_coupValide(Plateau p, Coup c)
 * \brief Fonction qui vérifie la validité d'un coup sur un plateau p
 *
 * \param p : le plateau
 * \param c : le coup
 * \return bool : si le coup est valide ou non
 */
bool IA_coupValide(Plateau p, Coup coup);

#endif
