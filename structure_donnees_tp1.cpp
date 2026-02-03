// structure_donnees_tp1.cpp :
// Ce fichier contient la fonction 'main'. 
// L'exécution du programme commence 
// et se termine à cet endroit.
//
#include <iostream>
#include "Intersection.h"
#include "Road.h"
#include "Vehicule.h"
#include "FileVehicule.h"
#include"Compteur.h"

int main() {
    std::cout << "=== TEST DU SYSTEME D'INTERSECTION ===" << std::endl;

    // 1. Créer les files de véhicules pour chaque route
    FileVehicule* fileNord = new FileVehicule();
    FileVehicule* fileSud = new FileVehicule();
    FileVehicule* fileEst = new FileVehicule();
    FileVehicule* fileOuest = new FileVehicule();

    // 2. Créer les routes
    Road* routeNord = new Road("Route Nord", fileNord, Direction::Nord);
    Road* routeSud = new Road("Route Sud", fileSud, Direction::Sud);
    Road* routeEst = new Road("Route Est", fileEst, Direction::Est);
    Road* routeOuest = new Road("Route Ouest", fileOuest, Direction::Ouest);

    // 3. Créer l'intersection (tu peux tester différents types)
    std::cout << "\n--- Test avec FIXED_LIGHT ---\n" << std::endl;
    Intersection intersection1("Intersection Principale",
        intersectionType::FIXED_LIGHT,
        routeNord, routeSud, routeEst, routeOuest);

    // 4. Ajouter des véhicules sur différentes routes
    std::cout << "\n=== Ajout de vehicules ===" << std::endl;

    // Route Nord : 3 véhicules
    routeNord->addVehicule(Vehicule("ABC123", "Voiture", "Downtown"));
    routeNord->addVehicule(Vehicule("DEF456", "Camion", "Suburbs"));
    routeNord->addVehicule(Vehicule("GHI789", "Moto", "Airport"));

    // Route Sud : 2 véhicules
    routeSud->addVehicule(Vehicule("JKL012", "Voiture", "Mall"));
    routeSud->addVehicule(Vehicule("MNO345", "Bus", "School"));

    // Route Est : 4 véhicules (plus chargée)
    routeEst->addVehicule(Vehicule("PQR678", "Voiture", "Hospital"));
    routeEst->addVehicule(Vehicule("STU901", "Ambulance", "Emergency"));
    routeEst->addVehicule(Vehicule("VWX234", "Taxi", "Station"));
    routeEst->addVehicule(Vehicule("YZA567", "Voiture", "Home"));

    // Route Ouest : 1 véhicule
    routeOuest->addVehicule(Vehicule("BCD890", "Camion", "Port"));

    // 5. Afficher l'état initial
    std::cout << "\n=== ETAT INITIAL ===" << std::endl;
    intersection1.display();

    // 6. Simuler plusieurs tours de circulation
    std::cout << "\n=== SIMULATION DE 10 TOURS ===" << std::endl;
    for (int i = 1; i <= 10; i++) {
        std::cout << "\n\n********** TOUR " << i << " **********" << std::endl;
        intersection1.processTurn();

        // Afficher l'état tous les 3 tours
        if (i % 3 == 0) {
            intersection1.display();
        }
    }

    // 7. Afficher l'état final
    std::cout << "\n=== ETAT FINAL ===" << std::endl;
    intersection1.display();


    // 8. Test avec PRIORITY_LIGHT
    std::cout << "\n\n\n=== Test avec PRIORITY_LIGHT ===" << std::endl;

    // Créer de nouvelles files et routes
    FileVehicule* fileNord2 = new FileVehicule();
    FileVehicule* fileSud2 = new FileVehicule();
    FileVehicule* fileEst2 = new FileVehicule();
    FileVehicule* fileOuest2 = new FileVehicule();

    Road* routeNord2 = new Road("Route Nord 2", fileNord2, Direction::Nord);
    Road* routeSud2 = new Road("Route Sud 2", fileSud2, Direction::Sud);
    Road* routeEst2 = new Road("Route Est 2", fileEst2, Direction::Est);
    Road* routeOuest2 = new Road("Route Ouest 2", fileOuest2, Direction::Ouest);

    Intersection intersection2("Intersection Prioritaire",
        intersectionType::PRIORITY_LIGHT,
        routeNord2, routeSud2, routeEst2, routeOuest2);

    // Ajouter beaucoup de véhicules à l'Est pour tester la priorité
    routeEst2->addVehicule(Vehicule("EAST1", "Voiture", "A"));
    routeEst2->addVehicule(Vehicule("EAST2", "Voiture", "B"));
    routeEst2->addVehicule(Vehicule("EAST3", "Voiture", "C"));
    routeEst2->addVehicule(Vehicule("EAST4", "Voiture", "D"));
    routeEst2->addVehicule(Vehicule("EAST5", "Voiture", "E"));

    // Peu de véhicules au Nord
    routeNord2->addVehicule(Vehicule("NORTH1", "Voiture", "X"));

    std::cout << "\n=== ETAT INITIAL (Priorité) ===" << std::endl;
    intersection2.display();

    std::cout << "\n=== SIMULATION DE 8 TOURS (Priorité) ===" << std::endl;
    for (int i = 1; i <= 8; i++) {
        std::cout << "\n\n********** TOUR " << i << " **********" << std::endl;
        intersection2.processTurn();
    }

    intersection2.display();


    // 9. Test avec FOUR_WAY_STOP
    std::cout << "\n\n\n=== Test avec FOUR_WAY_STOP ===" << std::endl;

    FileVehicule* fileNord3 = new FileVehicule();
    FileVehicule* fileSud3 = new FileVehicule();
    FileVehicule* fileEst3 = new FileVehicule();
    FileVehicule* fileOuest3 = new FileVehicule();

    Road* routeNord3 = new Road("Route Nord 3", fileNord3, Direction::Nord);
    Road* routeSud3 = new Road("Route Sud 3", fileSud3, Direction::Sud);
    Road* routeEst3 = new Road("Route Est 3", fileEst3, Direction::Est);
    Road* routeOuest3 = new Road("Route Ouest 3", fileOuest3, Direction::Ouest);

    Intersection intersection3("Intersection 4-Stop",
        intersectionType::FOUR_WAY_STOP,
        routeNord3, routeSud3, routeEst3, routeOuest3);

    // Un véhicule par direction
    routeNord3->addVehicule(Vehicule("N1", "Voiture", "A"));
    routeSud3->addVehicule(Vehicule("S1", "Voiture", "B"));
    routeEst3->addVehicule(Vehicule("E1", "Voiture", "C"));
    routeOuest3->addVehicule(Vehicule("O1", "Voiture", "D"));

    std::cout << "\n=== ETAT INITIAL (4-Stop) ===" << std::endl;
    intersection3.display();

    std::cout << "\n=== SIMULATION DE 5 TOURS (4-Stop) ===" << std::endl;
    for (int i = 1; i <= 5; i++) {
        std::cout << "\n\n********** TOUR " << i << " **********" << std::endl;
        intersection3.processTurn();
    }

    intersection3.display();


    // 10. Nettoyage de la mémoire
    std::cout << "\n=== FIN DES TESTS ===" << std::endl;

    // Note: Les destructeurs de FileVehicule et Road s'occupent du nettoyage
    delete routeNord;
    delete routeSud;
    delete routeEst;
    delete routeOuest;

    delete routeNord2;
    delete routeSud2;
    delete routeEst2;
    delete routeOuest2;

    delete routeNord3;
    delete routeSud3;
    delete routeEst3;
    delete routeOuest3;

    std::cout << Compteur::getInformation() << endl;
    std::cin.get();

    return 0;
}