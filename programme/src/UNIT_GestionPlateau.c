#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "TAD_Plateau.h"
#include "TAD_Coup.h"
#include "TAD_Coups.h"
#include "TAD_Position.h"
#include "TAD_Couleur.h"
#include "TAD_Pion.h"
#include "JEU_SeDeplacerDansLaDirection.h"
#include "UNIT_GestionPlateau.h"


Position GP_convertirCoordonneeEnPosition(char str[]){
	int ligne,colonne;
	ligne = atoi((const char*)&str[1]);
	colonne = str[0];
	if(colonne > 96 && colonne < 105) colonne = colonne - 32;
									
	ligne = ligne -1;
	colonne = (int) colonne - 65;
    return(TADPosition_position(ligne,colonne));
}


void GP_afficherPlateau(Plateau p){
	printf("\n\n    A B C D E F G H\n\n");
	for(int i=0; i<8; i++){
		printf("%d   ", i+1); 
		for(int j=0; j<8; j++){
			if(TADPlateau_obtenirPion(p, TADPosition_position(i,j)).estPlace){
				printf("%d ", TADPion_obtenirCouleur(TADPlateau_obtenirPion(p, TADPosition_position(i,j))).couleur);
			}
			else{
				printf("- ");
			}
		}
		printf("\n");
	}
	printf("\n");
}

Plateau GP_initialiserPlateau(){
	Plateau p;
	p = TADPlateau_plateau();
	// pions blancs (1)
	TADPlateau_placerPion(&p, TADPion_pion(TADCouleur_couleur(1), TADPosition_position(3, 3)));
	TADPlateau_placerPion(&p, TADPion_pion(TADCouleur_couleur(1), TADPosition_position(4, 4)));

	// pions noirs (0)
	TADPlateau_placerPion(&p, TADPion_pion(TADCouleur_couleur(0), TADPosition_position(3, 4)));
	TADPlateau_placerPion(&p, TADPion_pion(TADCouleur_couleur(0), TADPosition_position(4, 3)));

	return (p);
}

bool GP_positionInvalide(Position pos){
	return (TADPosition_obtenirColonne(pos) < 0 ||
			TADPosition_obtenirColonne(pos) > 7 ||
			TADPosition_obtenirLigne(pos) < 0 ||
			TADPosition_obtenirLigne(pos) > 7);
}

bool GP_tourJouable(Plateau p, Couleur couleur_joueur){
	for(unsigned int i=0; i<8; i++){
		for(unsigned int j=0; j<8; j++){
			if(!TADPlateau_obtenirPion(p, TADPosition_position(i, j)).estPlace){
				for(unsigned int dir=0; dir<8; dir++){
					if(GP_testerDirection(p, TADPosition_position(i, j), dir, couleur_joueur)){
						return 1;
					}
				}
			}
		}
	}
	return 0;
}

bool GP_testerDirection(Plateau p, Position pos, unsigned int dir, Couleur couleur_joueur) {
	bool directionValide = 0;
		
	do{
		pos = JEU_seDeplacerDansLaDirection(pos, dir);
		if(GP_positionInvalide(pos)){

			return 0;	
		}
		else{
			if (TADCouleur_couleursIdentiques(TADPion_obtenirCouleur(TADPlateau_obtenirPion(p, pos)), couleur_joueur) && TADPlateau_obtenirPion(p, pos).estPlace){
				return 0;
			}
			else{
		if(!TADCouleur_couleursIdentiques(TADPion_obtenirCouleur(TADPlateau_obtenirPion(p, pos)), couleur_joueur) && TADPlateau_obtenirPion(p, pos).estPlace) {
			while(TADPlateau_obtenirPion(p, pos).estPlace && !directionValide && !GP_positionInvalide(pos)) {
				
				
				

				pos = JEU_seDeplacerDansLaDirection(pos, dir);
				if(GP_positionInvalide(pos)){
					return 0;
				}
				if(TADCouleur_couleursIdentiques(TADPion_obtenirCouleur(TADPlateau_obtenirPion(p, pos)), couleur_joueur) && TADPlateau_obtenirPion(p, pos).estPlace){
					directionValide = 1;
				}

			}
		}
		}
		}
	} while(TADPlateau_obtenirPion(p, pos).estPlace && !directionValide);

	return directionValide;
}

void GP_miseAJourPlateau(Plateau *p, Coup coup) {
	bool directionValide;
	Position pos;

	
	for(unsigned int dir=0; dir<8; dir++) {
		pos = TADPion_obtenirPosition(TADCoup_obtenirPion(coup));
		directionValide = GP_testerDirection(*p, pos, dir, TADPion_obtenirCouleur(coup.pion));
		if(directionValide){
			pos = JEU_seDeplacerDansLaDirection(pos, dir);
			while(!TADCouleur_couleursIdentiques(TADPion_obtenirCouleur(TADPlateau_obtenirPion(*p, pos)),TADPion_obtenirCouleur(coup.pion)) && TADPlateau_obtenirPion(*p, pos).estPlace){

				Pion pion = TADPlateau_obtenirPion(*p,pos);
				TADPion_changerCouleur(&pion);
				TADPlateau_placerPion(p,pion);
				
				pos = JEU_seDeplacerDansLaDirection(pos, dir);
			}
		}
	}
}
		

int GP_max(int nb1, int nb2){
	if (nb1>nb2)
	return nb1;
	else
	return nb2;
}

int GP_min(int nb1, int nb2){
	if (nb1<nb2)
	return nb1;
	else
	return nb2;
}

unsigned int GP_nbPionsContigus(Plateau p,Pion pion){
    int resultat;
    bool directionValide;
    Position pos;
    for (unsigned int i=0; i<8;i++){
        directionValide = GP_testerDirection(p, pos, i, TADPion_obtenirCouleur(pion));
		
		while((!TADCouleur_couleursIdentiques(TADPion_obtenirCouleur(TADPlateau_obtenirPion(p, pos)),TADPion_obtenirCouleur(pion))) && directionValide) {
			pos = JEU_seDeplacerDansLaDirection(pos, i);
             resultat =resultat+1;
        }
    }
	return resultat;
	
}
