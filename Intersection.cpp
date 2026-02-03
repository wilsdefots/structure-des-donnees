#include "Intersection.h"


Intersection::Intersection(std::string nom, intersectionType typeIntersection,
    Road* nord, Road* sud, Road* est, Road* ouest)
{
    this->name = nom;
    this->type = typeIntersection;
    this->northroad = nord;
    this->southRoad = sud;
    this->eastRoad = est;
    this->westRoad = ouest;

    // Au début, Nord-Sud est vert, Est-Ouest est rouge par defaut
    this->northSouthLight = TrafficLightState::GREEN;
    this->eastWestLight = TrafficLightState::RED;

    this->cycleCounter = 0;
    this->greenDuration = 3;      // 3 tours minimum
    this->maxGreenDuration = 5;   // 5 tours maximum
}

Intersection::Intersection()
{
    this->name = "Boulevard Saint Paul";
    this->type = intersectionType::FIXED_LIGHT;

    // On crée une file vide pour chaque route
    FileVehicule* fileNord = new FileVehicule();
    FileVehicule* fileSud = new FileVehicule();
    FileVehicule* fileEst = new FileVehicule();
    FileVehicule* fileOuest = new FileVehicule();

    // On crée les routes
    this->northroad = new Road("Nord", fileNord, Direction::Nord);
    this->southRoad = new Road("Sud", fileSud, Direction::Sud);
    this->eastRoad = new Road("Est", fileEst, Direction::Est);
    this->westRoad = new Road("Ouest", fileOuest, Direction::Ouest);

    // Feux initiaux
    this->northSouthLight = TrafficLightState::GREEN;
    this->eastWestLight = TrafficLightState::RED;

    this->cycleCounter = 0;
    this->greenDuration = 3;
    this->maxGreenDuration = 5;
}

Intersection::~Intersection()
{
    // On supprime les routes si elles existent
    if (northroad != nullptr) {
        delete northroad;
        northroad = nullptr;
    }

    if (southRoad != nullptr) {
        delete southRoad;
        southRoad = nullptr;
    }

    if (eastRoad != nullptr) {
        delete eastRoad;
        eastRoad = nullptr;
    }

    if (westRoad != nullptr) {
        delete westRoad;
        westRoad = nullptr;
    }
}



// Traite un tour de circulation
void Intersection::processTurn()
{
    std::cout << "\n=== Tour de circulation ===" << std::endl;

    // On augmente le temps d'attente de TOUS les véhicules
    this->northroad->increaseAllWaitTimes();
    this->southRoad->increaseAllWaitTimes();
    this->eastRoad->increaseAllWaitTimes();
    this->westRoad->increaseAllWaitTimes();

    // Selon le type d'intersection
    if (this->type == intersectionType::FIXED_LIGHT) {
        // Feu fixe simple
        if (this->northSouthLight == TrafficLightState::GREEN) {
            // Nord et Sud peuvent passer
            if (!this->northroad->getFileDeVehicule()->isEmpty()) {
                Vehicule* v = this->northroad->getNextVehicule();
                std::cout << "Vehicule passe du Nord : ";
                v->display();
                delete v;
            }
            if (!this->southRoad->getFileDeVehicule()->isEmpty()) {
                Vehicule* v = this->southRoad->getNextVehicule();
                std::cout << "Vehicule passe du Sud : ";
                v->display();
                delete v;
            }
        }
        else {
            // Est et Ouest peuvent passer
            if (!this->eastRoad->getFileDeVehicule()->isEmpty()) {
                Vehicule* v = this->eastRoad->getNextVehicule();
                std::cout << "Vehicule passe de l'Est : ";
                v->display();
                delete v;
            }
            if (!this->westRoad->getFileDeVehicule()->isEmpty()) {
                Vehicule* v = this->westRoad->getNextVehicule();
                std::cout << "Vehicule passe de l'Ouest : ";
                v->display();
                delete v;
            }
        }
    }
    else if (this->type == intersectionType::PRIORITY_LIGHT) {
        // Feu avec priorité dynamique
        if (this->northSouthLight == TrafficLightState::GREEN) {
            // Nord et Sud passent
            if (!this->northroad->getFileDeVehicule()->isEmpty()) {
                Vehicule* v = this->northroad->getNextVehicule();
                std::cout << "Vehicule passe du Nord : ";
                v->display();
                delete v;
            }
            if (!this->southRoad->getFileDeVehicule()->isEmpty()) {
                Vehicule* v = this->southRoad->getNextVehicule();
                std::cout << "Vehicule passe du Sud : ";
                v->display();
                delete v;
            }
        }
        else {
            // Est et Ouest passent
            if (!this->eastRoad->getFileDeVehicule()->isEmpty()) {
                Vehicule* v = this->eastRoad->getNextVehicule();
                std::cout << "Vehicule passe de l'Est : ";
                v->display();
                delete v;
            }
            if (!this->westRoad->getFileDeVehicule()->isEmpty()) {
                Vehicule* v = this->westRoad->getNextVehicule();
                std::cout << "Vehicule passe de l'Ouest : ";
                v->display();
                delete v;
            }
        }
    }
    else if (this->type == intersectionType::FOUR_WAY_STOP) {
        // 4 stops : on cherche le véhicule qui attend le plus longtemps
        Vehicule* plusAncien = nullptr;
        Road* routeChoisie = nullptr;
        int tempsMax = -1;

        // On regarde chaque route
        if (!this->northroad->getFileDeVehicule()->isEmpty()) {
            Vehicule* v = this->northroad->getFileDeVehicule()->peek();
            if (v != nullptr && v->getWaitTime() > tempsMax) {
                tempsMax = v->getWaitTime();
                routeChoisie = this->northroad;
            }
        }
        if (!this->southRoad->getFileDeVehicule()->isEmpty()) {
            Vehicule* v = this->southRoad->getFileDeVehicule()->peek();
            if (v != nullptr && v->getWaitTime() > tempsMax) {
                tempsMax = v->getWaitTime();
                routeChoisie = this->southRoad;
            }
        }
        if (!this->eastRoad->getFileDeVehicule()->isEmpty()) {
            Vehicule* v = this->eastRoad->getFileDeVehicule()->peek();
            if (v != nullptr && v->getWaitTime() > tempsMax) {
                tempsMax = v->getWaitTime();
                routeChoisie = this->eastRoad;
            }
        }
        if (!this->westRoad->getFileDeVehicule()->isEmpty()) {
            Vehicule* v = this->westRoad->getFileDeVehicule()->peek();
            if (v != nullptr && v->getWaitTime() > tempsMax) {
                tempsMax = v->getWaitTime();
                routeChoisie = this->westRoad;
            }
        }

        // On fait passer le véhicule qui a attendu le plus
        if (routeChoisie != nullptr) {
            Vehicule* v = routeChoisie->getNextVehicule();
            std::cout << "Vehicule passe (4-way stop) : ";
            v->display();
            delete v;
        }
    }

    // On incrémente le compteur de cycle
    this->cycleCounter++;

    // On met à jour les feux
    this->updateLights();
}

// Met à jour les feux
void Intersection::updateLights()
{
    if (this->type == intersectionType::FIXED_LIGHT) {
        // Changement tous les 3 tours
        if (this->cycleCounter >= this->greenDuration) {
            // On inverse les feux
            cycleCounter = 0;
            northSouthLight = (northSouthLight == TrafficLightState::GREEN) ?
                TrafficLightState::RED : TrafficLightState::GREEN;
            eastWestLight = (eastWestLight == TrafficLightState::GREEN) ?
                TrafficLightState::RED : TrafficLightState::GREEN;

            std::cout << "Feux changés !" << std::endl;
        }
    }
    else if (this->type == intersectionType::PRIORITY_LIGHT) {
        // On vérifie si on doit changer selon la densité
        Road* routeSurchargee = this->routeSurchargee();

        // Si on a atteint le minimum de tours vert
        if (this->cycleCounter >= this->greenDuration) {
            // On regarde si l'autre direction a plus de véhicules
            bool doitChanger = false;

            if (this->northSouthLight == TrafficLightState::GREEN) {
                // Nord-Sud est vert, on vérifie Est-Ouest
                int nbNordSud = this->northroad->getVehicleCount() + this->southRoad->getVehicleCount();
                int nbEstOuest = this->eastRoad->getVehicleCount() + this->westRoad->getVehicleCount();

                if (nbEstOuest > nbNordSud || this->cycleCounter >= this->maxGreenDuration) {
                    doitChanger = true;
                }
            }
            else {
                // Est-Ouest est vert, on vérifie Nord-Sud
                int nbNordSud = this->northroad->getVehicleCount() + this->southRoad->getVehicleCount();
                int nbEstOuest = this->eastRoad->getVehicleCount() + this->westRoad->getVehicleCount();

                if (nbNordSud > nbEstOuest || this->cycleCounter >= this->maxGreenDuration) {
                    doitChanger = true;
                }
            }

            if (doitChanger) {
                cycleCounter = 0;
                northSouthLight = (northSouthLight == TrafficLightState::GREEN) ?
                    TrafficLightState::RED : TrafficLightState::GREEN;
                eastWestLight = (eastWestLight == TrafficLightState::GREEN) ?
                    TrafficLightState::RED : TrafficLightState::GREEN;

                std::cout << "Feux changés (priorité) !" << std::endl;
            }
        }
    }
    // FOUR_WAY_STOP n'a pas de feux à mettre à jour
}

// Affiche l'état de l'intersection
void Intersection::display()
{
    std::cout << "\n========================================" << std::endl;
    std::cout << "Intersection : " << this->name << std::endl;
    std::cout << "Type : ";

    if (this->type == intersectionType::FIXED_LIGHT) {
        std::cout << "Feu fixe" << std::endl;
        std::cout << "Feu Nord-Sud : " << (northSouthLight == TrafficLightState::GREEN ? "VERT" : "ROUGE") << std::endl;
        std::cout << "Feu Est-Ouest : " << (eastWestLight == TrafficLightState::GREEN ? "VERT" : "ROUGE") << std::endl;
    }
    else if (this->type == intersectionType::PRIORITY_LIGHT) {
        std::cout << "Feu avec priorité" << std::endl;
        std::cout << "Feu Nord-Sud : " << (northSouthLight == TrafficLightState::GREEN ? "VERT" : "ROUGE") << std::endl;
        std::cout << "Feu Est-Ouest : " << (eastWestLight == TrafficLightState::GREEN ? "VERT" : "ROUGE") << std::endl;
    }
    else {
        std::cout << "4-way stop" << std::endl;
    }

    std::cout << "Compteur de cycle : " << this->cycleCounter << std::endl;
    std::cout << "\n--- Routes ---" << std::endl;

    std::cout << "\nRoute Nord (" << this->northroad->getVehicleCount() << " véhicules)" << std::endl;
    this->northroad->display();

    std::cout << "\nRoute Sud (" << this->southRoad->getVehicleCount() << " véhicules)" << std::endl;
    this->southRoad->display();

    std::cout << "\nRoute Est (" << this->eastRoad->getVehicleCount() << " véhicules)" << std::endl;
    this->eastRoad->display();

    std::cout << "\nRoute Ouest (" << this->westRoad->getVehicleCount() << " véhicules)" << std::endl;
    this->westRoad->display();

    std::cout << "========================================\n" << std::endl;
}

// Trouve la route la plus surchargée
Road* Intersection::routeSurchargee()
{
    Road* plusChargee = this->northroad;
    int maxVehicules = this->northroad->getVehicleCount();

    if (this->southRoad->getVehicleCount() > maxVehicules) {
        plusChargee = this->southRoad;
        maxVehicules = this->southRoad->getVehicleCount();
    }

    if (this->eastRoad->getVehicleCount() > maxVehicules) {
        plusChargee = this->eastRoad;
        maxVehicules = this->eastRoad->getVehicleCount();
    }

    if (this->westRoad->getVehicleCount() > maxVehicules) {
        plusChargee = this->westRoad;
        maxVehicules = this->westRoad->getVehicleCount();
    }

    return plusChargee;
}