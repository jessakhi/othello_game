#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "TAD_Plateau.h"
#include "TAD_Pion.h"
#include "TAD_Position.h"
#include "TAD_Coups.h"



/* Partie publique */

Plateau TADPlateau_plateau(){
	Plateau p;
	unsigned int TAILLE;
	TAILLE = 8;
	p.estPlein = false;
	p.nbPionsPlaces = 0;
	
	for (int i=0; i<TAILLE; i++) {
		for (int j=0; j<TAILLE; j++) {
		        p.lesPions[i][j].couleur = TADCouleur_couleur(0);
		        p.lesPions[i][j].estPlace = 0;
		        p.lesPions[i][j].position = TADPosition_position(i,j);
		}
	}
	return (p);
}


bool TADPlateau_estPlein(Plateau p){
	unsigned int TAILLE;
	TAILLE = 8;
	for(int i=0; i<TAILLE; i++){
		for(int j=0; j<TAILLE; j++){
			if(!TADPlateau_obtenirPion(p, TADPosition_position(i, j)).estPlace){
				return 0;
			}
		}
	}
	return 1;
}

Pion TADPlateau_obtenirPion(Plateau p, Position pos) {
	 Pion pion = p.lesPions[TADPosition_obtenirLigne(pos)][TADPosition_obtenirColonne(pos)];
	return pion;
}

void TADPlateau_placerPion(Plateau *p, Pion pion){
	int ligne,colonne;
	ligne = TADPosition_obtenirLigne(pion.position);
	colonne = TADPosition_obtenirColonne(pion.position);
	p->lesPions[ligne][colonne].estPlace = 1;
	p->lesPions[ligne][colonne].couleur = pion.couleur;	
	p->nbPionsPlaces = p->nbPionsPlaces + 1; 
}

/* fonctions liées à l'utilisation de l'allocation dynamique */
/*Plateau* TADPlateau_copier(Plateau *p){
	Plateau* copie;
	unsigned int TAILLE;
	TAILLE = 8;
	Plateau cp = TADPlateau_plateau();
	
	copie = &cp;
	for(int i=0; i<TAILLE; i++){
		for(int j=0; j<TAILLE; j++){
		        if (TADPion_estPlace(*(p->lesPions[i][j]))){
			//copie->lesPions[i][j]=p->lesPions[i][j];
			memmove(copie->lesPions[i][j],p->lesPions[i][j],sizeof(Pion)*TAILLE*TAILLE);
			   }
			}
		}
	
	
	return copie;
}*/

void TADPlateau_copier(Plateau p,Plateau *copie){
	//Plateau copie = TADPlateau_plateau();
	for(int ligne = 0;ligne <8;ligne++){
		for(int colonne = 0;colonne <8;colonne++){
			copie->lesPions[ligne][colonne].estPlace = p.lesPions[ligne][colonne].estPlace;
			copie->lesPions[ligne][colonne].couleur = p.lesPions[ligne][colonne].couleur;
		}
	}

	//return copie;
}




bool TADPlateau_memePlateau(Plateau p1, Plateau p2){
	bool res;
	unsigned int TAILLE;
	unsigned int i,j;
	Position pos;
	TAILLE = 8;
    res= true;
    i=0;
    j=0;
    pos = TADPosition_position(i,j);
    while ((res==1) && (j<=TAILLE)) {
      if (!TADCouleur_couleursIdentiques(TADPion_obtenirCouleur(TADPlateau_obtenirPion(p1,pos)),TADPion_obtenirCouleur(TADPlateau_obtenirPion(p2,pos))))
	       res=0;
	       
      else {
	i++;
	if (i>TAILLE) {
	  j++;
	  i=1;
	  }
	  
	}
	    
 } 
	return res;
}

void TADPlateau_effacer(Plateau* p) {
unsigned int TAILLE = 8;
for(int i=0; i<TAILLE; i++){
		for(int j=0; j<TAILLE; j++){
			//free(p->lesPions[i][j]);
			
		}
	}
	//free(p);
}    
