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

        		
bool* JEU_trouverEgalite(Plateau* pl){
	bool* egalite = (bool*)malloc(sizeof(bool));
	unsigned int score_blanc, score_noir;
	
	JEU_calculerScore(*pl,&score_blanc,&score_noir);
	*egalite = (score_blanc==score_noir);
    return egalite;
}
