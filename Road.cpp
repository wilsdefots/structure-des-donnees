#include "Road.h"

Road::Road(std::string nom, FileVehicule*& file, Direction direction)
{
	this->nom = nom; 
	this->fileDeVehicule = file; 
	this->direction = direction;
}


void Road::addVehicule(Vehicule v)
{
    //enqueue(SimpleNode * &simpleNoeudSuivant);
   /* puisque la methode file.enqueue() attend un pointeur vers un noed,
   //et que nous  avons juste un vehicule, on va creer une variable de type
   // pointeur de noeud */

    SimpleNode* nouveauNoeudVehicule = new SimpleNode(v); 
    this->fileDeVehicule->enqueue(nouveauNoeudVehicule); 
    std::cout << "Vehicule ajoute avec succes dans la file ; " << std::endl; 
 }

Vehicule* Road::getNextVehicule()
{
    if (this->fileDeVehicule->isEmpty()) {
        std::cout << "Aucun vehicule dans la file !" << std::endl;
        return nullptr;
    }
    Vehicule* temp = new Vehicule(this->fileDeVehicule->getHead()->vehiculeCourant); 
    // temp pointe vers le vehicule qui se trouve à la tete
    this->fileDeVehicule->dequeue();
    return temp; 

}

void Road::increaseAllWaitTimes()
{
    if (this->fileDeVehicule->isEmpty()) {
        return;
    }
    while (!this->fileDeVehicule->isEmpty()) {
        this->fileDeVehicule->getHead()->vehiculeCourant.increaseWaitTime();
        this->fileDeVehicule->dequeue();
    }
}



void Road::display()
{

    std::cout << "************************************************* " << std::endl
        << "État de la route : " << this->getNom() << " \t en date du : "
        << dateHeure() << std::endl;
    this->fileDeVehicule->display(); 
}



int Road::getVehicleCount()
{
    return this->fileDeVehicule->size(); 
}



