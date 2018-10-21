/********************************************
* Titre: Travail pratique #2 - utilisateur.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene & David Dratwa 
*******************************************/

#include "utilisateur.h"
#include "utilisateurPremium.h"

// Constructeurs



// Methodes d'acces


Utilisateur::Utilisateur(const string & nom, TypeUtilisateur type) : nom_(nom), type_(type), interet_(0), totalDepense_(0)
{
}

Utilisateur::Utilisateur(const Utilisateur & utilisateur): nom_(utilisateur.nom_), type_(utilisateur.type_), interet_(utilisateur.interet_), depenses_(utilisateur.interet_), totalDepense_(utilisateur.totalDepense_)
{
}

Utilisateur::~Utilisateur()
{
}

string Utilisateur::getNom() const {
	return nom_;
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
		
		if (dep->getType() == groupe) {
			totalDepense_ += dep->getMontant() / static_cast<DepenseGroupe*>(dep)->getNombreParticipants();
			
		}
		else {
			totalDepense_ += dep->getMontant();
		}
			
	}
	

}

double Utilisateur::getTotalDepenses() const {
	return totalDepense_;
}

Utilisateur& Utilisateur::operator=(Utilisateur * utilisateur)
{
	interet_ = utilisateur->getInteret();
	nom_ = utilisateur->getNom();
	type_ = utilisateur->getType();
	totalDepense_ = utilisateur->getTotalDepenses();
	depenses_ = utilisateur->getDepenses();
	return *this;
}


Utilisateur& Utilisateur::operator+=(Depense* depense) {
	depenses_.push_back(depense);
	calculerTotalDepenses();
	return *this;
}

// Methode d'affichage
ostream& operator<<(ostream& os, const Utilisateur& utilisateur)
{
	string typeStr;
	if (utilisateur.getType() == Premium) {
		typeStr = "Premium";
	}
	else {
		typeStr = "Regulier";
	}

	os << "Utilisateur " << utilisateur.getNom() << "(" << typeStr <<") a depense pour un total de : " << utilisateur.getTotalDepenses()
		<< " Polycount prend en interet : " << utilisateur.getInteret() << " Voici les depense:";
	for (auto &dep : utilisateur.getDepenses()) {
		if (dep->getType() == groupe) {
			os << "\n\t"<< *static_cast<DepenseGroupe*>(dep);
		}
		else {
			os << "\n\t" << *dep;
		}


	}
	
	if (utilisateur.getType() == Premium) {
		double taux = 5 - 1*floor(utilisateur.getDepenses().size() / 2);
		os << "\n\tTaux final: " << taux << "%";
	}
	
	return os<<endl;
}
