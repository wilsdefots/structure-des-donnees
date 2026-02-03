#pragma once

#include<iostream>

enum class  TrafficLightState { 
    RED, 
    GREEN,
    YELLOW /*(optionnel)*/
};

enum class intersectionType {
    PRIORITY_LIGHT, // Feu avec gestion dynamique de priorité
    FIXED_LIGHT,  // Feu avec cycle fixe
    FOUR_WAY_STOP // Intersection avec 4 stops
};


enum class Direction {
    Nord, 
    Sud, 
    Est, 
    Ouest 
};


