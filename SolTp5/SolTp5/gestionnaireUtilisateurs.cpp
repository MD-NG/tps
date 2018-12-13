/********************************************
* Titre: Travail pratique #5 - gestionnaireUtilisateurs.cpp
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

#include "gestionnaireUtilisateurs.h"
#include "utilisateurPremium.h"
#include "utilisateurRegulier.h"

vector<double> GestionnaireUtilisateurs::getComptes() const
{
	vector<double> comptes;
	for (auto &p : conteneur_) {
		comptes.push_back(p.second);
	};
	return comptes;
}

void GestionnaireUtilisateurs::mettreAjourComptes(Utilisateur * payePar, double montant)
{
	double montantReparti = montant / getNombreElements();
	for (auto &p : conteneur_) {
		p.second -= montantReparti;
	}
	conteneur_[payePar]+=montant;

}

pair<Utilisateur*, double>& GestionnaireUtilisateurs::getmax() const
{
	pair<Utilisateur*, double>* retVal=new pair<Utilisateur*, double>(*max_element(conteneur_.begin(), conteneur_.end(), [](const pair<Utilisateur*, double> &p1, const pair<Utilisateur*, double> &p2) {return p1.second < p2.second; }));
	return *retVal;
}

pair<Utilisateur*, double>& GestionnaireUtilisateurs::getmin() const
{
	pair<Utilisateur*, double>* retVal = new pair<Utilisateur*, double>(*min_element(conteneur_.begin(), conteneur_.end(), [](const pair<Utilisateur*, double> &p1, const pair<Utilisateur*, double> &p2) {return p1.second < p2.second; }));
	return *retVal;

}

Utilisateur * GestionnaireUtilisateurs::getUtilisateurSuivant(Utilisateur * utilisateur, double montant) const
{

	auto f = bind([](pair<Utilisateur*, double> p, Utilisateur* u) {return p.first == u; }, std::placeholders::_1, utilisateur);
	auto it = find_if(conteneur_.begin(), conteneur_.end(), f);
	it++;
	return it->first;

}

vector<pair<Utilisateur*, double>> GestionnaireUtilisateurs::getUtilisateursEntre(double bornesInf, double bornesSup) const
{

	 vector<pair<Utilisateur*, double>> retVal;
	
	 copy_if(conteneur_.begin(), conteneur_.end(), back_inserter(retVal), FonteurIntervalle(bornesInf, bornesSup));
	 return retVal;
}

GestionnaireUtilisateurs & GestionnaireUtilisateurs::setCompte(pair<Utilisateur*, double> p)
{
	conteneur_[p.first] = p.second;
	return *this;
}

bool GestionnaireUtilisateurs::estExistant(Utilisateur * utilisateur) const
{
	return conteneur_.count(utilisateur) == 1;
}
