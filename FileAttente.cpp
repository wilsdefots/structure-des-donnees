#include "FileAttente.h"


FileVehicule::~FileVehicule(){
	while (!isEmpty()) {
		dequeue();
	}
}

// Vérifier si la file est vide
bool FileVehicule::isEmpty() const {
	return this->head == nullptr;
}

// Consulter le premier vehicule sans le retirer
Vehicule* FileVehicule::peek() const {
	if (this->isEmpty()) {
		std::cout << " Aucun vehicule sur cette file ! " << std::endl; 
		return nullptr; // on retourne le vehicule inconnu, qui represente aucun vehicule
	}
	std::cout << " Le vehicule es tete est : " ;
	this->head->vehiculeCourant.display();
	// j ai deja la tete, mais je suis obligé de retourner un pointeur. Donc je le créé
	Vehicule* vehiculeEntete = new Vehicule(this->head->vehiculeCourant); 

	
	return  vehiculeEntete;   
}

// accès au nombre de véhicules dans la pile
int FileVehicule::size()  const {
	int size = 0; 
	SimpleNode* noeudCourant = this->head; 

	while (noeudCourant != nullptr) {
		size++;
		noeudCourant = noeudCourant->next;
		}
	return size;
}

// ajout d'un vehicule (à la queue)
void FileVehicule::enqueue(SimpleNode* &simpleNoeudSuivant)
{ // un soeud simple est une voiture (vehicule courant) et sa fleche (next)
	if (this->isEmpty()) {
		this->head = simpleNoeudSuivant;
		this->queue = simpleNoeudSuivant; 
		return;
	}
	this->queue->next = simpleNoeudSuivant; //on relit la queue au vehicule qui s'ajoute
	this->queue = simpleNoeudSuivant; //la queue devient le nouveau vehicule
	
	 
}

void FileVehicule::dequeue()
{ //on retire la tete
	if (this->isEmpty()) {
		return;
	}
	 
	if (this->head->next = nullptr) { // il y avait un seul elt qu on veut retirer
		this->queue = nullptr; //la file devient alors vide
		return; 
		/*Je pouvais utiliser size ici, mais j'ai voulu rester pure */
	}
	SimpleNode* temp = this->head; //La copie des pointeurs se fait tjrs par reference
	this->head = this->head->next; 
	delete temp; /* pas de fuite de memoire, par ce que, grace à la copie par reference,
	en supprimant temp, l'ancien head eest effectivement supprimé */

}

// parcourt de tous les vehicules pour affichage
void FileVehicule::display() const
{
	int nroVehicule = 1; 
	if (this->isEmpty()) {
		std::cout << " \n La file est vide ! "; 
		return;
	}
	SimpleNode* noeudCourant = this->head;
	while (noeudCourant != nullptr) {
		std::cout << "Vehicule nro " << nroVehicule << std::endl; 
		noeudCourant->vehiculeCourant.display();
		nroVehicule++; 
		noeudCourant = noeudCourant->next; 
		std::cout << std::endl; 
	}


}


