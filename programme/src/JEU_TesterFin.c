#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "TAD_Plateau.h"
#include "TAD_Couleur.h"
#include "TAD_Coups.h"
#include "IA_ObtenirCoupsPossibles.h"
#include "JEU_TesterFin.h"
#include "UNIT_GestionPlateau.h"

bool JEU_testerFin(Plateau p){
	// si le plateau est plein ou que le joueur noir ne peut pas jouer, c'est fini
	if(TADPlateau_estPlein(p) || (!GP_tourJouable(p, TADCouleur_couleur(1))))
			return 1;
		// si le joueur blanc ne peut pas jouer non plus, c'est fini
		else if (!GP_tourJouable(p, TADCouleur_couleur(0)))
			return 1;
			// sinon ce n'est pas fini
		else 
		        return 0; 
}
