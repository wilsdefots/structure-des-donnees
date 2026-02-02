#pragma once

#include<iostream>

enum class  TrafficLightState { 
    RED, 
    GREEN,
    YELLOW /*(optionnel)*/
};

enum class intersectionType {
    RIORITY_LIGHT, // Feu avec gestion dynamique de priorité
    FIXED_LIGHT,  // Feu avec cycle fixe
    FOUR_WAY_STOP // Intersection avec 4 stops
};

enum  Direction { Nord, Ouest, Sud, Est };
// Je ne le mets pas en classe par ce que je veux pouvoir faire les operations
