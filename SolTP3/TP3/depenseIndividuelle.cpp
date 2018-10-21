#include "depenseIndividuelle.h"

DepenseIndividuelle::DepenseIndividuelle(const string & nom, double montant, const string& lieu) : Depense(nom, montant, lieu)
{
	this->setType(individuelle);
}



ostream& operator<< (ostream& os, const DepenseIndividuelle& depense) {
	return os << "Achat fait (a " << *depense.getLieu() << ") : " << depense.getNom()
		<< " Prix : " << depense.getMontant();
 }