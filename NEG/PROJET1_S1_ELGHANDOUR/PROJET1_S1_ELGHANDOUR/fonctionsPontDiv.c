//--- librairie standart ---//
#include <stdio.h>                  // entr�e - sortie
#include <stdlib.h>                 // pour les fonctions syst�mes
#include <stdint.h>

//-- librairie personnelle --// 
#include "PontResistifs.h"

//...................................Fonctions

int InitInofoPontDiviseur(PontDiviseur *demoPonDiv) {
	int valeurUser;
	printf("nombre de resisatance du pont : ");
	scanf("%d", &valeurUser);

	if (valeurUser > nombreMaxDeResPontDiv)
	{
		demoPonDiv->nbResComposantPonRes = nombreMaxDeResPontDiv;
	}
	else if (valeurUser <= 0)
	{
		demoPonDiv->nbResComposantPonRes = 1;
	}
	demoPonDiv->tbValRes = malloc(sizeof(int) * demoPonDiv->nbResComposantPonRes);
	if (!demoPonDiv->tbValRes)
	{
		return;
	}
}

int CalculTensionPontDiviseur(PontDiviseur* demoPonDiv) {

}

int AfficheTensionPontDiviseur(PontDiviseur demoPonDiv) {

}
