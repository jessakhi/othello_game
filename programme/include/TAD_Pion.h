/**
 * \file TAD_Pion.h
 * \brief Implementation du TAD Pion pour le jeu d'Othello
 * \author Charles Foyer Benchekroun Essakhi
 * \version 1.0
 * \date 11/12/2022
 *
 */

#ifndef __PION__
#define __PION__
#include <stdbool.h>
#include "TAD_Position.h"
#include "TAD_Couleur.h"

/**
 * \brief Le type Pion permet de représenter un pion à partir de sa couleur et sa position
 *
 */
typedef struct {
  Position position;
  Couleur couleur; 
  bool estPlace;
} Pion;

/**
 * \fn TADPion_pion(unsigned int ligne, unsigned int colonne)
 * \brief Fonction de création d'un pion
 *
 * \param ligne : la ligne
 * \param colonne : la colonne
 * \return Pion
 */
Pion TADPion_pion(Couleur couleur, Position pos);

/**
 * \fn TADPion_obtenirPosition(Position pos)
 * \brief Fonction qui permet de retourner la position d'un poin
 *
 * \param p : la position
 * \return Position
 */
Position TADPion_obtenirPosition(Pion pion);

/**
 * \fn Couleur TADPion_obtenirCouleur(Pion pion)
 * \brief Fonction qui permet de retourner la couleur d'un poin
 *
 * \param p : la position
 * \return Couleur
 */
Couleur TADPion_obtenirCouleur(Pion pion);

/**
 * \fn TADPion_changerCouleur(Pion pion)
 * \brief Procedure qui permet de changer la couleur d'un pion
 *
 * \param pion : le pion
 * \return Pion
 */
void TADPion_changerCouleur(Pion* pion);

/**
 * \fn TADPion_estPlace(Pion pion)
 * \brief Fonction qui permet de savoir si un pion est placé
 *
 * \param pion : le pion
 * \return bool
 */
bool TADPion_estPlace(Pion pion);

/**
 * \fn TADPion_fixerCouleur(Pion *pion, Couleur couleur)
 * \brief Procédure pour fixer la couleur d'un pion
 *
 * \param pion : le pion
 * \param couleur : la couleur à fixer
 */
void TADPion_fixerCouleur(Pion *pion, Couleur couleur);

/**
 * \fn TADPion_placerPion(Pion pion)
 * \brief Procédure qui permet d'indiquer au programme que le pion a été placé
 *
 * \param pion : le pion
 */
void TADPion_placerPion(Pion pion);


#endif

