#include <stdlib.h>
#include <stdio.h>
#include "TAD_Plateau.h"
#include "TAD_Couleur.h"
#include "IA_Score.h"
#include "IA_Evaluer.h"

int IA_evaluer(Plateau p,Couleur couleur_joueur){
    // on soustrait le score du joueur adverse à celui du joueur référence
    return IA_score(p,couleur_joueur) - IA_score(p,TADCouleur_couleurOpposee(couleur_joueur));
}
