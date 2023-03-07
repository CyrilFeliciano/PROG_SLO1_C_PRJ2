//-----------------------------------------------------------------------------------//
// Nom du projet 		: Projet 1 Semestre2 Pont resistif 
// Nom du fichier 		: fonctionsPontDiv.h
// Date de cr�ation 	: 07.03.2023
// Date de modification : xx.xx.20xx
//
// Auteur 				: JAR (J�r�my Affolter)
//
// Description          : 
//
//
// Remarques			: voir donnee de l'�preuve            
//----------------------------------------------------------------------------------//

// Librairie perso
#include "PontResistifs.h"


//---
// Nom fonction : InitInfoPontDiviseur
// Param�tres entr�e / sortie / inout : -/-/demoPontDiv
// Description : Initialise une structure pontDiviseur
// Remarque : -
// Auteur : JAR
// Date modification : 07.03.2023
//---
void InitInfoPontDiviseur(pontDiviseur* demoPontDiv)
{
	// Affichage Fonction Init
	printf("Vous Etes dans la fonction d'initialisation de pont diviseur\n\n");
	// Afficher une demande du nombre de r�sistances
	printf("Entrer le nombre de r�sistances de votre pont\n");
	// R�cup�ration du nombres de r�sistances
	scanf("%c", &demoPontDiv->nbRes);
	// Test que le nombres de r�sistances entr�es ne soit pas plus grand ou plus petit que les limites
	if (demoPontDiv->nbRes > NBMAXRES)
	{
		demoPontDiv->nbRes = NBMAXRES;
		printf("La valeur entr�e est trop grande. Votre nombre de r�sistances est &c\n", NBMAXRES);
	}
	else if (demoPontDiv->nbRes <= 0)
	{
		demoPontDiv->nbRes = 1;
		printf("La valeur entr�e est trop petit. Votre nombre de r�sistances est 1\n");
	}

	for (char i = 0; i < demoPontDiv->nbRes; i++)
	{
		do
		{
			// Afficher une demande de la valeur de la r�sistance
			printf("Entrer la valeur de la r�sistance %c\n", &i);
			// R�cup�ration de la valeur de la r�sistance
			scanf("%d", &demoPontDiv->tb_ValRes[i]);
			// Test que la valeur soit dans les limites d�finies si non recommencer
			if ((demoPontDiv->tb_ValRes[i] > RMAX) || (demoPontDiv->tb_ValRes[i] < RMIN))
			{
				printf("La valeur ne rentre pas dans les limites(maximum &d et minimum &d)\n", RMAX, RMIN);
			}
		} while ((demoPontDiv->tb_ValRes[i] > RMAX) || (demoPontDiv->tb_ValRes[i] < RMIN));
	}
	// Afficher	une demande de Vcc du pont
	printf("Entrer la tension de votre pont\n");
	// R�cup�ration de la tension du pont
	scanf("%c", &demoPontDiv->vccPont);
	// Test que la tension du pont ne soit pas plus grand ou plus petit que les limites
	if (demoPontDiv->vccPont > VCCMAX)
	{
		demoPontDiv->vccPont = VCCMAX;
		printf("La valeur entr�e est trop grande. Votre tension de pont est &cV\n", VCCMAX);
	}
	else if (demoPontDiv->vccPont < 1)
	{
		demoPontDiv->nbRes = 1;
		printf("La valeur entr�e est trop petit. Votre ntension de pont est 1V\n");
	}
}


//---
// Nom fonction : CalculTensionPontDiviseur
// Param�tres entr�e / sortie / inout : -/-/demoPontDiv
// Description : Calcul la tension sur chaque r�sistance
// Remarque : -
// Auteur : JAR
// Date modification : 07.03.2023
//---
void CalculTensionPontDiviseur(pontDiviseur* demoPontDiv)
{
	// Variables locales
	int rTot = 0;

	for (char i = 0; i < demoPontDiv->nbRes; i++)
	{
		rTot = rTot + demoPontDiv->tb_ValRes[i];
	}
	for (char i = 0; i < demoPontDiv->nbRes; i++)
	{
		demoPontDiv->tb_URes[i] = demoPontDiv->vccPont * demoPontDiv->tb_ValRes[i] / rTot;
	}
}


//---
// Nom fonction :AffichageTensionPontDiviseur
// Param�tres entr�e / sortie / inout : demoPontDiv/-/-
// Description : Affiche la tension sur chaque r�sistance
// Remarque : -
// Auteur : JAR
// Date modification : 07.03.2023
//---
void AffichageTensionPontDiviseur(pontDiviseur demoPontDiv)
{
	for (char i = 0; i < demoPontDiv.nbRes; i++)
	{
		printf("Tension sur la r�sistance &c: &.3f", &i, &demoPontDiv.tb_URes[i]);
	}
}