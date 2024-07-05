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
#include "time.h"
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


void TAD_test_couleur() {
    Couleur blanc, noir;
    char *affichage_couleur_blanc;
    char * affichage_couleur_noir;
    blanc = TADCouleur_couleur(true);
    noir = TADCouleur_couleur(false);
    affichage_couleur_blanc =TADCouleur_afficherCouleur(blanc);
    affichage_couleur_noir = TADCouleur_afficherCouleur(noir);
    CU_ASSERT_TRUE(TADCouleur_couleurOpposee(blanc).couleur == TADCouleur_couleur(false).couleur);
    CU_ASSERT_FALSE((int)TADCouleur_couleursIdentiques(blanc,noir));
    CU_ASSERT_TRUE((int)TADCouleur_couleursIdentiques(blanc,TADCouleur_couleur(true)));
    CU_ASSERT_STRING_EQUAL(affichage_couleur_blanc,"blanc");
    CU_ASSERT_STRING_EQUAL(affichage_couleur_noir,"noir");
}

void TAD_test_position() {
    Position pos;
    unsigned int x = rand() % 8;
    unsigned int y = rand() % 8;

    pos = TADPosition_position(x, y);
    CU_ASSERT_TRUE(TADPosition_obtenirLigne(pos) == x);
    CU_ASSERT_TRUE(TADPosition_obtenirColonne(pos) == y);
}

void TAD_test_pion() {
    Pion p;
    bool c = true;
    Couleur blanc;
    blanc = TADCouleur_couleur(c);
    Position pos = TADPosition_position(rand() % 8, rand() % 8);
    p = TADPion_pion(blanc, pos);
    CU_ASSERT_EQUAL(TADPion_obtenirCouleur(p).couleur,blanc.couleur);
    CU_ASSERT_EQUAL(p.estPlace,false);
    TADPion_changerCouleur(&p);
    CU_ASSERT_EQUAL(TADPion_obtenirCouleur(p).couleur,TADCouleur_couleurOpposee(blanc).couleur);
    TADPion_fixerCouleur(&p,blanc);
    CU_ASSERT_EQUAL(TADPion_obtenirCouleur(p).couleur,blanc.couleur);

}

void TAD_test_plateau() {
    Plateau plateau = TADPlateau_plateau();
    CU_ASSERT_FALSE(TADPlateau_estPlein(plateau));
}

void TAD_test_coup(){
     Pion p;
     Coup c;
     Couleur blanc = TADCouleur_couleur(true);
     Position pos = TADPosition_position(rand() % 8, rand() % 8);
     p = TADPion_pion(blanc, pos);
     Plateau pl = TADPlateau_plateau();
     c = TADCoup_coup(p);
     CU_ASSERT_TRUE(egalite_pion(TADCoup_obtenirPion(c),p));
     TADCoup_jouerCoup(&pl,c);
     CU_ASSERT_TRUE(TADPion_estPlace(TADPlateau_obtenirPion(pl,TADPion_obtenirPosition(c.pion)))); 
     }



void TAD_test_coups() {
    Couleur blanc = TADCouleur_couleur(true);
    Couleur noir = TADCouleur_couleur(false);
    Coups coups = TADCoups_coups();
    Pion p1 = TADPion_pion(blanc,TADPosition_position(1, 1));
    Pion p2 = TADPion_pion(noir,TADPosition_position(1, 2));
    Coup coup1 = TADCoup_coup(p1);
    Coup coup2 = TADCoup_coup(p2);

    CU_ASSERT_TRUE(TADCoups_obtenirNbCoups(coups) == 0);
    CU_ASSERT_TRUE(TADCoups_estVide(coups));
    TADCoups_ajouterCoup(&coups, coup1);
    CU_ASSERT_FALSE(TADCoups_estVide(coups));
    TADCoups_ajouterCoup(&coups, coup2);
    CU_ASSERT_TRUE(TADCoups_obtenirNbCoups(coups) == 2);

    CU_ASSERT_TRUE(egalite_coup(TADCoups_obtenirIEmeCoup(coups, 1), coup1));
    CU_ASSERT_TRUE(egalite_coup(TADCoups_obtenirIEmeCoup(coups, 0), coup2));
    }


int main(int argc, char** argv){
    CU_BasicRunMode mode = CU_BRM_VERBOSE;
    CU_pSuite pSuite = NULL;
    srand(time(NULL));

    /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry()){
    return CU_get_error();}

    /* ajout d'une suite de test */
    pSuite = CU_add_suite("Test othello : TADs", init_suite_success, clean_suite_success);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Ajout des tests */
    if ((NULL == CU_add_test(pSuite, "Test TAD Couleur", TAD_test_couleur))
    || (NULL == CU_add_test(pSuite, "Test TAD Position", TAD_test_position)) 
            || (NULL == CU_add_test(pSuite, "Test TAD Pion", TAD_test_pion)) 
            || (NULL == CU_add_test(pSuite, "Test TAD Coup", TAD_test_coup)) 
            || (NULL == CU_add_test(pSuite, "Test TAD Coups", TAD_test_coups)) 
            || (NULL == CU_add_test(pSuite, "Test TAD Plateau", TAD_test_plateau))
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
