//Nom du projet			: fonction pont diviseur
//Nom du fichier		: fonctionsPontDiv.c
//Nom auteur			: Diogo Ferreira
//Date de cr�ation		: 07.03.2023
//Date de modification	: 07.03.2023 DF
/*
  Description:
  fonction qui permet d'initialiser les valeurs de r�sistance, calculer et afficher le r�sultat

  Remarque:
  n�cessaire des librairie local PontResistifs.h pour les valeurs max et min 
  et le type de structure compatible pour les fonctions
*/

//--- librairie standart ---//
#include <stdio.h>                  // entr�e - sortie

//-- librairie personnelle --// 
#include "PontResistifs.h"


//fonction pour initialiser une structure avec le nombre de r�sistance/valeur de r�sistance/tension alim
void InitInfoPontDiviseur(struct pontDiviseur* demoPontDiv)
{
	float valeurUser;
	unsigned int i;
	int Error = 0;
	//nombre de r�sistance
	printf("Entrer le nombre de resistance (Max %d / type entier):\n", MAXNBRRES);
	scanf_s("%f", &valeurUser);
	if (valeurUser > MAXNBRRES)
		valeurUser = MAXNBRRES;
	if (valeurUser < 1)
		valeurUser = 1;
	demoPontDiv->NbrMaxRes = valeurUser;

	//insertion des valeurs de r�sistance
	for (i = 0; i < demoPontDiv->NbrMaxRes; i++)
	{
		printf("Entrer la valeur de resistance %d (Max 10M / Min 0.1):\n", i+1);
		do
		{
			Error = 0;
			scanf_s("%f", &valeurUser);
			if ((valeurUser > MAXRES) || (valeurUser < MINRES))
			{
				Error = 1;
				printf("ERREUR: VALEUR INCORRECT\n");
				while ((getchar() != '\n') && (getchar() != EOF));
			}
			else
				demoPontDiv->TbResistor[i] = valeurUser;
				
		} while (Error == 1);
		
	}

	//tension circuit
	printf("Entrer la tension du circuit (Max %d / type entier):\n", MAXVALIM);
	scanf_s("%f", &valeurUser);
	if (valeurUser > MAXVALIM)
		valeurUser = MAXVALIM;
	if (valeurUser < 1)
		valeurUser = 1;
	demoPontDiv->VAlim = valeurUser;

	//fin de l'initialisation
	while ((getchar() != '\n') && (getchar() != EOF));
}

//fonction pour calculer les diff�rente tension des r�sistances
void CalculTensionPontDiviseur(struct pontDiviseur* demoPontDiv) 
{
	float RTotal = 0;
	float Rdiv = 0;
	int i;
	//initialisation de la r�sitance max du circuit
	for (i = 0; i < demoPontDiv->NbrMaxRes; i++) 
	{
		RTotal += demoPontDiv->TbResistor[i];
		
	}
	Rdiv = RTotal;

	//algorithme pour les diff�rentes tensions
	for (i = 0; i < demoPontDiv->NbrMaxRes; i++)
	{
		
		demoPontDiv->TbVResistor[i] = demoPontDiv->VAlim * (Rdiv / RTotal);
		Rdiv -= demoPontDiv->TbResistor[i];
	}

}

//fonction qui permet d'afficher les r�stultats des tensions des r�sistance.
void AffichageTensionPontDiviseur(struct pontDiviseur demoPontDiv)
{
	unsigned int i;
	//espace entre initialisation et les r�sultats
	printf("\n\n");
	//affichage de chaque r�sistance avec ses valeurs
	for (i = 0; i < demoPontDiv.NbrMaxRes; i++)
	{
		printf("R%d  Valeur:%f  Tension:%f\n", i+1, demoPontDiv.TbResistor[i], demoPontDiv.TbVResistor[i]);
	}
}