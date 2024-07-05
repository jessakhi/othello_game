/**
 * \file UNIT_GestionPlateau.h
 * \brief Implementation de toutes les procédures et fonction de gestion du plateau
 * \author Charles Foyer Benchekroun Essakhi
 * \version 1.0
 * \date 22/12/2022
 *
 */
#ifndef __GESTION_PLATEAU__
#define __GESTION_PLATEAU__
#include "TAD_Plateau.h"
#include "TAD_Couleur.h"
#include "TAD_Position.h"
#include "TAD_Pion.h"
#include "TAD_Coup.h"
#include <stdbool.h>
/**
 * \fn GP_convertirCoordonneeEnPosition(char coord[])
 * \brief Fonction qui converti les coordonnées entrées en Position
 *
 * \param coord : les coordonnées
 * \return Position
 */
Position GP_convertirCoordonneeEnPosition(char str[]);

/**
 * \fn GP_initialiserPlateau()
 * \brief Fonction d'initialisation du plateau
 * \return Plateau
 */
Plateau GP_initialiserPlateau();
/**
 * \fn GP_testerDirection(Plateau p, Position pos, unsigned int dir, Couleur c)
 * \brief qui permet de tester si la direction est valide
 *
 * \param p : le plateau
 * \param pos : la position
 * \param dir : la direction
 * \param c : la couleur
 * \return bool
 */

bool GP_positionInvalide(Position pos);


/**
 * \fn GP_tourJouable(Plateau p, Couleur couleur_joueur)
 * \brief permet d'indiquer si un joueur peu placer un pion ou non lorsqu'il est censé jouer
 *
 * \param p : le plateau
 * \param couleur_joueur : la couleur du joueur courant

 * \return bool
 */
bool GP_tourJouable(Plateau p, Couleur couleur_joueur);

/**
 * \fn GP_testerDirection(Position p)
 * \brief permet d'indiquer si une position est invalide (en dehors du plateau)
 *
 * \param c : la position
 * \return bool
 */
bool GP_testerDirection(Plateau p, Position pos, unsigned int dir, Couleur c);
/**
 * \fn GP_miseAJourPlateau(Plateau *p, Coup coup)
 * \brief Procédure de mise à jour du plateau
 *
 * \param p : le Plateau
 * \param coup : le coup
 * \return void
 */
void GP_miseAJourPlateau(Plateau *p, Coup coup);
/**
 * \fn GP_nbPionsContigus(Plateau *p, Coup coup)
 * \brief Fonction qui retourne le nombre de pions contigus à un pion 
 *
 * \param p : le Plateau
 * \param pion : le pion
 * \return unsigned int
 */
unsigned int GP_nbPionsContigus(Plateau p,Pion pion);
/**
 * \fn GP_max(int nb1, int nb2)
 * \brief Fonction qui retourne le maximum de deux entiers 
 *
 * \param nb1 : un entier
 * \param nb2 : un autre entier
 * \return int
 */
int GP_max(int nb1, int nb2);
/**
 * \fn GP_min(int nb1, int nb2)
 * \brief Fonction qui retourne le minimum de deux entiers 
 *
 * \param nb1 : un entier
 * \param nb2 : un autre entier
 * \return int
 */
int GP_min(int nb1, int nb2);

/**
 * \fn GP_afficherPlateau(Plateau p)
 * \brief Procédure qui affiche le plateau
 *
 * \param p : le Plateau
 * \return void
 */
void GP_afficherPlateau(Plateau p);

#endif
