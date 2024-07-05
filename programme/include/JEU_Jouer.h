 /**
 * \file JEU_Jouer.h
 * \brief Implementation de la fonction jouer, qui permet d'effectuer toutes les étapes nécéssaires à un tour de jeu d'un joueur
 * \author Charles Foyer Benchekroun Essakhi
 * \version 1.0
 * \date 11/12/2022
 *
 */
#ifndef __JOUER__
#define __JOUER__
#include "TAD_Plateau.h"
#include "TAD_Couleur.h"
#include "TAD_Coup.h"
/**
 * \fn JEU_jouer(Plateau *p,Couleur couleur_joueur_courant, Coup (*obtenirCoup)(Plateau,Couleur, int, char, unsigned int),int ligne, char colonne, unsigned int profondeur)
 * \brief Procédure de jeu de coup sur le plateau p 
 *
 * \param p : le plateau
 * \param couleur_joueur_courant : la couleur du joueur courant
 * \param obtenirCoup : un pointeur de fonction sur la fonction à utiliser selon le joueur, un humain ou une IA 
 * \param ligne
 * \param colonne
 * \param profondeur : la profondeur à laquelle la recherche de coup devra se faire
 * \return void
 */
void JEU_jouer(Plateau *p,Couleur couleur_joueur_courant, Coup (*obtenirCoup)(Plateau,Couleur, int, char, unsigned int),int ligne, char colonne, unsigned int profondeur);

#endif
