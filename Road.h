#pragma once
#include<iostream>
#include"AccessoireRoutier.h"
#include"FileAttente.h"
#include <ctime>

std::string dateHeure() {
	char b[17]; time_t t = time(0); tm m;
	localtime_s(&m, &t);
	strftime(b, 17, "%Y-%m-%d %H:%M", &m);
	return b;
}  // le code précédant pour retourner la date a été généré par ChatGPT

class Road
{
public:
	Road(std::string nom, FileVehicule*& file, Direction direction);
	Road():nom("route Nord"),  fileDeVehicule(nullptr), direction(Nord){}
	~Road(); 
	void addVehicule(Vehicule v); //Ajoute un véhicule à la file
	Vehicule* getNextVehicule(); //Retourne et retire le premier véhicule.
	void increaseAllWaitTimes(); //Incrémente le temps d'attente de tous les véhicules.
	void display(); // Affiche l'état de la route.
	int getVehicleCount(); // Retourne le nombre de véhicules sur la route.

	inline std::string getNom() const { return this->nom; }
	inline FileVehicule* getFileDeVehicule() const { return this->fileDeVehicule; }
	inline Direction getDirection() const { return this->direction;  }

private:
	std::string nom; 
	FileVehicule* fileDeVehicule; 
	Direction direction; 

};

