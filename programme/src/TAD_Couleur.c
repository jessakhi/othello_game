#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "TAD_Couleur.h"
#include "TAD_Pion.h"


Couleur TADCouleur_couleur(bool param){
	Couleur couleur;
    
	/* si param est 0 c'est noir, sinon blanc */
	couleur.couleur = param;
	return couleur;
}

Couleur TADCouleur_couleurOpposee(Couleur couleur){
    Couleur couleurOpposee;

    couleurOpposee.couleur = !couleur.couleur;
    return couleurOpposee;
}

bool TADCouleur_couleursIdentiques(Couleur couleur1,Couleur couleur2){
    return (couleur1.couleur == couleur2.couleur);
}

char* TADCouleur_afficherCouleur(Couleur couleur){
    if (couleur.couleur == 1)
        return "blanc";
    else
        return "noir";
}
