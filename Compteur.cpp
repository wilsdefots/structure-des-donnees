#include "Compteur.h"

int Compteur::constructeur = 0;
int Compteur::destructeur;
int Compteur::constructeurCopie = 0;

void Compteur::ajouterConstructeur()
{
	constructeur++;
}

void Compteur::ajouterConstructeurCopie()
{
	constructeurCopie++;
}

void Compteur::ajouterDestructeur()
{
	destructeur++;
}

string Compteur::getInformation()
{
	string info = "\n\n-------------------------------\n";
	info += (" NB constructeurs       : " + to_string(Compteur::constructeur) + "\n");
	info += (" NB constructeurs copie : " + to_string(Compteur::constructeurCopie) + "\n");
	info += (" NB destructeurs        : " + to_string(Compteur::destructeur) + "\n");

	return info;
}



