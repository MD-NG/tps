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



void updateInteret(Utilisateur* u, double montant) {
	double taux = 0.05;
	if (u->getType() == Premium) {
		static_cast<UtilisateurPremium*> (u)->calculerTaux();
		taux = static_cast<UtilisateurPremium*> (u)->getTaux();

	}
	u->ajouterInteret(montant*taux);
}

// Methodes d'ajout
Groupe& Groupe::ajouterDepense(Depense* depense, Utilisateur* payePar, vector<Utilisateur*> payePour)
{
	if (depense->getType() == groupe) {
		bool utilisateurPresents = true;
		if (find(utilisateurs_.begin(), utilisateurs_.end(), payePar) == utilisateurs_.end()) {
			 utilisateurPresents = false;
		}
		else {
			utilisateurPresents = true;
			for (auto &u: payePour) {
				if ( find(utilisateurs_.begin(), utilisateurs_.end(), u) == utilisateurs_.end()  ) {
					utilisateurPresents = false;
					break;
				}
			}
		}

		if (utilisateurPresents) {
			depenses_.push_back(static_cast<DepenseGroupe*> (depense));
			static_cast<DepenseGroupe*> (depense)->setNombreParticipants(payePour.size()+1);
			auto pos = distance(utilisateurs_.begin(), find(utilisateurs_.begin(), utilisateurs_.end(), payePar));
			double prixInd = depense->getMontant()/(payePour.size()+1);
			comptes_[pos] += depense->getMontant()-prixInd;
			*payePar += depense;
	

			for (auto &u : payePour) {
				pos = distance(utilisateurs_.begin(), find(utilisateurs_.begin(), utilisateurs_.end(), u));
				comptes_[pos] -= prixInd;
				*u += depense;

			}

		}
		cout << "\nErreur: utilisateur non present dans le groupe"<< endl;
	}
	cout << "\nErreur: la depense n'est pas de type groupe"<< endl;
	return *this;
}

Groupe& Groupe::operator+=(Utilisateur* utilisateur)
{
	if (find(utilisateurs_.begin(), utilisateurs_.end(), utilisateur) == utilisateurs_.end()) {
		if (utilisateur->getType() == Premium) {
			if (static_cast<UtilisateurPremium*> (utilisateur)->getJoursRestants() != 0) {
				utilisateurs_.push_back(utilisateur);
				comptes_.push_back(0);
			}
			else {
				cout<< "Erreur: l'utilisateur "<< utilisateur->getNom() << " doit renouveler son abonnement premium";
			}				
		}
		else
		{
			utilisateurs_.push_back(utilisateur);
			comptes_.push_back(0);
		}
	}
	return *this;
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
			if (utilisateurs_[indexMin]->getType() == Premium) {
				static_cast<UtilisateurPremium*> (utilisateurs_[indexMin])->calculerTaux();
				double taux = static_cast<UtilisateurPremium*> (utilisateurs_[indexMin])->getTaux();
				utilisateurs_[indexMin]->ajouterInteret(-min*taux);
			}
			else
			{
				utilisateurs_[indexMin]->ajouterInteret(-min * 0.05);
			}
			
	
		}
		else if (-min > max  && min != 0 && max != 0) {
			transferts_.push_back(new Transfert(max, utilisateurs_[indexMin], utilisateurs_[indexMax]));
			comptes_[indexMax] = 0;
			comptes_[indexMin] += max;
			if (utilisateurs_[indexMin]->getType() == Premium) {
				static_cast<UtilisateurPremium*> (utilisateurs_[indexMin])->calculerTaux();
				double taux = static_cast<UtilisateurPremium*> (utilisateurs_[indexMin])->getTaux();
				utilisateurs_[indexMin]->ajouterInteret(max * taux);
			}
			else
			{
				utilisateurs_[indexMin]->ajouterInteret(max * 0.05);
			}
			

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
		u->calculerTotalDepenses();
	}

	totalDepenses_ = 0;
	for (auto &d : depenses_) {
		totalDepenses_ += d->getMontant();
	}

}

// Methode d'affichage
ostream & operator<<(ostream& os, const Groupe& groupe)
{
	os << "L'evenement nomme : "<< groupe.getNom() << " a coute un total (en terme de depenses groupees: " << groupe.getTotalDepenses()
		<< ", voici les utilisateurs et toute leur depense :";
	for (auto &u : groupe.getUtilisateurs()) {

		os << "\n" << *u;

	}

	os << "\n\nLes transfert suivants ont ete effectue: \n";
	for (auto &tf : groupe.getTransferts()) {
		os << *tf;

	}

	os << endl;
	return os;
}
