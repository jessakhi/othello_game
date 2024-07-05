#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "TAD_Plateau.h"
#include "TAD_Couleur.h"
#include "TAD_Coups.h"
#include "TAD_Coup.h"
#include "JEU_ObtenirCoupH.h"
#include "IA_ObtenirCoupsPossibles.h"
#include "IA_CoupValide.h"
#include "UNIT_GestionPlateau.h"
#include "JEU_Jouer.h"


// ici *obtenirCoup permet d'obtenir un pointeur de fonction de type obtenirCoup, pour utiliser obtenirCoupH ou obtenirCoupIA selon le contexte
void JEU_jouer(Plateau *p,Couleur couleur_joueur_courant,Coup (*obtenirCoup)(Plateau,Couleur,int,char, unsigned int /* la profondeur */),int ligne, char colonne,unsigned int profondeur){
    Coup coup_joue;
    
    // si le tour est jouable on agit normalement, sinon on saute le tour
    if(GP_tourJouable(*p, couleur_joueur_courant)){
        coup_joue = obtenirCoup(*p,couleur_joueur_courant,ligne,colonne,profondeur);
        TADCoup_jouerCoup(p,coup_joue);
        GP_miseAJourPlateau(p,coup_joue);
    }
    else{
        printf("MASTER : Tour sauté !\n");
    }
}
