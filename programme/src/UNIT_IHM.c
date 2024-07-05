#include <stdio.h>
#include <stdlib.h>
#include "UNIT_IHM.h"

// le préfixe à mettre dans un printf pour le gras

void IHM_gras(char* texte){
	printf("\033[1m%s\033[0m", texte);
}

void IHM_separateur(){
	printf("----------------------------------------------\n");
}

void IHM_aide(){
	IHM_separateur();
	IHM_gras("<#> Aide du programme othello <#>\n");
	printf("Les options possibles sont :\n");
	printf("\t <1> othello standard blanc | noir [profondeur >2]\n");
	printf("\t\t permet de jouer contre l'ordinateur en lui donnant les blancs ou les noirs\n");
	printf("\t <2> othello tournoi blanc | noir [profondeur >2]\n");
	printf("\t\t permet de faire jouer le programme dans un mode tournoi en lui donnant les blancs ou les noirs\n"); 
	IHM_separateur();
}