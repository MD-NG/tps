/********************************************
* Titre: Travail pratique #2 - depense.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#include "depense.h"

// Constucteurs
Depense::Depense() : nom_(""), montant_(0), lieu_(nullptr) {
}

Depense::Depense(const string& nom, double montant, const string& lieu) : nom_(nom), montant_(montant) {
	lieu_ = new string(lieu);
}

Depense::Depense(const Depense & dep): nom_(dep.getNom()), montant_(dep.getMontant()){
	lieu_ = new string(dep.getLieu());
}

Depense::~Depense()
{
	delete lieu_;
}

// Methodes d'acces
string Depense::getNom() const {
	return nom_;
}

double Depense::getMontant() const {
	return montant_;
}

string Depense::getLieu() const
{
	return *lieu_;
}

// Methodes de modifications
void Depense::setNom(const string& nom) {
	nom_ = nom;
}

void Depense::setMontant(double montant) {
	montant_ = montant;
}

void Depense::setLieu(const string& lieu)
{
	delete lieu_;
	lieu_ = new string(lieu);
}

// Methode d'affichage
void Depense::afficherDepense() const {
	cout << "Achat : " << nom_ << " Prix : " << montant_ << "; " << endl;
}

Depense Depense::operator=(const Depense & dep) 
{
	if (lieu_ != nullptr) {
		delete lieu_;
		lieu_=new string (dep.getLieu());
	}
	else {
		lieu_ = new string(dep.getLieu());
	}
	
	nom_ = dep.getNom();
	montant_ = dep.getMontant();
	return *this;
}

ostream & operator<<(ostream & os, const Depense& dep)
{
	return os << "Achat: " << dep.getNom() << " Prix: " << dep.getMontant()<< ";";
}


