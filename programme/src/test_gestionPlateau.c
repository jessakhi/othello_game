#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h> 
#include <CUnit/Automated.h> 
#include <CUnit/Console.h> 
#include "UNIT_GestionPlateau.h"
#include "time.h"

int init_suite_success(void) {
    return 0;
}

int clean_suite_success(void) {
    return 0;
}

void test_Initialisation(){

	Plateau p = GP_initialiserPlateau ();
	Pion TPion;
	TPion = TADPlateau_obtenirPion (p, TADPosition_position(3,3) );
	CU_ASSERT_STRING_EQUAL(TADCouleur_afficherCouleur(TADPion_obtenirCouleur(TPion) ), "blanc"); //la couleur du pion doit être blanche
	TPion = TADPlateau_obtenirPion (p, TADPosition_position(4,3) );
	CU_ASSERT_STRING_EQUAL(TADCouleur_afficherCouleur(TADPion_obtenirCouleur(TPion)) , "noir");//la couleur du pion doit être noir
	TPion = TADPlateau_obtenirPion(p, TADPosition_position (3,4) ) ;
	CU_ASSERT_STRING_EQUAL(TADCouleur_afficherCouleur(TADPion_obtenirCouleur(TPion)), "noir"); //la couleur du pion doit être noir
	TPion = TADPlateau_obtenirPion (p, TADPosition_position(4,4) );
	CU_ASSERT_STRING_EQUAL(TADCouleur_afficherCouleur(TADPion_obtenirCouleur(TPion)) , "blanc");//la couleur du pion doit être blanche
}

void test_CoordonneeEnPosition ( void ) {
Position pos ;
Position positionR ;
char* coord  = "4D\0" ;

Position posR= TADPosition_position(4,4);
pos = GP_convertirCoordonneeEnPosition(coord) ;
unsigned int a=TADPosition_obtenirLigne(pos);
printf(" la valeur de la ligne %d",pos.ligne);
printf(" la valeur de la ligne %d",pos.colonne);

CU_ASSERT( TADPosition_obtenirLigne(pos) == TADPosition_obtenirLigne(posR));
CU_ASSERT_EQUAL( TADPosition_obtenirColonne(pos) , TADPosition_obtenirColonne(posR));
}

void test_miseAJourPlateau(){
Plateau p = GP_initialiserPlateau ();
Pion Pion1 , Pion2, Pion3, Pion4, Pion5, Pion6, Pion7;
Coup coup;

Pion1 = TADPlateau_obtenirPion(p,TADPosition_position(4,4));
Pion2 = TADPlateau_obtenirPion(p,TADPosition_position(4,5));
Pion3 = TADPlateau_obtenirPion(p,TADPosition_position(5,4));
Pion4 = TADPlateau_obtenirPion(p,TADPosition_position(5,5));

// On place le Pion5 
Pion5 = TADPion_pion(TADCouleur_couleur(0),TADPosition_position(3,4));
TADPlateau_placerPion(&p,Pion5);
coup = TADCoup_coup (Pion5);
GP_miseAJourPlateau(&p , coup);
CU_ASSERT_STRING_EQUAL(TADCouleur_afficherCouleur(TADPion_obtenirCouleur(Pion1) ), "blanc");


// On place le Pion6
Pion6= TADPion_pion(TADCouleur_couleur(1),TADPosition_position(5,3));
TADPlateau_placerPion(&p,Pion6);
coup = TADCoup_coup (Pion6);
GP_miseAJourPlateau(&p , coup);
CU_ASSERT_STRING_EQUAL(TADCouleur_afficherCouleur(TADPion_obtenirCouleur(Pion3) ), "noir");

// On place le Pion7
Pion7= TADPion_pion(TADCouleur_couleur(0),TADPosition_position(6,3));
TADPlateau_placerPion(&p,Pion7);
GP_miseAJourPlateau(&p , coup);
CU_ASSERT_STRING_EQUAL(TADCouleur_afficherCouleur(TADPion_obtenirCouleur(Pion3) ), "noir");

}
int main(int argc, char** argv){
    CU_BasicRunMode mode = CU_BRM_VERBOSE;
    CU_pSuite pSuite = NULL;
    srand(time(NULL));

    /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry()){
    return CU_get_error();}

    /* ajout d'une suite de test */
    pSuite = CU_add_suite("Test othello : init", init_suite_success, clean_suite_success);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }
     /* Ajout des tests */
    if ((NULL == CU_add_test(pSuite, "Test INITIALISATION ", test_Initialisation)|| (NULL == CU_add_test(pSuite, "Test MAJ PLATEAU", test_miseAJourPlateau)) || (NULL == CU_add_test(pSuite, "Test COORD EN POSITION ", test_CoordonneeEnPosition)))
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

