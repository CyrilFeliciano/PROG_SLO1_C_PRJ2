#include <stdio.h>                  // entr�e - sortie
#include <stdlib.h>                 // pour les fonctions syst�mes
#include <stdint.h>

#include "PontResistifs.h"


//d�claration de fonction
void InitInfoPontDiviseur(char choixUser, char* ptr_Nb_Res)     // fonction Information pont diviseur
{
	char choixUser = 0;
	char valeur = 0;
	
	printf("Veuillez inserer le nombre de resistance possible dans votre pont diviseur :");
	scanf("%d \n", choixUser);

	if (choixUser > * ptr_Nb_Res)		//test valeur entr�e pour nombre de r�sistance
	{
		valeur = MaxRes;
	}
	if (choixUser <= 0)
	{
		valeur = 1;
	}
	*ptr_Nb_Res = choixUser;

	printf("Veuillez inserer une valeur de resistance allant de 0.1 a 10Mohm R");
	for (size_t i = 0; i < choixUser; i++)
	{
	scanf("%d", *ptr_ValRes);
	if (*ptr_ValRes < ValMin_Res || *ptr_ValRes > ValMax_Res)
		{
			printf("!!! Erreur de valeur !!! \n");
		}
		else
		{
			*ValRes = &ptr_ValRes;
		}
	}
	

void CalculTensionPontDiviseur (char choixUser, int *Vin)

}