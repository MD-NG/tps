#include "utilisateurRegulier.h"

UtilisateurRegulier::UtilisateurRegulier(const string & nom):utilisateur(nom), estGroupe_(false)
{
	
}

UtilisateurRegulier::UtilisateurRegulier(const Utilisateur & utilisateur) : utilisateur(utilisateur), estGroupe_(false)
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

}
