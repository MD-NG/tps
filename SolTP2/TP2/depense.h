/********************************************
* Titre: Travail pratique #2 - depense.h
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#ifndef DEPENSE_H
#define DEPENSE_H

#include <string>
#include <iostream>

using namespace std;

class Depense {
public:
	// Constructeurs
	// TODO: Ajouter le attribut objet dans les constructeurs
	Depense();
	Depense(const string& nom, double montant, const string& lieu);
	Depense(const Depense& dep);
	~Depense();
	// TODO: Ajouter un constructeur par copie

	// Methodes d'acces
	string getNom() const;
	double getMontant() const;
	string getLieu() const;
	// Methodes de modifications
	void setNom(const string& nom);
	void setMontant(double montant);
	void setLieu(const string& lieu);

	// TODO: Ajouter une surcharge de l'operateur =
	// TODO: Remplacer par une surcharge de l'operateur <<
	void afficherDepense() const;
	Depense operator= (const Depense& dep);
	friend ostream& operator<< (ostream& os, const Depense& dep);


private:
	string nom_;
	double montant_;
	string* lieu_;
	// TODO: Ajouter l'attribut lieu
};
#endif