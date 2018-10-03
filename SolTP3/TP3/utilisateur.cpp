/********************************************
* Titre: Travail pratique #2 - utilisateur.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene & David Dratwa 
*******************************************/

#include "utilisateur.h"

// Constructeurs



// Methodes d'acces


Utilisateur::Utilisateur(const string & nom, TypeUtilisateur type) : nom_(nom), type_(type), interet_(0), totalDepense_(0)
{
}

Utilisateur::Utilisateur(const Utilisateur & utilisateur): nom_(utilisateur.nom_), type_(utilisateur.type_), interet_(utilisateur.interet_), depenses_(utilisateur.interet_), totalDepense_(utilisateur.totalDepense)
{
}

string Utilisateur::getNom() const {
	return nom_;
}

double Utilisateur::getTotalDepenses() const {
	calculerTotalDepenses;
	return totalDepense_;
}

TypeUtilisateur Utilisateur::getType() const {
	return type_; 
}

double Utilisateur::getInteret() const {
	return interet_; 
}

unsigned int Utilisateur::getNombreDepenses() const {
	
	return depenses_.size();
}

vector <Depense*> Utilisateur::getDepenses() const {
	return depenses_; 
}

//Methodes de modification
void Utilisateur::setNom(const string& nom) {
	nom_ = nom;
}

void Utilisateur::calculerTotalDepenses() {
	totalDepense_ = 0;
	for (auto& dep : depenses_) {
		totalDepense_ += dep->getMontant;
	}

}

Utilisateur& Utilisateur::operator=(Utilisateur * utilisateur)
{
	interet_ = utilisateur->getInteret();
	nom_ = utilisateur->getNom();
	type_ = utilisateur->getType();
	totalDepense_ = utilisateur->getTotalDepenses();
	depenses_ = utilisateur->getDepenses();

}


void Utilisateur::ajouterInteret(double montant) {
	interet_ += montant;
}

Utilisateur& Utilisateur::operator+=(Depense* depense) {
	depenses_.push_back(depense);
	calculerTotalDepenses;
}

// Methode d'affichage
ostream& operator<<(ostream& os, const Utilisateur& utilisateur)

{

}
