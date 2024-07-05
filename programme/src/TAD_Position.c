#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "TAD_Position.h"


Position TADPosition_position(unsigned int ligne, unsigned int colonne){
	Position pos;
	
	pos.ligne = ligne;
	pos.colonne = colonne;
	return pos;
}

unsigned int TADPosition_obtenirLigne(Position pos){
	return pos.ligne;
}

unsigned int TADPosition_obtenirColonne(Position pos){
	return pos.colonne;
}

