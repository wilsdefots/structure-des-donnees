// structure_donnees_tp1.cpp :
// Ce fichier contient la fonction 'main'. 
// L'exécution du programme commence 
// et se termine à cet endroit.
//

#include <iostream>
#include <iostream>
#include "FileAttente.h"


#include"Vehicule.h"





int main()
{

    Vehicule maVoiture  ; 
    Vehicule laVoiture("N002","Nissan");
    SimpleNode*  noeud1 = new SimpleNode(maVoiture); 
    SimpleNode* noeud2 = new SimpleNode(laVoiture);
    FileVehicule* file = new FileVehicule(); 
    file->enqueue(noeud1);
    file->enqueue(noeud2); 
    
    file->display();
    return 0; 

}
