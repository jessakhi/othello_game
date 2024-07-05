#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "TAD_Coup.h"
#include "TAD_Pion.h"
#include "TAD_Plateau.h"
#include "IA_CoupValide.h"


/* Partie publique */

Coup TADCoup_coup (Pion pion){
	Coup coup;
	coup.pion = pion;
	return coup;
}

Pion TADCoup_obtenirPion(Coup coup){
	return coup.pion;
}


void TADCoup_jouerCoup(Plateau *p, Coup coup){		
		TADPlateau_placerPion(p,coup.pion);
	}
	





