#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "TAD_Coups.h"
#include "TAD_Plateau.h"
#include "TAD_Couleur.h"
#include "IA_ObtenirCoupsPossibles.h"
#include "IA_ScoreDUnCoup.h"
#include "IA_ObtenirCoupIA.h"
#include "UNIT_GestionPlateau.h"

Coup IA_obtenirCoupIA(Plateau p,Couleur couleur_joueur_courant,int ligne, char colonne ,unsigned int profondeur){
    Coup coup;
    Coups coups_possibles;
    int score,meilleur_score;
    unsigned int i;

    coups_possibles = IA_obtenirCoupsPossibles(p,couleur_joueur_courant);

    coup = TADCoups_obtenirIEmeCoup(coups_possibles,0);
    
    meilleur_score = IA_scoreDUnCoup(p,coup,couleur_joueur_courant,couleur_joueur_courant,profondeur);
   
    for (i=1;i<(TADCoups_obtenirNbCoups(coups_possibles));i++){
        score = IA_scoreDUnCoup(p,TADCoups_obtenirIEmeCoup(coups_possibles,i),couleur_joueur_courant,couleur_joueur_courant,profondeur);
        if (score>meilleur_score){
            coup = TADCoups_obtenirIEmeCoup(coups_possibles,i);
            meilleur_score = score;
        }
    }
    return coup;
}
