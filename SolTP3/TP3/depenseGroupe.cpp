#include "depenseGroupe.h"


DepenseGroupe::DepenseGroupe(const string & nom, double montant, const string & lieu): Depense(nom, montant, lieu), nombreParticipants_(0) 
{
	setType(groupe);
}

DepenseGroupe::DepenseGroupe(const DepenseGroupe & depense):Depense(depense), nombreParticipants_(0)
{
	setType(groupe);
}

unsigned int DepenseGroupe::getNombreParticipants() const
{
	return nombreParticipants_;
}

double DepenseGroupe::getMontantPersonnel() const
{
	if (nombreParticipants_ == 0) {
		return 0;
	}
	else {
		return getMontant() / nombreParticipants_;
	}	
}

void DepenseGroupe::setNombreParticipants(unsigned int nombre)
{
	nombreParticipants_ = nombre;
}
