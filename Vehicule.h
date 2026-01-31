#pragma once

#include<iostream>

class Vehicule
{
public : 
	Vehicule(std::string id, std::string type, std::string destination, int waitTime); 
	Vehicule(std::string id, std::string type, std::string destination);
	Vehicule(std::string id, std::string type,  int waitTime);
	Vehicule(std::string id, std::string type);
	Vehicule();
	~Vehicule(); // Je veux faire un nettoyage propre


	void increaseWaitTime(int nombreDeTours);
	inline void  increaseWaitTime() { increaseWaitTime(1); }
	void decreaseWaitTime(int nombreDeTours);
	inline void  decreaseWaitTime() { decreaseWaitTime(1); }
	void display() const ; 


	inline std::string getId() const { return this->id;  }
	inline std::string getType() const { return this->type;  }
	inline std::string getDestination() const { return this->destination;  }
	inline int getWaitTime() const { return this->waitTime; }

private : 
	std::string id; 
	std::string type; 
	std::string destination;
	int waitTime; // temps d'attente en tour
};

