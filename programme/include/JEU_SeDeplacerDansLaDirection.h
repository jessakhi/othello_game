 /**
 * \file JEU_SeDeplacerDansLaDirection.h
 * \brief Implementation de la fonction seDeplacerDansLaDirection pour le jeu d'Othello
 * \author Charles Foyer Benchekroun Essakhi
 * \version 1.0
 * \date 11/12/2022
 *
 */

#ifndef __SE_DEPLACER_DANS_LA_DIRECTION__
#define __SE_DEPLACER_DANS_LA_DIRECTION__
#include "TAD_Position.h"
/**
 * \fn JEU_seDeplacerDansLaDirection(Position pos, unsigned int dir)
 * \brief Déplace une position dans une direction numérotée de 0 à 7
 *
 * \param pos : la position
 * \param dir : la direction
 * \return Position
 */
Position JEU_seDeplacerDansLaDirection(Position pos, unsigned int dir);

#endif
