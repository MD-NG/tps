#include "utilisateurRegulier.h"

UtilisateurRegulier::UtilisateurRegulier(const string & nom):Utilisateur(nom), estGroupe_(false)
{
	
}

UtilisateurRegulier::UtilisateurRegulier(const Utilisateur & utilisateur) : Utilisateur(utilisateur), estGroupe_(false)
{
}

bool UtilisateurRegulier::estGroupe() const
{
	return estGroupe_;
}

void UtilisateurRegulier::setEtatGroupe(bool etat)
{
	estGroupe_ = etat;
}

UtilisateurRegulier & UtilisateurRegulier::operator=(Utilisateur * utilisateur)
{
	Utilisateur::operator=(utilisateur);
	estGroupe_ = false;
	return *this;

}

ostream & operator<<(ostream & os, const UtilisateurRegulier & utilisateur)
{
	// TODO: insert return statement here
	return os;
}
