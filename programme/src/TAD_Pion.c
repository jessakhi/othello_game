#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "TAD_Pion.h"
#include "TAD_Couleur.h"


/* Partie publique */

Pion TADPion_pion(Couleur couleur, Position pos){
	Pion pion;
	pion.position = pos;
	pion.couleur = couleur;
	pion.estPlace = 0;
	return pion;
}



		
Position TADPion_obtenirPosition(Pion pion){
	return pion.position;
}

bool TADPion_estPlace(Pion p) {
    return p.estPlace;
}

Couleur TADPion_obtenirCouleur(Pion pion){
	return pion.couleur;
}

void TADPion_changerCouleur(Pion *pion){
	
	if(TADPion_obtenirCouleur(*pion).couleur == TADCouleur_couleur(0).couleur){
		 pion->couleur = TADCouleur_couleur(1);
	}
	else{
		 pion->couleur = TADCouleur_couleur(0);
	}
	
}

void TADPion_fixerCouleur(Pion *pion,Couleur couleur){
	pion->couleur = couleur;
}

void TADPion_placerPion(Pion pion){
	pion.estPlace = true;
}


