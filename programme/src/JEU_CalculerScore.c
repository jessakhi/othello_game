#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "TAD_Plateau.h"
#include "TAD_Position.h"
#include "TAD_Coup.h"
#include "TAD_Couleur.h"
#include "TAD_Pion.h"
#include "JEU_CalculerScore.h"


void JEU_calculerScore(Plateau pl,unsigned int* score_blanc,unsigned int* score_noir){
	unsigned int TAILLE =8;
	Couleur blanc = TADCouleur_couleur(true); 
	Couleur noir = TADCouleur_couleur(false); 
	Position position;
	*score_blanc = 0;
	*score_noir = 0;

	for(unsigned int i=1; i<TAILLE; i++) {
		for(unsigned int j=1; j<TAILLE; j++) {
			position = TADPosition_position(i,j) ;
			Pion pion = TADPlateau_obtenirPion(pl, position);
			if (TADPion_estPlace(pion)){ 
				if (TADCouleur_couleursIdentiques(TADPion_obtenirCouleur(pion),blanc))
					(*score_blanc)++;
				if (TADCouleur_couleursIdentiques(TADPion_obtenirCouleur(pion),noir))
					(*score_noir)++;
			}
		}
	}
		
}
