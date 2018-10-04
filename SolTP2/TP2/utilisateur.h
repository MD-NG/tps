/********************************************
* Titre: Travail pratique #2 - utilisateur.h
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <string>
#include <iostream>
#include <vector>

#include "depense.h"

using namespace std;

class Utilisateur {
public:
	// Constructeurs
	Utilisateur();
	Utilisateur(const string& nom);
	// TODO: Ajouter un constructeur par copie
	Utilisateur(const Utilisateur& u);

	// Destructeur
	~Utilisateur();

	// Methodes d'accès
	string getNom() const;
	unsigned int getNombreDepense() const;
	double getTotalDepenses() const;
	vector <Depense*> getDepenses() const;

	// Methodes de modification
	void setNom(const string& nom);

	Utilisateur operator+= (Depense* dep);
	
	// TODO: Remplacer par une surcharge de l'operateur <<
	friend ostream& operator<< (ostream& os, const Utilisateur& u);

	Utilisateur operator= (const Utilisateur& u);

private:
	string nom_;
	// TODO: Remplacer depenses_ par un vecteur
	
	vector<Depense*> depenses_;

};
#endif