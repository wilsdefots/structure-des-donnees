// structure_donnees_tp1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <iostream>


#include"Vehicule.h" 

int main()
{
    Vehicule* voiture = new Vehicule();

    voiture->display(); 
    voiture->increaseWaitTime(6); 
    voiture->display(); 
    voiture->decreaseWaitTime(); 
    std::cout << voiture->getWaitTime(); 

    return 0; 

}
