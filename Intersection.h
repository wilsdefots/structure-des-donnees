#pragma once

#include <iostream>
#include"AccessoireRoutier.h"
#include "Road.h"




class Intersection
{
public:
	Intersection(std::string nom, intersectionType typeIntersection, Road* nord, Road* sud, Road* est, Road* ouest);
	Intersection();
	~Intersection() ;
	void processTurn(); // Traite un tour de circulation selon le type d'intersection.
	void updateLights(); // Met à jour l'état des feux.
	void display() ; // Affiche l'état de l'intersection.
	Road* routeSurchargee(); // Pour connaitre la route avec la plus longue file
	


private:
	std::string name; 
	intersectionType type; 
	Road* northroad; //Route venant du nord.
	Road* southRoad;  // Route venant du sud.
	Road* eastRoad;   //Route venant de l'est.
	Road* westRoad;  //Route venant de l'ouest.
	TrafficLightState northSouthLight; // État du feu Nord - Sud(GREEN, RED ou YELLOW).
	TrafficLightState eastWestLight;  // État du feu Est - Ouest(idem).
	int cycleCounter =0; 
	int greenDuration; // Durée minimale du vert (en tours).
	int maxGreenDuration;
	
};

