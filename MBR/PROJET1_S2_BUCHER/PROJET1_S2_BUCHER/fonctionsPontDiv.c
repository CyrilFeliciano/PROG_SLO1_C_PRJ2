//--- librairie standart ---//
#include <stdio.h>                  // entr�e - sortie
#include <stdlib.h>                 // pour les fonctions syst�mes
#include <stdint.h>

//-- librairie personnelle --// 
#include "PontResistifs.h"

//d�clarations des fonctions
//type_de_retour nom_de_la_fonction(type_argument_1 arg1, type_argument_2 arg2, ...);




float InitInfoPontDiviseur(float valUser, double valMaxResistance)
{
	float valUser = 0;
	int valeurMax = 0;
	float valeurTension = 0;
	float valeurResistance = 0;
	int i = 1;			//compteur pour le nb de r�sistance


	//partie pour ins�rer le nombre de r�sistance max
	printf("Veuillez ins�rer le nombre de r�sistance possible dans votre pont diviseur : ");
	scanf("%f", valUser);

	if (valUser > nbMaxResistance)
	{
		valeurMax = nbMaxResistance;
	}
	else if (valUser <= 0)
	{
		valeurMax = 1;
	}
	else
	{
		valeurMax = valUser;
	}

	//Partie pour ins�rer les valeurs de r�sistances
	for (i = 1; i <= 10; i++)
	{
		printf("Veuillez ins�rer une valeur de r�sistance allant de 0.1 � 10Mohm pour R% : ",i);
		scanf("%f", valUser);

		//mettre les diff�rentes valeur dans une variable
		valeurResistance = valUser;
	}



	//Partie inserer la valeur de tension
	printf("Veuillez ins�rer la valeur de tension du montage: ");
	scanf("%f", valUser);

	if (valUser > tensionMax)
	{
		valeurTension = tensionMax;
	}

	else if (valUser < 1)
	{
		valeurTension = 1;
	}

	else
	{
		valeurTension = valUser;
	}
	//mise en m�moire des valeurs dans la structure pontDiviseur
	struct pontDiviseur pontDiviseur = { valeurMax, valeurResistance, valeurTension };

}



float CalculTensionPontDiviseur(struct pontDiviseur *pointeurTension)
{
	float VpontDiviseur = 0;

	//VpontDiviseur = pontDiviseur.valeurTension;
}



float AffichageTensionPontDiviseur()
{

	//fonction affichant la tension se trouvant au borne de chaque r�sistance sous format scientifique de 3 chiffres significatif

}