/**
 * \file TAD_Plateau.h
 * \brief Implementation du TAD Plateau pour le jeu d'Othello
 * \author Charles Foyer Benchekroun Essakhi
 * \version 1.0
 * \date 11/12/2022
 *
 */

#ifndef __PLATEAU__
#define __PLATEAU__
#include "TAD_Pion.h"


/**
 * \brief Le type Plateau permet de représenter un plateau de jeu
 *
 */

typedef struct {
  Pion lesPions[8][8];
  bool estPlein; 
  unsigned int nbPionsPlaces;
} Plateau;

/**
 * \fn TADPlateau_plateau ()
 * \brief Fonction de création d'un plateau
 *
 * \return Plateau
 */

Plateau TADPlateau_plateau();

/**
 * \fn TADPlateau_testerFin(Plateau p)
 * \brief Fonction qui permet de savoir si le tableau est rempli
 *
 * \param p : le plateau 
 * \param couleur_joueur : la couleur du joueur courant
 * \return bool
 */
bool TADPlateau_testerFin(Plateau p, Couleur couleur_joueur);

/**
 * \fn TADPlateau_nbPionsDUneCouleur(Plateau p, Couleur c)
 * \brief Fonction qui permet d'obtenir le nombre de pion de couleur c placés sur le plateau
 *
 * \param p : le plateau
 * \param c : la couleur
 * \return unsigned int
 */
unsigned int TADPlateau_nbPionsDUneCouleur(Plateau p, Couleur c);

/**
 * \fn TADPlateau_obtenirHauteur(Plateau p)
 * \brief Fonction qui permet d'obtenir la hauteur du plateau (encapsulation)
 *
 * \param p : le plateau
 * \return unsigned int
 */
unsigned int TADPlateau_obtenirHauteur(Plateau p);

/**
 * \fn TADPlateau_obtenirLargeur(Plateau p)
 * \brief Fonction qui permet d'obtenir la largeur du plateau (encapsulation)
 *
 * \param p : le plateau
 * \return unsigned int
 */
unsigned int TADPlateau_obtenirLargeur(Plateau p);

/**
 * \fn TADPlateau_mettreAJourPlateau(Plateau p)
 * \brief Procedure qui permet de mettre à jours le tableau
 *
 * \param p : le plateau
 * \return Plateau
 */
Plateau TADPlateau_mettreAJourPlateau(Plateau p);

/**
 * \fn TADPlateau_obtenirPion(Plateau p, Couleur c)
 * \brief Fonction qui permet d'obtenir le pion placé à la position pos sur le plateau p
 *
 * \param p : le plateau
 * \param pos : la position
 * \return Pion
 */
Pion TADPlateau_obtenirPion(Plateau p, Position pos);

/**
 * \fn TADPlateau_estPlein(Plateau p)
 * \brief Fonction qui permet de savoir si le plateau p est plein (tous les pions placés)
 *
 * \param p : le plateau
 * \return bool
 */
bool TADPlateau_estPlein(Plateau p);
/**
 * \fn TADPlateau_placerPion(Pion *pion, Couleur couleur)
 * \brief Procédure pour placer un pion
 *
 * \param p : le plateau (pointeur sur plateau)
 * \param pion : le pion
 */

void TADPlateau_placerPion(Plateau *p, Pion pion);

/* fonctions liées à l'utilisation de l'allocation dynamique */
/**
 * \fn TADPlateau_copier(Plateau p)
 * \brief Fonction qui permet de créer une copie du tableau pour le modifier sans modifier le précédent 
 *
 * \param p : le plateau
 * \return Plateau
 */
void TADPlateau_copier(Plateau p,Plateau *copie);
/* fonctions liées à l'utilisation de l'allocation dynamique */
/**
 * \fn TADPlateau_memePlateau(Plateau p)
 * \brief Fonction qui permet de savoir si deux plateau sont egaux
 *
 * \param p : le plateau
 * \return bool
 */
bool TADPlateau_memePlateau(Plateau p1, Plateau p2);
/* fonctions liées à l'utilisation de l'allocation dynamique */
/**
 * \fn TADPlateau_effacer(Plateau p)
 * \brief Procédure qui permet de supprimer un plateau
 *
 * \param p : le plateau
 * \return void
 */
void TADPlateau_effacer(Plateau *p);


#endif
