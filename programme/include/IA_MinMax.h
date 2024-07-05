 /**
 * \file IA_MinMax.h
 * \brief Implementation de l'algorithme du MinMax qui maximise le score de l'IA et minimise celui de l'adversaire
 * \author Charles Foyer Benchekroun Essakhi
 * \version 1.0
 * \date 22/12/2022
 *
 */
#ifndef __MIN_MAX__
#define __MIN_MAX__
#include "TAD_Plateau.h"
#include "TAD_Couleur.h"
/**
 * \fn IA_minMax(Plateau p,Couleur couleur_joueur_courant,Couleur couleur_joueur_referent, unsigned int profondeur)
 * \brief Fonction qui maximise le score du joueur (IA) et minimise celui de son adversaire
 *
 * \param p : le plateau
 * \param couleur_joueur_courant : la couleur du joueur courant, on minimisera si c'est l'adversaire, maximisera si elle coincide avec la couleur_joueur_referent 
 * \param couleur_joueur_referent : la couleur du joueur de référence, l'IA
 * \param profondeur : la profondeur à laquelle l'ia travaille
 * \return int : le résultat de l'algorithme MinMax
 */
int IA_minMax(Plateau p,Couleur couleur_joueur_referent,Couleur couleur_joueur_courant, unsigned int profondeur);

#endif
