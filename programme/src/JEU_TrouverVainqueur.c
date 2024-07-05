#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "TAD_Plateau.h"
#include "TAD_Position.h"
#include "TAD_Coup.h"
#include "IA_CoupValide.h"
#include "UNIT_GestionPlateau.h"
#include "IA_Score.h"
#include "JEU_TrouverVainqueur.h"
#include "JEU_CalculerScore.h"
        		
Couleur* JEU_trouverVainqueur(Plateau* pl) {
	unsigned int TAILLE = 8;
	int* egalite = (int*)malloc(sizeof(int));
	Couleur* vainqueur = (Couleur*)malloc(sizeof(Couleur)*TAILLE*TAILLE);
	unsigned int score_blanc, score_noir;
	JEU_calculerScore(*pl,&score_blanc,&score_noir);
	*egalite = (score_blanc==score_noir);

	if ((*egalite)){
		*vainqueur = TADCouleur_couleur(true) ;
	} 
	if (!(*egalite)){
		if (score_blanc>score_noir) {
			*vainqueur = TADCouleur_couleur(true);
		} else {
			*vainqueur = TADCouleur_couleur(false);
		}
	}
	return vainqueur;
}




