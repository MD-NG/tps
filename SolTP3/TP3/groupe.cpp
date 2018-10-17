/********************************************
* Titre: Travail pratique #2 - groupe.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene & David Dratwa
*******************************************/

#include "groupe.h"
#include <algorithm>

// Constructeurs

Groupe::Groupe() {
	nom_ = ""; 
}
Groupe::Groupe(const string& nom) : nom_(nom) {
}

Groupe::~Groupe() {
	for (int i = 0; i < transferts_.size(); i++) {
		delete transferts_[i];
	}
}


// Methodes d'acces
string Groupe::getNom() const {
	return nom_;
}

vector<DepenseGroupe*> Groupe::getDepenses() const
{
	return depenses_;
}

vector<Utilisateur*> Groupe::getUtilisateurs() const
{
	return utilisateurs_;
}

vector<Transfert*> Groupe::getTransferts() const
{
	return transferts_;
}


double Groupe::getTotalDepenses() const {

	return totalDepenses_;
}

// Methodes de modifications
void Groupe::setNom(const string& nom) {
	nom_ = nom;
}

// Methodes d'ajout
Groupe& Groupe::ajouterDepense(Depense* depense, Utilisateur* payePar, vector<Utilisateur*> payePour)
{
	if (depense->getType == groupe) {
		bool utilisateurPresents = true;
		for (auto &u: payePour) {
			if ( find(payePour.begin(), payePour.end(), u) == payePour.end()  ) {
				utilisateurPresents = false;
				break;
			}
		}
		if (utilisateurPresents) {
			depenses_.push_back(static_cast<DepenseGroupe*> (depense));
			auto pos = distance(utilisateurs_.begin(), find(utilisateurs_.begin(), utilisateurs_.end(), payePar));
			double prixInd = depense->getMontant()/static_cast<DepenseGroupe*>(depense)->getNombreParticipants();
			
			comptes_[pos] -= prixInd;

			for (auto &u : payePour) {
				pos = distance(utilisateurs_.begin(), find(utilisateurs_.begin(), utilisateurs_.end(), u));
				comptes_[pos] += prixInd;
			}
		}
		cout << "Erreur: utilisateur non présent";
	}
	cout << "Erreur: la dépense n'est pas de type groupe";
}

Groupe& Groupe::operator+=(Utilisateur* utilisateur)
{
	if (find(utilisateurs_.begin(), utilisateurs_.end(), utilisateur) == utilisateurs_.end()) {
		if (utilisateur->getType == Premium) {
			if (static_cast<UtilisateurPremium> (*utilisateur).getJoursRestants() != 0) {
				utilisateurs_.push_back(utilisateur);
				comptes_.push_back(utilisateur->getTotalDepenses());
			}
			else {
				cout<< "erreur";
			}				
		}
		else
		{
			utilisateurs_.push_back(utilisateur);
			comptes_.push_back(utilisateur->getTotalDepenses());
		}
	}
}

void Groupe::equilibrerComptes() {
	
	bool calcul = true;
	int count = 0;
	while (calcul) {
		double max = 0;
		double min = 0;
		int indexMax = 0;
		int indexMin = 0;

		// On cherche le compte le plus eleve et le moins eleve
		for (int i = 0; i < utilisateurs_.size(); i++) {
			if (comptes_[i] > max) {
				max = comptes_[i];
				indexMax = i;
			}
			if (comptes_[i] < min) {
				min = comptes_[i];
				indexMin = i;
			}
		}

		// On cherche lequel des deux a la dette la plus grande
		if (-min <= max && min != 0 && max != 0) {
			transferts_.push_back(new Transfert(-min, utilisateurs_[indexMin], utilisateurs_[indexMax]));
			comptes_[indexMax] += min;
			comptes_[indexMin] = 0;
	
		}
		else if (-min > max  && min != 0 && max != 0) {
			transferts_.push_back(new Transfert(max, utilisateurs_[indexMin], utilisateurs_[indexMax]));
			comptes_[indexMax] = 0;
			comptes_[indexMin] += max;
			

		}

		// On incremente le nombre de comptes mis a 0
		count++;
		if (-min == max) {
			count++;
		}
		if (count >= utilisateurs_.size() - 1) {
			calcul = false;
		}
	}
	
}

void Groupe::calculerTotalDepense() {
	for (auto &u : utilisateurs_) {
		u->calculerTotalDepenses;
	}

	totalDepenses_ = 0;
	for (auto &d : depenses_) {
		totalDepenses_ += d->getMontant();
	}

}

// Methode d'affichage
ostream & operator<<(ostream& os, const Groupe& groupe)
{
	
}
