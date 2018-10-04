/********************************************
* Titre: Travail pratique #2 - transfert.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#include "transfert.h"

// Constructeurs
Transfert::Transfert() : montant_(0), expediteur_(nullptr), receveur_(nullptr) {
}

Transfert::Transfert(double montant, Utilisateur* expediteur, Utilisateur* receveur) : 
	montant_(montant), expediteur_(expediteur), receveur_(receveur) {
}

// Methodes d'acces
double Transfert::getMontant() const {
	return montant_;
}

Utilisateur* Transfert::getExpediteur() const {
	return expediteur_;
}

Utilisateur* Transfert::getReceveur() const {
	return receveur_;
}

// Methodes de modifications
void Transfert::setMontant(double montant) {
	montant_ = montant;
}

void Transfert::setExpediteur(Utilisateur *donneur) {
	expediteur_ = donneur;
}

void Transfert::setReceveur(Utilisateur *receveur) {
	receveur_ = receveur;
}

//Methode affichage
//void Transfert::afficherTransfert() const {
//	cout << "Transfert fait par " << expediteur_->getNom() << " vers " << receveur_->getNom() 
//		<< " d'un montant de " << montant_ << endl;
//}

ostream & operator<<(ostream& os, const Transfert& tf)
{
	return os << "Transfert fait par " << tf.getExpediteur()->getNom() << " vers " << tf.getReceveur()->getNom() 
	<< " d'un montant de " << tf.getMontant() << endl;
	// TODO: insert return statement here
	
}
