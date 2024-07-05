#include <stdlib.h>
#include <stdio.h>
#include "TAD_Couleur.h"
#include "TAD_Plateau.h"
#include "TAD_Coups.h"
#include "IA_MinMax.h"
#include "IA_ObtenirCoupsPossibles.h"
#include "IA_ScoreDUnCoup.h"
#include "UNIT_GestionPlateau.h"

int IA_minMax(Plateau p,Couleur couleur_joueur_referent,Couleur couleur_joueur_courant, unsigned int profondeur){
	Coups coups_possibles;
	int score,nb_coups_possibles,resultat;
	unsigned int i;


	coups_possibles = IA_obtenirCoupsPossibles(p,couleur_joueur_courant);
	nb_coups_possibles = TADCoups_obtenirNbCoups(coups_possibles);


	
	resultat = IA_scoreDUnCoup(p,TADCoups_obtenirIEmeCoup(coups_possibles,0),couleur_joueur_referent,couleur_joueur_courant,profondeur);

	for (i = 1;i<nb_coups_possibles;i++){
		score = IA_scoreDUnCoup(p,TADCoups_obtenirIEmeCoup(coups_possibles,i),couleur_joueur_referent,couleur_joueur_courant,profondeur);
		if (TADCouleur_couleursIdentiques(couleur_joueur_courant,couleur_joueur_referent)){
			resultat = GP_max(resultat,score);
		}
		else{
			resultat = GP_min(resultat,score);
		}
		
	}
	
	return resultat;
	
}


