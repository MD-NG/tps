#include "utilisateurPremium.h"

UtilisateurPremium::UtilisateurPremium(const string & nom):Utilisateur(nom, Premium), joursRestants_(30), taux_(0.05)
{
}

UtilisateurPremium::UtilisateurPremium(const Utilisateur & utilisateur):Utilisateur(utilisateur), joursRestants_(30), taux_(0.05)
{
	
}

unsigned int UtilisateurPremium::getJoursRestants() const
{
	return joursRestants_;
}

double UtilisateurPremium::getTaux() const
{
	return taux_;
}

void UtilisateurPremium::setJoursRestants(unsigned int joursRestants)
{
	joursRestants_ = joursRestants;
}

void UtilisateurPremium::calculerTaux()
{
	taux_ = 0.05 - 0.01 * floor(this->getDepenses().size() / 2);
}

UtilisateurPremium & UtilisateurPremium::operator=(Utilisateur * utilisateur)
{
	Utilisateur::operator=(utilisateur);
	taux_ = 0.05;
	joursRestants_ = 30;
	return *this;
}

ostream & operator<<(ostream & os, const UtilisateurPremium & utilisateur)
{
	// TODO: insert return statement here
	return os;
}
