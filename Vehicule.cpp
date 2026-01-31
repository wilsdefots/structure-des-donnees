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
{
}

Vehicule::Vehicule(std::string id, std::string type, int waitTime)
	: Vehicule(id, type, "", waitTime)
{
}

Vehicule::Vehicule(std::string id, std::string type)
	: Vehicule(id, type, "", 0){  
}

Vehicule::Vehicule() : Vehicule("inconnu", "inconnu", " ", 0) {

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
