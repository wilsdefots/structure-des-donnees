#include "Vehicule.h"



Vehicule::Vehicule(std::string id, std::string type, std::string destination, int waitTime)
{
	this->id = id;
	this->type = type; 
	this->waitTime = waitTime ;
	this->destination = destination;
}


Vehicule::Vehicule(std::string id, std::string type, std::string destination)
	: Vehicule(id, type, destination, 0)
{//si le temps d attente n est pas fourni, on le set à 0
}

Vehicule::Vehicule(std::string id, std::string type, int waitTime)
	: Vehicule(id, type, "destination inconnue", waitTime)
{
}

Vehicule::Vehicule(std::string id, std::string type)
	: Vehicule(id, type, "destination inconnue", 0){  
}

Vehicule::Vehicule() : Vehicule("Vehicule non enregistre a la SAAQ", "type inconnu", "destination inconnue", 0) {

}

Vehicule::~Vehicule() = default;

void Vehicule::increaseWaitTime(int nombreDeTours)
{
	this->waitTime += nombreDeTours;
}

void Vehicule::decreaseWaitTime(int nombreDeTours)
{
	if (this->waitTime <= nombreDeTours) {
		this->waitTime = 0; 
		return; 
	}
	this->waitTime -= nombreDeTours; 
}



void Vehicule::display() const
{
	std::cout << "************************************************* " << std::endl
		<< "Numero de serie : " << this->getId() << std::endl
		<< "type : " << this->getType() << std::endl
		<< "temps d'attente : " << this->getWaitTime() << std::endl
		<< "destination : " << this->getDestination() << std::endl
		<< "************************************************* " << std::endl;
}
