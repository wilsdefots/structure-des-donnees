#pragma once

#include <map>
#include <string>
using namespace std;

class Compteur
{
public:

	static void ajouterConstructeur();
	static void ajouterConstructeurCopie();
	static void ajouterDestructeur();

	static int getNbConstructeurs() { return constructeur; }
	static int getNbConstructeursCopie() { return constructeurCopie; }
	static int getNbDestructeurs() { return destructeur; }

	static string getInformation();

private:
	static int constructeur;
	static int constructeurCopie;
	static int destructeur;
};


