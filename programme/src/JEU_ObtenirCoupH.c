#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "JEU_ObtenirCoupH.h"
#include "TAD_Plateau.h"
#include "TAD_Pion.h"
#include "TAD_Couleur.h"
#include "TAD_Position.h"
#include "TAD_Coup.h"

Coup JEU_obtenirCoupH(Plateau p,Couleur couleur_joueur, int ligne, char colonne, unsigned int profondeur ){
    Coup coup;

    // on crée le coup choisi par le joueur humain
    coup = TADCoup_coup(TADPion_pion(couleur_joueur,TADPosition_position(ligne,colonne)));
    return coup;
} 
