#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "TAD_Coups.h"


/* Fonctions de Liste Coups (privées)*/

void ListeCoups_ajouterCoup(ListeCoups *liste_coups, Coup c){
	ListeCoups noeud = (ListeCoups) malloc (sizeof(Ncoups));

	ListeCoups_fixerCoup(&noeud, c);
	ListeCoups_fixerListeSuivante(noeud, *liste_coups);
	*liste_coups = noeud;
}
/*----------------------------------*/
void ListeCoups_supprimerCoup(ListeCoups *liste_coups){
	ListeCoups liste_coups_temp = *liste_coups;
	*liste_coups = ListeCoups_obtenirListeSuivante(*liste_coups);
	free(liste_coups_temp);
}
/*----------------------------------*/
void ListeCoups_supprimerIEmeCoupRecursif(ListeCoups *liste_coups, unsigned int i){
	if(i == 0){
		ListeCoups_supprimerCoup(liste_coups);
	}
	else{
		ListeCoups liste_coups_suivante = ListeCoups_obtenirListeSuivante(*liste_coups);
		ListeCoups_supprimerIEmeCoupRecursif(&liste_coups_suivante, i-1);
	}
}
/*----------------------------------*/
Coup ListeCoups_obtenirCoup(ListeCoups liste_coups){
	return liste_coups->coup;
}
/*----------------------------------*/
void ListeCoups_fixerCoup(ListeCoups *liste_coups, Coup c){
	(*liste_coups)->coup = c;
}
/*----------------------------------*/
ListeCoups ListeCoups_obtenirListeSuivante(ListeCoups liste_coups){
	return (*liste_coups).listeSuivante;
}
/*----------------------------------*/
void ListeCoups_fixerListeSuivante(ListeCoups liste_coups, ListeCoups liste_coups_suivante){
	(*liste_coups).listeSuivante = liste_coups_suivante;
}


/*----------------------------------*/
/*----------------------------------*/


/* Fonctions de Coups (publiques) */
void TADCoups_fixerNbCoups(Coups *coups, unsigned int nb_coups){
	(*coups).nbCoups = nb_coups;
}
/*----------------------------------*/
void TADCoups_fixerListeCoups(Coups *coups, ListeCoups l){
	(*coups).listecoups  = l;
}
/*----------------------------------*/
unsigned int TADCoups_obtenirNbCoups(Coups coups){
	return coups.nbCoups ;	
}
/*----------------------------------*/
Coups TADCoups_coups (){
	Coups coups;
	/* on fixe le nombre de coups à l'origine à 0*/
	TADCoups_fixerNbCoups(&coups,0);
	/*on initialise la liste de coups à la liste vide*/
	coups.listecoups = NULL;
	return coups;
}
/*----------------------------------*/
ListeCoups *TADCoups_obtenirListeCoups(Coups *coups){
    return &(coups->listecoups);
}
/*----------------------------------*/
void TADCoups_ajouterCoup(Coups *coups, Coup coup){

	ListeCoups_ajouterCoup(TADCoups_obtenirListeCoups(coups),coup);
	TADCoups_fixerNbCoups(coups,TADCoups_obtenirNbCoups(*coups) + 1);
}
/*----------------------------------*/
bool TADCoups_estVide (Coups coups){
	return (coups.listecoups == NULL);
}
/*----------------------------------*/
Coup TADCoups_obtenirIEmeCoup(Coups coups, unsigned int i){
	/* on vérifie la précondition */
	assert(TADCoups_obtenirNbCoups(coups) >= i);
	
	// et on démarre la récursivité
	return TADCoups_obtenirIEmeCoupRecursif(*TADCoups_obtenirListeCoups(&coups), i);
}
/*----------------------------------*/
Coup TADCoups_obtenirIEmeCoupRecursif(ListeCoups liste_coups,unsigned int i){
	/* si i vaut 0 c'est qu'on est à l'élément qu'on cherche*/
	if(i == 0){
		return ListeCoups_obtenirCoup(liste_coups);
	}
	/* sinon on obtient la liste suivante en diminuant i*/
	else{
		return TADCoups_obtenirIEmeCoupRecursif(ListeCoups_obtenirListeSuivante(liste_coups), i-1);
	}
}
