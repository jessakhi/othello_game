#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include "TAD_Plateau.h"
#include "TAD_Pion.h"
#include "TAD_Couleur.h"
#include "JEU_FaireUnePartie.h"
#include "UNIT_Tournoi.h"
#include "JEU_TrouverVainqueur.h"
#include "JEU_TrouverEgalite.h"
#include "UNIT_IHM.h"

int main(int argc, char** argv){
	if (argc >= 3){
		Couleur couleur_joueur;
		unsigned int profondeur;
		couleur_joueur = (strcmp(argv[2], "blanc") == 0) ? TADCouleur_couleur(1) : TADCouleur_couleur(0);
		char* zero = "0\0";

		if (argc >= 4){
			profondeur = *argv[3] - *zero;
			if (profondeur <= 2) profondeur = 5; 
		}
		else profondeur = 5;
	

		if(strcmp(argv[1], "standard") == 0 && argc >= 3)   
		JEU_faireUnePartie(couleur_joueur,profondeur);
		else if (strcmp(argv[1], "tournoi") == 0) 
			TO_tournoi(couleur_joueur, profondeur);
		else   
			IHM_aide();
		}
    else{      
        IHM_aide();
	}
	return 0;
}	
