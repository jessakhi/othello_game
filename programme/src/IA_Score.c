#include <stdlib.h>
#include <stdio.h>
#include <TAD_Plateau.h>
#include <TAD_Couleur.h>
#include <IA_Score.h>

int IA_score(Plateau p,Couleur couleur_joueur){
	int score = 0;
	int colonne,ligne;
	Pion pion;
	Couleur couleur;
	Position position;

	// boucle sur la largeur
	for (colonne = 0;colonne<=7;colonne++){
		// boucle sur la hauteur
		for (ligne = 0;ligne<=7;ligne++){
			position = TADPosition_position(ligne,colonne);
			pion = TADPlateau_obtenirPion(p,position);
			couleur = TADPion_obtenirCouleur(pion);
			// si la couleur du pion est la couleur du joueur passée en entrée, on ajoute 1 au score
			if (TADCouleur_couleursIdentiques(couleur,couleur_joueur) && pion.estPlace){
				score = score + 1;
			}
		}
	}
	return score;
    
}
