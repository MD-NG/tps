/********************************************
* Titre: Travail pratique #2 - utilisateur.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#include "utilisateur.h"

// Constructeurs
Utilisateur::Utilisateur() : nom_(""){
}

Utilisateur::Utilisateur(const string& nom)
	: nom_(nom) {
}

Utilisateur::Utilisateur(const Utilisateur & u)
{
	(*this).nom_ = u.getNom();
}

//Destructeur
Utilisateur::~Utilisateur() {
}

// Methodes d'acces
string Utilisateur::getNom() const {
	return nom_;
}

unsigned int Utilisateur::getNombreDepense() const {
	return depenses_.size();
}

double Utilisateur::getTotalDepenses() const {
	double total=0;
	for (auto &dep : depenses_) {
		total += dep->getMontant();
	}
	return total;
}

vector<Depense*> Utilisateur::getDepenses() const
{
	return depenses_;
}

//Methodes de modification
void Utilisateur::setNom(const string& nom) {
	nom_ = nom;
}



// Methode d'affichage


Utilisateur Utilisateur::operator=(const Utilisateur & u)
{
	depenses_.clear();
	depenses_ = u.getDepenses();
	nom_ = u.getNom();

	return *this;
}

Utilisateur Utilisateur::operator+=(Depense* dep)
{
	depenses_.push_back(dep);
	return *this;
}

ostream & operator<<(ostream& os, const Utilisateur & u)
{
	// TODO: insert return statement here
	os << "utilisateur: " << u.getNom() << "a depense pour un totat de :" << u.getTotalDepenses() << "\n\tListe depense :\n";
	for (auto& dep: u.getDepenses()) {
		os << "\t\t"<< *dep<<"\n";
	}
	os << endl;
	return os;
}
