#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "TAD_Plateau.h"
#include "TAD_Position.h"
#include "TAD_Coup.h"
#include "IA_CoupValide.h"
#include "UNIT_GestionPlateau.h"

bool IA_coupValide(Plateau p, Coup coup){
	Position pos = TADPion_obtenirPosition(TADCoup_obtenirPion(coup));
	bool valide = false;
	int i = 0;

	// on vérifie que le pion n'est pas déjà placé, sinon on rentre dans la boucle
	if (TADPlateau_obtenirPion(p,coup.pion.position).estPlace || GP_positionInvalide(pos))
		valide = false;
	else{
		// on parcourt toutes les directions pour vérifier que le coup est valide dans toutes les directions
		while(!valide && i<8){
			valide = GP_testerDirection(p, pos, i, coup.pion.couleur);
			i++;
		}
	}
	return valide;
}
