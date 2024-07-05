#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "TAD_Plateau.h"
#include "TAD_Couleur.h"
#include "TAD_Coup.h"
#include "JEU_TesterFin.h"
#include "IA_ScoreDUnCoup.h"
#include "IA_ObtenirCoupIA.h"
#include "JEU_FaireUnePartie.h"
#include "IA_CoupValide.h"
#include "JEU_ObtenirCoupH.h"
#include "JEU_Jouer.h"
#include "UNIT_IHM.h"
#include "UNIT_GestionPlateau.h"
#include "UNIT_GestionPlateau.c"
#include "JEU_TrouverEgalite.h"
#include "JEU_TrouverVainqueur.h"

void JEU_faireUnePartie(Couleur couleur_choisie,unsigned int profondeur){
    Plateau p;    
    Couleur *vainqueur;
    bool egalite;


    // compteur de tour
    int nb_tour = 0;


    // on initialise la couleur du joueur avec la couleur choisie
    Couleur couleur_joueur_humain,couleur_joueur_courant;
    couleur_joueur_humain = couleur_choisie;


    // l'humain commence
    couleur_joueur_courant = couleur_joueur_humain;
    p = GP_initialiserPlateau();



    IHM_gras("Vous commencez !\n");
    while (!JEU_testerFin(p)){
        nb_tour = nb_tour + 1;

        IHM_separateur();
        printf("Tour numéro : %d\n",nb_tour);
        printf("C'est au joueur %s de jouer !\n",TADCouleur_afficherCouleur(couleur_joueur_courant)); 
    	GP_afficherPlateau(p);
    
          
          
        // si c'est l'humain qui joue
        int ligne;
        char colonne;
        char str[2];

        if(TADCouleur_couleursIdentiques(couleur_joueur_courant,couleur_joueur_humain)){
            IHM_gras("A vous de jouer !\n");
            do{
                do{
                    IHM_gras("Quel coup voulez-vous jouer ? \nEntrez une lettre suivie d'un chiffre :  ");
                    scanf("%s", str);

                    ligne = atoi((const char*)&str[1]);
                    colonne = str[0];
                    if(colonne > 96 && colonne < 105) colonne = colonne - 32;
                                                    
                    ligne = ligne -1;
                    colonne = (int) colonne - 65;
                    if (ligne < 0 || ligne > 7 || colonne < 0 || colonne > 7)
                        IHM_gras("<!> Coup non valide, réessayez !\n");
	            }while(ligne < 0 || ligne > 7 || colonne < 0 || colonne > 7); 

                // tant que le coup passé en entrée n'est pas valide, on continue à demander d'entrer un coup
                if (!IA_coupValide(p,TADCoup_coup(TADPion_pion(couleur_joueur_humain,TADPosition_position(ligne,colonne)))))
                    IHM_gras("<!> Coup non valide, réessayez !\n");
                    
            } while(!IA_coupValide(p,TADCoup_coup(TADPion_pion(couleur_joueur_humain,TADPosition_position(ligne,colonne)))));
            JEU_jouer(&p,couleur_joueur_courant,JEU_obtenirCoupH,ligne,colonne,3);
        }
        // si c'est l'IA qui joue
        else{
            printf("ORDINATEUR : A moi, je joue ici ! \n");
       
            JEU_jouer(&p,couleur_joueur_courant, IA_obtenirCoupIA,0,0,profondeur);
        }
        // à la fin d'un tour, on change la couleur du joueur qui joue
        couleur_joueur_courant = TADCouleur_couleurOpposee(couleur_joueur_courant);
    }

    // à la fin de la partie
    
    IHM_gras("<##> La partie est terminée ! <##>\n");
    egalite = JEU_trouverEgalite(&p);
    if (!egalite){
        vainqueur = JEU_trouverVainqueur(&p);
        GP_afficherPlateau(p);
        printf("<##> Le vainqueur est la couleur %d ! <##>\n",vainqueur->couleur);
    }
    else {
        GP_afficherPlateau(p);
        printf("<##> Pas de vainqueur ! <##>\n");
    }
    
}
