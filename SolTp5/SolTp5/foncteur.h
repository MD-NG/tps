/********************************************
* Titre: Travail pratique #5 - foncteur.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

#include <map>
/*
	Foncteur AjouterDepense

	M�thode :
	Constructeur
	vector<Depense*>& operator()();

	Attribut :
	vector<Depense*> conteneur_;
*/
class AjouterDepense
{
public:
	AjouterDepense(vector<Depense*> &conteneur) :conteneur_(conteneur) {};
	~AjouterDepense();
	vector<Depense*> operator() (Depense* depense) {
		conteneur_.push_back(depense);
		return conteneur_;
	}
private:
	vector<Depense*>&conteneur_; 
};




/*
Foncteur AjouterUtilisateur

M�thode :
Constructeur
map<Utilisateur*, double>& operator()();

Attribut :
map<Utilisateur*, double> conteneur_;
*/


class AjouterUtlisateur
{
public:
	AjouterUtlisateur(map<Utilisateur*, double> &conteneur) :conteneur_(conteneur) {};
	~AjouterUtlisateur();
	map<Utilisateur*, double> operator() (Utilisateur* utilisateur, double montant) {
		conteneur_.insert(pair<Utilisateur*, double>(utilisateur,montant));
		return conteneur_;
	}
private:
	map<Utilisateur*, double> &conteneur_;
};



/*
Foncteur FoncteurIntervalle

M�thode :
Constructeur
bool operator()();

Attribut :
double borneInf_, borneSup_;
*/

class FonteurIntervalle
{
public:
	FonteurIntervalle(double borneInf, double borneSup) :borneInt_(borneInf), borneSup_(borneSup_) {};
	~FonteurIntervalle();
	bool operator()(pair<Utilisateur*, double> p) {
		return (p.second < borneSup_) && (p.second > borneSup_);
	}

private:
	double borneInt_;
	double borneSup_;

};

