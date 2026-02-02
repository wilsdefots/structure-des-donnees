#pragma once
#include "Vehicule.h"


struct SimpleNode
{
    Vehicule vehiculeCourant;
    SimpleNode* next;
    SimpleNode(Vehicule ceVehicule) : vehiculeCourant(ceVehicule),next(nullptr){}
    SimpleNode( ) : vehiculeCourant(Vehicule("inconnu", "inconnu", " ", 0)), next(nullptr) {
    }
};