/********************************************
* Titre: Travail pratique #2 - groupe.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#include "groupe.h"

// Constructeurs


Groupe::Groupe(const string & nom) :nom_(nom)
{
}

Groupe::~Groupe() {
	for (auto& tf : transferts_) {
		delete tf;
	}
}


// Methodes d'acces
string Groupe::getNom() const {
	return nom_;
}

unsigned int Groupe::getNombreDepenses() const {
	return depenses_.size();
}

double Groupe::getTotalDepenses() const {
	double total = 0;
	for (auto& dep : depenses_) {
		total += dep->getMontant();
	}
	return total;
}

// Methodes de modifications
void Groupe::setNom(const string& nom) {
	nom_ = nom;
}

// Methodes d'ajout
Groupe& Groupe::ajouterDepense(Depense* depense, Utilisateur* utilisateur) {
	bool userFound = false;
	for (auto& u : utilisateurs_) {
		if (u == utilisateur) {
			*u += depense;
			userFound = true;
			break;
		}
	}
	if (!userFound) {
		utilisateurs_.push_back(utilisateur);
		*utilisateurs_.back() += depense;
	}

	depenses_.push_back(depense);
	return (*this);
}

Groupe& Groupe::operator+=(Utilisateur* u)
{
	utilisateurs_.push_back(u);
	return (*this);
}



void Groupe::calculerComptes()
{
	comptes_.clear();
	double moyenne = getTotalDepenses() / utilisateurs_.size();
	for (auto& u:utilisateurs_) {
		comptes_.push_back(u->getTotalDepenses() - moyenne);
	}
}
unsigned int minVector(const vector<double>& v) {
	unsigned int minIndex = 0;
	for (unsigned int i = 0; i < v.size(); i++) {
		if (v[i] < v[minIndex]) {
			minIndex = i;
		}
	}
	return minIndex;
}
unsigned int maxVector(const vector<double>& v) {
	unsigned int maxIndex = 0;
	for (unsigned int i = 0; i < v.size(); i++) {
		if (v[i] > v[maxIndex]) {
			maxIndex = i;
		}
	}
	return maxIndex;
}
void Groupe::equilibrerComptes() {
	calculerComptes();
	bool calcul = true;
	int count = 0;
	using namespace std;
	unsigned int minIndex = minVector(comptes_);
	unsigned int maxIndex = maxVector(comptes_);
	double montantTF;
	double solde;
	if (!comptes_.empty()) {
		while (abs(comptes_[minIndex]) >=1e-9  || abs(comptes_[maxIndex]) >= 1e-9) {
			minIndex = minVector(comptes_);
			maxIndex = maxVector(comptes_);
			solde = comptes_[minIndex] + comptes_[maxIndex];
			montantTF = min(abs(comptes_[minIndex]), comptes_[maxIndex]);
			transferts_.push_back(new Transfert(montantTF, utilisateurs_[minIndex], utilisateurs_[maxIndex]));
			comptes_[minIndex] = min(0.0, solde);
			comptes_[maxIndex] = max(0.0, solde);
		}

	}


}


// Methode d'affichage

ostream & operator<<(ostream& os, const Groupe& grp)
{
	os << "L'evenement " << grp.getNom() << " a coute un total de " << grp.getTotalDepenses() << " :  \n\n";
	for (auto& u : grp.utilisateurs_) {
		os << *u;
	}
	os << endl;

	if (grp.transferts_.size() != 0) {
		cout << "Les transferts suivants ont ete realiser pour equilibrer  : " << endl;
		for (auto& tf : grp.transferts_) {
			os << "\t" << *tf;

		}
	}
	else {
		os << "Les comptes ne sont pas equilibres" << endl << endl;
	}
	os << endl;
	return os;
	
}
