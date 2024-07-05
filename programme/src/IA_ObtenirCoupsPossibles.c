#include <stdlib.h>
#include <stdio.h>
#include "TAD_Plateau.h"
#include "TAD_Pion.h"
#include "TAD_Coups.h"
#include "TAD_Coup.h"
#include "TAD_Position.h"
#include "IA_CoupValide.h"
#include "IA_ObtenirCoupsPossibles.h"

Coups IA_obtenirCoupsPossibles(Plateau p,Couleur couleur_joueur){
	Coups coups_possibles = TADCoups_coups();
	Coup coup;


	// on parcourt l'ensemble des coups du plateau, si un coup est valide, on l'ajoute à la liste
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			if(IA_coupValide(p, TADCoup_coup(TADPion_pion(couleur_joueur, TADPosition_position(i, j))))){
				coup = TADCoup_coup(TADPion_pion(couleur_joueur, TADPosition_position(i, j)));
				TADCoups_ajouterCoup(&coups_possibles, coup);
			}
		}
	}
	return coups_possibles;
}
