/********************************************
* Titre: Travail pratique #4 - utilisateurPremium.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#include "utilisateurPremium.h"


UtilisateurPremium::UtilisateurPremium(const string& nom, MethodePaiement methodePaiement,
	unsigned int joursRestants, const string& courriel, const string& idPaypal)
	: Utilisateur(nom, methodePaiement, courriel, idPaypal), joursRestants_(joursRestants)
{}

unsigned int UtilisateurPremium::getJoursRestants() const {
	return joursRestants_;
}

void UtilisateurPremium::setJoursRestants(unsigned int joursRestants) {
	joursRestants_ = joursRestants;
}

void UtilisateurPremium::print(ostream & os) const
{
	os << "\tUtilisateur (Premium) " << getNom()<<":\n";
	Utilisateur::print(os);
	os << "Jours restants: " << joursRestants_;
	os << "\nDepenses:\n":
	for  (auto &d: getDepenses())
	{
		os << d;
	}
	os << endl;
	
}
