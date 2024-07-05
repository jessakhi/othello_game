#include <stdlib.h>
#include <stdio.h>
#include "TAD_Position.h"
#include "JEU_SeDeplacerDansLaDirection.h"

Position JEU_seDeplacerDansLaDirection(Position pos, unsigned int dir) {
	int dirLigne[8] = {-1,-1,0,1,1,1,0,-1};
	int dirColonne[8] = {0,1,1,1,0,-1,-1,-1};
	
	Position position = TADPosition_position(TADPosition_obtenirLigne(pos)+dirLigne[dir], TADPosition_obtenirColonne(pos)+dirColonne[dir]);
	return position;
}
