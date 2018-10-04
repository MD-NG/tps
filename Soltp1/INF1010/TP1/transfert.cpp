#include "transfert.h"

// Constructeurs
Transfert::Transfert() {
	montant_ = 0;
	donneur_ = nullptr;
	receveur_ = nullptr;
};
Transfert::Transfert(double montant, Utilisateur* de, Utilisateur* pour) {
	montant_ = montant;
	donneur_ = de;
	receveur_ = pour;
};

// Methodes d'accès

Utilisateur* Transfert::getDonneur() {
	return donneur_;
};
Utilisateur* Transfert::getReceveur() {
	return receveur_;

};
double Transfert::getMontant() {
	return montant_;
};


//Methode d'affichage
void Transfert::setDonneur(Utilisateur* donneur) {
	donneur_ = donneur;
};
void Transfert::setMontant(double montant) {
	montant_ = montant;
};
void Transfert::setReceveur(Utilisateur* receveur) {
	receveur_ = receveur;
};

void Transfert::afficherTransfert()
{
	cout << "\n pour equilibrer : " << endl;
	cout << "\n Transfert fait part : " << donneur_->getNom() << " pour : " << receveur_->getNom()
		<< " d'un montant de : " << montant_ << endl;
}
