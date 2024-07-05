/**
 * \file TAD_Position.h
 * \brief Implementation du TAD Position pour le jeu d'Othello
 * \author Charles Foyer Benchekroun Essakhi
 * \version 1.0
 * \date 11/12/2022
 *
 */

#ifndef  __POSITION__
#define __POSITION__

/**
 * \brief Le type Position permet de représenter une position
 *
 */
 
typedef struct {

   unsigned int ligne;
   unsigned int colonne; 

  } Position;

/**
 * \fn TADPosition_position(unsigned int l,unsigned int c)
 * \brief Fonction de création d'une position
 *
 * \param l : la ligne
 * \param c : la colonne
 * \return Position
 */
Position TADPosition_position(unsigned int ligne , unsigned int colonne);

/**
 * \fn TADPosition_pobtenirligne(Position p)
 * \brief Fonction qui permet de retourner la ligne d'une position
 *
 * \param p : la position
 * \return unsigned int
 */
unsigned int TADPosition_obtenirLigne(Position p);

/**
 * \fn TADPosition_pobtenircolonne(Position p)
 * \brief Fonction qui permet de retourner la lcolonne d'une position
 *
 * \param p : la position
 * \return unsigned int
 */
unsigned int TADPosition_obtenirColonne(Position p);

#endif
