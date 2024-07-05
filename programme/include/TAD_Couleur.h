/**
 * \file TAD_Couleur.h
 * \brief Implementation du TAD Couleur pour le jeu d'Othello
 * \author Charles Foyer Benchekroun Essakhi
 * \version 1.0
 * \date 11/12/2022
 *
 */

#ifndef __COULEUR__
#define __COULEUR__
#include <stdbool.h>
/**
 * \brief Le type Couleur permet de représenter une couleur à partir de d'un booléen (1,0)
 *
 */
typedef struct{
	bool couleur;
} Couleur;
/**
 * \fn TADCouleur_couleur(bool c)
 * \brief Fonction de création d'une couleur
 *
 * \param c: le booléen
 * \return Couleur
 */
Couleur TADCouleur_couleur(bool c);
/**
 * \fn TADCouleur_couleurOpposee(Couleur c)
 * \brief Fonction de création de l'opposé de la couleur
 *
 * \param c: la couleur
 * \return Couleur
 */
Couleur TADCouleur_couleurOpposee(Couleur c);
/**
 * \fn TADCouleur_couleursIdentiques(Couleur couleur1,Couleur couleur2)
 * \brief Fonction dqui verifie si deux couleurs sont identiques
 *
 * \param couleur1: la couleur
 * \param couleur2 : la deuxième couleur
 * \return bool
 */
bool TADCouleur_couleursIdentiques(Couleur couleur1,Couleur couleur2);
/**
 * \fn TADCouleur_afficherCouleur(Couleur couleur)
 * \brief Fonction qui affiche l'équivalent en couleur réelle du booléen contenu dans couleur.couleur
 *
 * \param couleur1: la couleur
 * \return const char*
 */
char* TADCouleur_afficherCouleur(Couleur couleur);

#endif

