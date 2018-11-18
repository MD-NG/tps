/********************************************
* Titre: Travail pratique #5 - foncteur.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

#include <map>
/*
	Foncteur AjouterDepense

	Méthode :
	Constructeur
	vector<Depense*>& operator()();

	Attribut :
	vector<Depense*> conteneur_;
*/

#ifndef FONCTEUR_H
#define FONCTEUR_H
class AjouterDepense{
public:
	AjouterDepense(vector<Depense*> &conteneur) :conteneur_(conteneur) {};
	vector<Depense*> operator() (Depense* depense) {
		conteneur_.push_back(depense);
		return conteneur_;
	}
private:
	vector<Depense*>&conteneur_; 
};




/*
Foncteur AjouterUtilisateur

Méthode :
Constructeur
map<Utilisateur*, double>& operator()();

Attribut :
map<Utilisateur*, double> conteneur_;
*/


class AjouterUtlisateur{
public:
	AjouterUtlisateur(map<Utilisateur*, double> &conteneur) :conteneur_(conteneur) {};
	map<Utilisateur*, double> operator() (Utilisateur* utilisateur, double montant=0) {

		conteneur_.insert(pair<Utilisateur*, double>(utilisateur,montant));
		return conteneur_;
	}
private:
	map<Utilisateur*, double> &conteneur_;
};



/*
Foncteur FoncteurIntervalle

Méthode :
Constructeur
bool operator()();

Attribut :
double borneInf_, borneSup_;
*/

class FonteurIntervalle{
public:
	FonteurIntervalle(double borneInf, double borneSup) :borneInf_(borneInf), borneSup_(borneSup) {};
	bool operator()(pair<Utilisateur*, double> p) {
		return (p.second <= borneSup_) && (p.second >= borneInf_);
	}

private:
	double borneInf_;
	double borneSup_;

};

#endif