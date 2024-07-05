#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "TAD_Coup.h"
#include "TAD_Coups.h"
#include "TAD_Couleur.h"
#include "TAD_Pion.h"
#include "TAD_Plateau.h"
#include "TAD_Position.h"
#include "JEU_SeDeplacerDansLaDirection.h"
#include "time.h"
#include "JEU_ObtenirCoupH.h"
#include "JEU_TrouverVainqueur.h"
#include "UNIT_GestionPlateau.h"
#include "JEU_TesterFin.h"
#include "JEU_CalculerScore.h"
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h> 
#include <CUnit/Automated.h> 
#include <CUnit/Console.h> 	
 	


int init_suite_success(void) {
    return 0;
}

int clean_suite_success(void) {
    return 0;
}

bool egalite_pion(Pion p1, Pion p2) {
    bool res;
    Position pos1, pos2;
    res = false;
    Couleur c1;
    Couleur c2;
    c1 = p1.couleur;
    c2 = p2.couleur;
    pos1 = p1.position;
    pos2 = p2.position;
    if ((c1.couleur == c2.couleur)  && (p1.estPlace == p2.estPlace) && (pos1.ligne == pos2.ligne) &&(pos1.colonne == pos2.colonne)){
    res = true;
    }
    return (res);
}

bool egalite_position(Position pos1, Position pos2) {
    return (pos1.ligne == pos2.ligne && pos1.colonne == pos2.colonne);
}

bool egalite_coup(Coup cp1, Coup cp2) {
    return (egalite_pion(TADCoup_obtenirPion(cp1), TADCoup_obtenirPion(cp2)));}


void JEU_test_seDeplacerDansLaDirection() {
    	Position pos;
    	unsigned int x = rand() % 8;
    	unsigned int y = rand() % 8;
	pos = TADPosition_position(x, y);
    	CU_ASSERT_TRUE(TADPosition_obtenirLigne(TADPosition_position(x-1,y))== TADPosition_obtenirLigne(JEU_seDeplacerDansLaDirection(pos,0)));
    	CU_ASSERT_TRUE(TADPosition_obtenirColonne(TADPosition_position(x-1,y))== TADPosition_obtenirColonne(JEU_seDeplacerDansLaDirection(pos,0)));    
    	CU_ASSERT_TRUE(TADPosition_obtenirLigne(TADPosition_position(x-1,y+1))== TADPosition_obtenirLigne(JEU_seDeplacerDansLaDirection(pos,1)));
    	CU_ASSERT_TRUE(TADPosition_obtenirColonne(TADPosition_position(x-1,y+1))== TADPosition_obtenirColonne(JEU_seDeplacerDansLaDirection(pos,1)));
    	CU_ASSERT_TRUE(TADPosition_obtenirLigne(TADPosition_position(x,y+1))== TADPosition_obtenirLigne(JEU_seDeplacerDansLaDirection(pos,2)));
    	CU_ASSERT_TRUE(TADPosition_obtenirColonne(TADPosition_position(x,y+1))== TADPosition_obtenirColonne(JEU_seDeplacerDansLaDirection(pos,2)));    
    	CU_ASSERT_TRUE(TADPosition_obtenirLigne(TADPosition_position(x+1,y+1))== TADPosition_obtenirLigne(JEU_seDeplacerDansLaDirection(pos,3)));
    	CU_ASSERT_TRUE(TADPosition_obtenirColonne(TADPosition_position(x+1,y+1))== TADPosition_obtenirColonne(JEU_seDeplacerDansLaDirection(pos,3)));
    	CU_ASSERT_TRUE(TADPosition_obtenirLigne(TADPosition_position(x+1,y))== TADPosition_obtenirLigne(JEU_seDeplacerDansLaDirection(pos,4)));
    	CU_ASSERT_TRUE(TADPosition_obtenirColonne(TADPosition_position(x+1,y))== TADPosition_obtenirColonne(JEU_seDeplacerDansLaDirection(pos,4))); 
    	CU_ASSERT_TRUE(TADPosition_obtenirLigne(TADPosition_position(x+1,y-1))== TADPosition_obtenirLigne(JEU_seDeplacerDansLaDirection(pos,5)));
    	CU_ASSERT_TRUE(TADPosition_obtenirColonne(TADPosition_position(x+1,y-1))== TADPosition_obtenirColonne(JEU_seDeplacerDansLaDirection(pos,5)));
    	CU_ASSERT_TRUE(TADPosition_obtenirLigne(TADPosition_position(x,y-1))== TADPosition_obtenirLigne(JEU_seDeplacerDansLaDirection(pos,6)));
    	CU_ASSERT_TRUE(TADPosition_obtenirColonne(TADPosition_position(x,y-1))== TADPosition_obtenirColonne(JEU_seDeplacerDansLaDirection(pos,6)));   
    	CU_ASSERT_TRUE(TADPosition_obtenirLigne(TADPosition_position(x-1,y-1))== TADPosition_obtenirLigne(JEU_seDeplacerDansLaDirection(pos,7)));
    	CU_ASSERT_TRUE(TADPosition_obtenirColonne(TADPosition_position(x-1,y-1))== TADPosition_obtenirColonne(JEU_seDeplacerDansLaDirection(pos,7)));
}

void JEU_test_ObtenirCoupH(){
   	Plateau plateau = TADPlateau_plateau();
    	bool c = true;
    	Couleur couleur;
    	unsigned int x = rand() % 8;
    	unsigned int y = rand() % 8;
    	
    	couleur = TADCouleur_couleur(c);

    	Coup coup = JEU_obtenirCoupH(plateau,couleur,x,y,3);
    	Coup coup2 = JEU_obtenirCoupH(plateau,couleur,x+1,y,3);
    	CU_ASSERT_FALSE(egalite_coup(coup,coup2));
    	CU_ASSERT_EQUAL(coup.pion.position.ligne,x);
    	CU_ASSERT_EQUAL(coup.pion.position.colonne,y);
    	CU_ASSERT_EQUAL(coup.pion.couleur.couleur,couleur.couleur);
    	CU_ASSERT_EQUAL(TADPion_obtenirCouleur(TADCoup_obtenirPion(coup)).couleur,couleur.couleur);
    	CU_ASSERT_EQUAL(TADPosition_obtenirLigne(TADPion_obtenirPosition(TADCoup_obtenirPion(coup))),x);
    	CU_ASSERT_EQUAL(TADPosition_obtenirColonne(TADPion_obtenirPosition(TADCoup_obtenirPion(coup))),y);
}

void JEU_test_CalculerScore(){
   	unsigned int* score_blanc  = (unsigned int*)malloc(sizeof(unsigned int));
    	unsigned int* score_noir= (unsigned int*)malloc(sizeof(unsigned int));
   	
    	Couleur couleur_joueur_noir = TADCouleur_couleur(false);
	//Plateau plat = TADPlateau_plateau();
	Plateau plat = GP_initialiserPlateau();
	Plateau *plateau = &plat;
	JEU_calculerScore(*plateau,score_blanc,score_noir);
	CU_ASSERT_EQUAL(*score_blanc,2);
    	CU_ASSERT_EQUAL(*score_noir,2);
   	
    	Coup coup = TADCoup_coup(TADPion_pion(couleur_joueur_noir,TADPosition_position(2,3)));
    	TADCoup_jouerCoup(plateau,coup);
    	GP_miseAJourPlateau(plateau, coup);
	Coup coup1 = TADCoup_coup(TADPion_pion(couleur_joueur_noir,TADPosition_position(1,3)));
	TADCoup_jouerCoup(plateau,coup1);
    	GP_miseAJourPlateau(plateau, coup1);
    	Coup coup2 = TADCoup_coup(TADPion_pion(couleur_joueur_noir,TADPosition_position(3,2)));
	TADCoup_jouerCoup(plateau,coup2);
    	GP_miseAJourPlateau(plateau, coup2);
    	JEU_calculerScore(*plateau,score_blanc,score_noir);
    	//CU_ASSERT_EQUAL(*score_blanc,2);
    	//CU_ASSERT_EQUAL(*score_noir,5);
    	free(score_blanc);
    	free(score_noir);
}




void JEU_test_TrouverVainqueur(){
   	
    	Couleur couleur_joueur_blanc = TADCouleur_couleur(true);
    	Couleur couleur_joueur_noir = TADCouleur_couleur(false);
	Plateau plat = GP_initialiserPlateau();
   	Plateau *plateau = &plat;
    	Coup coup = TADCoup_coup(TADPion_pion(couleur_joueur_noir,TADPosition_position(2,3)));
    	TADCoup_jouerCoup(plateau,coup);
    	GP_miseAJourPlateau(plateau, coup);
	Coup coup1 = TADCoup_coup(TADPion_pion(couleur_joueur_noir,TADPosition_position(1,3)));
	TADCoup_jouerCoup(plateau,coup1);
    	GP_miseAJourPlateau(plateau, coup1);
    	Coup coup2 = TADCoup_coup(TADPion_pion(couleur_joueur_noir,TADPosition_position(3,2)));
	TADCoup_jouerCoup(plateau,coup2);
    	GP_miseAJourPlateau(plateau, coup2);
    	CU_ASSERT_NOT_EQUAL(JEU_trouverVainqueur(plateau)->couleur ,couleur_joueur_blanc.couleur);
    	//ATTENTION DONNE TOUJOURS NOIR COMME VAINQUEUR A CORRIGER
	Plateau plat2 = TADPlateau_plateau();
    	Plateau* pl = &plat2;
    	TADCoup_jouerCoup(pl,JEU_obtenirCoupH(*pl,couleur_joueur_blanc,1,1,3));
    	GP_miseAJourPlateau(pl, JEU_obtenirCoupH(*pl,couleur_joueur_blanc,1,1,3));
    	TADCoup_jouerCoup(pl,JEU_obtenirCoupH(*pl,couleur_joueur_blanc,1,2,3));
    	GP_miseAJourPlateau(pl, JEU_obtenirCoupH(*pl,couleur_joueur_blanc,1,2,3));
    	TADCoup_jouerCoup(pl,JEU_obtenirCoupH(*pl,couleur_joueur_blanc,1,3,3));
    	GP_miseAJourPlateau(pl, JEU_obtenirCoupH(*pl,couleur_joueur_blanc,1,3,3));
    	TADCoup_jouerCoup(pl,JEU_obtenirCoupH(*pl,couleur_joueur_noir,2,1,3));
    	GP_miseAJourPlateau(pl, JEU_obtenirCoupH(*pl,couleur_joueur_noir,2,1,3));
    	CU_ASSERT_EQUAL(JEU_trouverVainqueur(pl)->couleur ,couleur_joueur_blanc.couleur);
    	
}



void JEU_test_TesterFin(){
 	unsigned int TAILLE = 8;
   	Plateau plateau = TADPlateau_plateau();
    	//Couleur couleur_joueur_blanc = TADCouleur_couleur(true);
    	Couleur couleur_joueur_noir = TADCouleur_couleur(false);
    	for (int i=0; i<TAILLE; i++) {
		for (int j=0; j<TAILLE; j++) {
			TADCoup_jouerCoup(&plateau,TADCoup_coup(TADPion_pion(couleur_joueur_noir,TADPosition_position(i,j))));
			GP_miseAJourPlateau(&plateau, TADCoup_coup(TADPion_pion(couleur_joueur_noir,TADPosition_position(i,j))));
		}
	}
	CU_ASSERT_TRUE(JEU_testerFin(plateau));
}







int main(int argc, char** argv){
    CU_BasicRunMode mode = CU_BRM_VERBOSE;
    CU_pSuite pSuite = NULL;
    srand(time(NULL));

    /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry()){
    return CU_get_error();}

    /* ajout d'une suite de test */
    pSuite = CU_add_suite("Test othello : JEU", init_suite_success, clean_suite_success);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Ajout des tests */
    if ((NULL == CU_add_test(pSuite, "Test JEU se Déplacer dans la diresction", JEU_test_seDeplacerDansLaDirection))
    || (NULL == CU_add_test(pSuite, "Test JEU ObtenirCoupH", JEU_test_ObtenirCoupH)) 
      || (NULL == CU_add_test(pSuite, "Test JEU Vainqueur", JEU_test_TrouverVainqueur)) 
            || (NULL == CU_add_test(pSuite, "Test JEU Tester Fin", JEU_test_TesterFin)) 
            || (NULL == CU_add_test(pSuite, "Test JEU Calculer Score", JEU_test_CalculerScore)) 
            /*|| (NULL == CU_add_test(pSuite, "Test TAD Plateau", TAD_test_plateau))*/
       ) 
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Lancement des tests */
    CU_basic_set_mode(mode);
    CU_basic_run_tests();
    printf("\n");
    CU_basic_show_failures(CU_get_failure_list());
    printf("\n\n");

    /* Nettoyage du registre */
    CU_cleanup_registry();
    return CU_get_error();
}






