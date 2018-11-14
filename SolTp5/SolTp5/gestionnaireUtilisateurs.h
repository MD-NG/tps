/********************************************
* Titre: Travail pratique #5 - gestionnaireUtilisateurs.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once

#include "utilisateur.h"
#include "foncteur.h"
#include <map>
#include <vector>
#include "gestionnaireGenerique.h"
#include <algorithm>
#include <functional>

class GestionnaireUtilisateurs :public GestionnaireGenerique <map<Utilisateur*, double>, Utilisateur*, AjouterUtlisateur,pair<Utilisateur*, double>> {
public:
	vector<double> getComptes() const;
	void mettreAjourComptes(Utilisateur* payePar, double montant);
	pair<Utilisateur*, double>& getmax() const;
	pair<Utilisateur*, double>& getmin() const;
	Utilisateur* getUtilisateurSuivant(Utilisateur* utilisateur, double montant) const;
	vector<pair<Utilisateur*, double>> getUtilisateursEntre(double bornesInf, double bornesSup) const;
	GestionnaireUtilisateurs& setCompte(pair<Utilisateur*, double> p);

private:

};