#ifndef PONT_RESISTIF_H
#define PONT_RESISTIF_H



//d�clarations des constantes(si marche pas utiliser define)
const int nbMaxResistance = 10;
const int tensionMax = 30;
const float valMaxResistance = 10000000;
const float valMinResistance = 0.1;

//d�clarations des structures
struct pontDiviseur {
	int nbDeResistance;
	int tensionAlimVe;
	float valeurResistance[50];		
	float valeurTension[50];			
};


//d�clarations des prototypes des fonctions

float InitInfoPontDiviseur(float valUser, double valMaxResistance);
float CalculTensionPontDiviseur(struct pontDiviseur* pointeurTension);
float AffichageTensionPontDiviseur(); 



#endif // PONT_RESISTIF_H


