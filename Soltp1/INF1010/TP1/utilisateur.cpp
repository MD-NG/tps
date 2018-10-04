#include "utilisateur.h"


Utilisateur::Utilisateur() {
	nom_ = "";
	tailleTabDepense_ = TAILLE_DEPENSES;
	nombreDepenses_ = 0;
	listeDepenses_ = new Depense*[tailleTabDepense_];
	for (unsigned int i=0; i < tailleTabDepense_; i++) {
		listeDepenses_[i] = nullptr;
	}
	
	totalDepense_ = 0;
};

Utilisateur::Utilisateur(string& nom) {
	
	nom_ = nom;
	tailleTabDepense_ = TAILLE_DEPENSES;
	nombreDepenses_ = 0;
	listeDepenses_ = new Depense*[tailleTabDepense_];
	for (unsigned int i = 0; i < tailleTabDepense_; i++) {
		listeDepenses_[i] = nullptr;
	}

	totalDepense_ = 0;
};

//Destructeur
Utilisateur::~Utilisateur() {
	if (listeDepenses_ != nullptr) {
		delete[] listeDepenses_;
	}
	listeDepenses_ = nullptr;
};

//Methodes d'accès
string Utilisateur::getNom() {
	return nom_;
};
unsigned int Utilisateur::getNombreDepense() {
	return nombreDepenses_;
};
double Utilisateur::getTotal() {
	calculerTotal();
	return totalDepense_;
};

//Methode de modification
void Utilisateur::setNom(string& nom) {
	nom_ = nom;
};

// Methode ajout de depense
void Utilisateur::ajouterDepense(Depense* uneDepense) {
	if (nombreDepenses_ < tailleTabDepense_) {
		listeDepenses_[nombreDepenses_] = uneDepense;
	}
	else {
		tailleTabDepense_ *= 2;
		Depense** listeDepensesTemp = new Depense*[tailleTabDepense_];
		for (unsigned int i=0; i < nombreDepenses_; i++) {
			listeDepensesTemp[i] = listeDepenses_[i];
		}
		listeDepensesTemp[nombreDepenses_]=uneDepense;
		delete[] listeDepenses_;
		listeDepenses_ = listeDepensesTemp;
	}
	nombreDepenses_++;
};

//Methode de calcul total
void Utilisateur::calculerTotal() {
	double total=0;
	for (unsigned int i = 0; i < nombreDepenses_; i++) {
		total=total+listeDepenses_[i]->getMontant();
	}
	totalDepense_ = total;
};

//Mathode d'affichage
void Utilisateur::afficherUtilisateur()
{
	cout << "\n\tUtilisateur : " << nom_ << " a depense pour un total : " << totalDepense_ << "\n\tListe de depenses :  \n";
	for (unsigned int i = 0; i < nombreDepenses_; i++) {
		
		listeDepenses_[i]->afficherDepense();
	}
	
}