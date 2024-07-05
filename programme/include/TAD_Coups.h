/**
 * \file TAD_Coups.h
 * \brief Implementation du TAD Coups pour le jeu d'Othello
 * \author Charles Foyer Benchekroun Essakhi
 * \version 1.0
 * \date 11/12/2022
 *
 */

#ifndef __COUPS__
#define __COUPS__
#include "TAD_Coup.h"



/* structures */
/**
 * \brief Le type ListesCoups est un pointeur sur des noeud de coups 
 *
 */
typedef struct Ncoups* ListeCoups;
/**
 * \brief Le type Ncoups est un noeud de coups qui sera utilisé pour representer le type ListeCoups
 *
 */
typedef struct Ncoups {
	Coup coup;
	ListeCoups listeSuivante;
}Ncoups;



/**
 * \brief Le type Coups est une Liste de coups  
 *
 */
typedef struct {
	unsigned int nbCoups;
	ListeCoups listecoups;
}Coups;

/* Headers des fonctions de Liste Coups (privées) */


/**
 * \fn ListeCoups_ajouterCoup(ListeCoups *liste_coups, Coup c)
 * \brief Procedure d'ajout d'un coup à une liste de coups
 *
 * \param *liste_coups : la liste de coups
 * \param c : le coup à ajouter
 * \return void
 */

void ListeCoups_ajouterCoup(ListeCoups *liste_coups, Coup c);

/**
 * \fn  ListeCoups_supprimerCoup(ListeCoups *liste_coups);
 * \brief Procedure de suppression de coups
 * \param *liste_coups : la liste de coups
 * \return void
 */
void ListeCoups_supprimerCoup(ListeCoups *liste_coups);

/**
 * \fn  ListeCoups_supprimerIEmeCoup(ListeCoups *liste_coups, unsigned int i)
 * \brief Procedure de suppression du ieme coup
 *
 * \param *liste_coups : la liste de coups
 * \param i : indice du ieme coup
 * \return void
 */
void ListeCoups_supprimerIEmeCoupRecursif(ListeCoups *liste_coups, unsigned int i);

/**
 * \fn  ListeCoups_obtenirCoup(ListeCoups liste_coups)
 * \brief Fonction qui retourne un coup
 *
 * \param *liste_coup : la liste de coups
 * \return Coup
 */
Coup ListeCoups_obtenirCoup(ListeCoups liste_coups);

/**
 * \fn  ListeCoups_fixerCoup(ListeCoups liste_coups, Coup c)
 * \brief Procedure qui fixe un coup à la suite de la liste
 * \param liste_coups : la liste de coups
 * \param c: le coup
 * \return void
 */
void ListeCoups_fixerCoup(ListeCoups* liste_coups, Coup c);

/**
 * \fn  ListeCoups_obtenirListeSuivante(ListeCoups liste_coups)
 * \brief Fonction qui permet d'obtenir la liste suivante de coups
 *
 * \param liste_coups : la liste de coups
 * \return ListeCoups
 */
ListeCoups ListeCoups_obtenirListeSuivante(ListeCoups liste_coups);

/**
 * \fn  ListeCoups_fixerListeSuivante(ListeCoups liste_coups, ListeCoups liste_coups_suivante)
 * \brief Procedure qui fixe la liste suivante
 *
 * \param liste_coups : la liste de coups
 * \param liste_coups_suivante: la liste à fixer
 * \return void
 */
void ListeCoups_fixerListeSuivante(ListeCoups liste_coups, ListeCoups liste_coups_suivante);

/**
 * \fn  TADCoups_coups()
 * \brief Fonction qui creer un historique de Coups vide
 *
 * \return Coups
 */
Coups TADCoups_coups();

/* Headers des fonctions de Coups (publiques) */
/**
 * \fn  TADCoups_fixerNbCoups(Coups *coups, unsigned int nb_coups)
 * \brief Procedure qui fixe le nombre de coups
 *
 * \param coups : l'historique de coups
 * \param nb_coups: le nombre de coups
 * \return void
 */
void TADCoups_fixerNbCoups(Coups *coups, unsigned int nb_coups);

/**
 * \fn  TADCoups_fixerListeCoups(Coups *coups, ListeCoups l)
 * \brief Procedure qui fixe lea liste de coups dans l historique de coups
 *
 * \param coups : l'historique de coups
 * \param nb_coups: le nombre de coups
 * \return void
 */
unsigned int TADCoups_obtenirNbCoups(Coups coups);

/**
 * \fn  TADCoups_obtenirNbCoups(Coups coups)
 * \brief Procedure qui permet d'obtenir le nombre de coups contenus dans un 'Coups'
 *
 * \param coups : l'historique de coups
 * \return unsigned int
 */
void TADCoups_fixerListeCoups(Coups *coups, ListeCoups l);

/**
 * \fn  Coups TADCoups_coups ()
 * \brief Fonction qui creer un historique de Coups vide
 *
 * \return Coups
 */
Coups TADCoups_coups ();

/**
 * \fn  ListeCoups *TADCoups_obtenirListeCoups(Coups *coups)
 * \brief Fonction qui permet d'obtenir la liste des coups contenu dans un "coups"
 * \param coups : l'historique de coups dont on veut la liste
 * \return ListeCoups
 */
ListeCoups *TADCoups_obtenirListeCoups(Coups *coups);

/**
 * \fn  void TADCoups_ajouterCoup (Coups *coups, Coup coup)
 * \brief Fonction qui ajoute un coup a l'historique de coups
 *
 * \param coups : l'historique
 * \param coup : le coup
 */
void TADCoups_ajouterCoup(Coups *coups, Coup coup);

/**
 * \fn  CTADCoups_estVide (Coups coups)
 * \brief Fonction qui verifie si l'historique des coups est vide
 *
 * \param coups : l'historique
 * \return bool
 */
bool TADCoups_estVide (Coups coups);

/**
 * \fn  TADCoups_obtenirIEmeCoup(Coups coups, unsigned int i)
 * \brief Fonction qui ajoute un coup a l'historique de coups à l indice i 
 *
 * \param coups : l'historique
 * \param i : l'indice
 * \return Coups
 */
Coup TADCoups_obtenirIEmeCoup(Coups coups, unsigned int i);

/**
 * \fn  TADCoups_obtenirIEmeCoup(Coups coups, unsigned int i)
 * \brief Fonction qui ajoute un coup a la liste de couos à l indice i recursivement 
 *
 * \param liste_coups : liste des coups
 * \param i : l'indice
 * \return Coups
 */
Coup TADCoups_obtenirIEmeCoupRecursif(ListeCoups liste_coups,unsigned int i);

#endif
