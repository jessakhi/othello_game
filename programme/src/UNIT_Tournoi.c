#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "TAD_Couleur.h"
#include "JEU_TesterFin.h"
#include "TAD_Coups.h"
#include "IA_ObtenirCoupIA.h"
#include "JEU_ObtenirCoupH.h"
#include "IA_ObtenirCoupsPossibles.h"
#include "JEU_Jouer.h"
#include "UNIT_IHM.h"
#include "TAD_Coup.h"
#include "JEU_TrouverEgalite.h"
#include "UNIT_GestionPlateau.h"
#include "JEU_TrouverVainqueur.h"


// fonction pour lancer le couleur_joueur_courantnoi
void TO_tournoi(Couleur couleur_choisie, unsigned int profondeur){
	Plateau p = GP_initialiserPlateau();
    bool a_nous_de_jouer = !(TADCouleur_couleursIdentiques(TADCouleur_couleur(1),couleur_choisie));
    Position pos;
    Coup coup;
    bool coup_possible = true;
    bool coup_possible_precedent;
    Couleur vainqueur;
    bool egalite;
    Pion pion;
    char saisie[7];
	
    while(true){
        if (a_nous_de_jouer) {
                coup_possible_precedent = coup_possible;
				coup_possible = GP_tourJouable(p,couleur_choisie);
            if (coup_possible){

				coup = IA_obtenirCoupIA(p,couleur_choisie,0,0,profondeur);
				JEU_jouer(&p,couleur_choisie,IA_obtenirCoupIA,0,0,profondeur);
                printf("%c%d\n",TADPosition_obtenirColonne(TADPion_obtenirPosition(TADCoup_obtenirPion(coup))) + 'a',
                        TADPosition_obtenirLigne(TADPion_obtenirPosition(TADCoup_obtenirPion(coup)))+1);
            }
            else {
                if (coup_possible_precedent)
                    printf("passe\n");
                else{
              		egalite = JEU_trouverEgalite(&p);
                    vainqueur = *JEU_trouverVainqueur(&p);
                    if (egalite)
                        printf("nulle\n");
                    else
                        printf((TADCouleur_couleursIdentiques(vainqueur,TADCouleur_couleur(1))) ? "blanc\n" : "noir\n");
                }
            }
        }
        else{
            scanf("%s",saisie);
            if (strcmp(saisie, "passe\n") != 0){ //s'il ne passe pas son tour
                pos = GP_convertirCoordonneeEnPosition(saisie);
                pion = TADPion_pion(TADCouleur_couleurOpposee(couleur_choisie), pos);
                coup = TADCoup_coup(pion);
                TADCoup_jouerCoup(&p,coup);
                GP_miseAJourPlateau(&p,coup);
            
            }
        }

        fflush(stdout);
        a_nous_de_jouer = !a_nous_de_jouer;
        
    }
}