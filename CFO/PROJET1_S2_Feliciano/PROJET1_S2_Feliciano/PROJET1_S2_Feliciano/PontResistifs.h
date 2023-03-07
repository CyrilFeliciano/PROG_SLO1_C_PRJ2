#ifndef PontResistifs
#define PontResistifs
#include <stdio.h>                  // entr�e - sortie
#include <stdlib.h>                 // pour les fonctions syst�mes
#include <stdint.h>

//d�claration des constantes
const unsigned char MaxRes = 10;
const unsigned char MaxTension = 30;
const unsigned int ValMax_Res = 10000000;
const unsigned float ValMin_Res = 0.1;


//d�finition de la structure

struct pontDiviseur {
	unsigned char Nb_Res;
	unsigned char Vin;
	unsigned int ValRes[100];		//Valeur du tableau � v�rifier
	unsigned char Val_U_Res[100];	//Valeur du tableau � v�rifier
};

//D�claration des pointeurs
struct pontDiviseur* Nb_Res;
struct pontDiviseur* Vin;
struct pontDiviseur* ValRes;
struct pontDiviseur* Val_U_Res;

char* ptr_Nb_Res = *Nb_Res;
int* ptr_ValRes = *ValRes;
int* ptr_Vin = *Vin;
//D�claration des prototype de fonction
void InitInfoPontDiviseur(char choixUser, char* ptr_Nb_Res)

#endif  !PontResistifs;

