 /**
 * \file UNIT_IHM.h
 * \brief Unité qui contient les fonctions d'interface homme machine
 * \author Charles Foyer Benchekroun Essakhi
 * \version 1.0
 * \date 27/12/2022
 *
 */

#ifndef __IHM__
#define __IHM__

/**
 * \fn IHM_gras(char* texte)
 * \brief Fonction d'affichage d'un texte en gras
 *
 * \param texte: le texte à printf en gras
 * \return void
 */
void IHM_gras(char* texte);

/**
 * \fn IHM_separateur()
 * \brief Fonction d'affichage d'un séparateur
 *
 * \return void
 */
void IHM_separateur();

/**
 * \fn IHM_aide()
 * \brief Fonction d'affichage de l'aide
 *
 * \return void
 */
void IHM_aide();



#endif