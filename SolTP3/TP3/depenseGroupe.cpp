#include "depenseGroupe.h"


DepenseGroupe::DepenseGroupe(const string & nom, double montant, const string & lieu) :nom_( nom), montant_ (montant), lieu_ (new string(lieu)), nombreParticipants_(0)
{
	type_ = groupe;
}

DepenseGroupe::DepenseGroupe(const DepenseGroupe & depense)
{
	DepenseGroupe(depense.getNom, depense.getMontant, depense.getLieu);
}

unsigned int DepenseGroupe::getNombreParticipants() const
{
	return nombreParticipants_;
}

double DepenseGroupe::getMontantPersonnel() const
{
	if (nombreParticipants_ == 0) {
		return 0
	}
	else {
		return montant_ / nombreParticipants_;
	}	
}

void DepenseGroupe::setNombreParticipants(unsigned int nombre)
{
	nombreParticipants_ = nombre;
}
