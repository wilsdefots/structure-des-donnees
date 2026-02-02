#pragma once
#include "Vehicule.h" 

struct DoubleNode {
    Vehicule* vehicule;
    DoubleNode* next;
    DoubleNode* prev;
    DoubleNode(Vehicule*& unVehicule) : vehicule(unVehicule),
        next(nullptr), prev(nullptr) {
    }
};
