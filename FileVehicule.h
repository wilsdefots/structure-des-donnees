#pragma once
#include <iostream>

#include "SimpleNode.h" ;

class FileVehicule
{
public : 
	FileVehicule(): head(nullptr) ,queue (nullptr) {};// par defaut, une fille d attente est vide
	~FileVehicule();

	// Vérifier si la pile est vide
	bool isEmpty() const ;

	// Consulter le premier vehicule sans le retirer
	Vehicule* peek() const; /*Je n utilise pas void par ce que je veux pouvoir  manipuler le resultat plutard*/

	// accès au nombre de véhicules dans la pile
	int size() const ; 

	// ajout d'un vehicule
	void enqueue(SimpleNode* &simpleNoeudSuivant); 

	// retrait d'un vehicule
	void dequeue() ;

	// parcourt detous les vehicules pour affichage
	void display() const ; 

	inline SimpleNode* getHead() const { return this->head; }
	inline SimpleNode* getQueue() const { return this->queue;  }


private: 
	SimpleNode* head  ; 
	SimpleNode* queue ;

};

