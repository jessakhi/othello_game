#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include "TAD_Plateau.h"
#include "TAD_Coup.h"
#include "TAD_Couleur.h"
#include "IA_Evaluer.h"
#include "IA_MinMax.h"
#include "UNIT_GestionPlateau.h"
#include "IA_ScoreDUnCoup.h"

int IA_scoreDUnCoup(Plateau p,Coup coup, Couleur couleur_joueur_referent,Couleur couleur_joueur_courant, unsigned int profondeur){
	Plateau copie_plateau = TADPlateau_plateau();
	TADPlateau_copier(p,&copie_plateau);
	// on copie le plateau pour ne pas le modifier

	TADCoup_jouerCoup(&copie_plateau,coup);
	GP_miseAJourPlateau(&copie_plateau,coup);

	

	if ( TADPlateau_estPlein(copie_plateau) || profondeur <= 0){
		int evaluation =  IA_evaluer(copie_plateau,couleur_joueur_referent);
		return evaluation;

	}
	 else{
		return IA_minMax(copie_plateau,couleur_joueur_referent,TADCouleur_couleurOpposee(couleur_joueur_courant),profondeur-1);
	} 
}

