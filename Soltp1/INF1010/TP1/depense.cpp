#include "depense.h"

Depense::Depense() {
	titre_ = "";
	montant_ = 0;
};
Depense::Depense(string& titre, double montant) {
	titre_ = titre;
	montant_ = montant;
}

// methodes d'accès
string Depense::getTitre() {
	return titre_;
};
double Depense::getMontant() {
	return montant_;
};

//methodes de modifications
void Depense::setTitre(string& titre) {
	titre_ = titre;
};
void Depense::setMontant(double montant) {
	montant_ = montant;
};

//methode d'affichage
void Depense::afficherDepense()
{
	cout << "\t\tAchat : " << titre_ << " prix : " << montant_ << "\n";
}

