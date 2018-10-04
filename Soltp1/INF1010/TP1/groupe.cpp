#include "groupe.h"
#include <algorithm>

//Constructeurs
Groupe::Groupe() {
	nom_ = "";
	totalDepenses_ = 0;
	nombreDepenses_ = 0;
	nombreUtilisateurs_ = 0;
	tailleTabDepenses_ = TAILLE_DEPENSES;
	tailleTabUtilisateurs_ = TAILLE_UTILISATEURS;
	listeUtilisateurs_ = new Utilisateur*[TAILLE_UTILISATEURS];
	for(int i=0; i<TAILLE_UTILISATEURS; i++){
		listeUtilisateurs_[i] = nullptr;
	}
	listeDepenses_ = new Depense*[TAILLE_DEPENSES];
	for (int i = 0; i < TAILLE_DEPENSES; i++) {
		listeDepenses_[i] = nullptr;
	}
	comptes_ = new double[TAILLE_UTILISATEURS];
}
Groupe::Groupe(string& nom, unsigned int tailleTabDepenses, unsigned int tailleTabUtilisateurs) {
	nom_ = nom;
	totalDepenses_ = 0;
	nombreDepenses_ = 0;
	nombreUtilisateurs_ = 0;
	tailleTabDepenses_ = tailleTabDepenses;
	tailleTabUtilisateurs_ = tailleTabUtilisateurs;
	listeUtilisateurs_ = new Utilisateur*[tailleTabUtilisateurs];
	for (unsigned int i = 0; i < tailleTabUtilisateurs; i++) {
		listeUtilisateurs_[i] = nullptr;
	}
	listeDepenses_ = new Depense*[tailleTabDepenses];
	for (unsigned int i = 0; i < tailleTabDepenses; i++) {
		listeDepenses_[i] = nullptr;
	}
	comptes_ = new double[tailleTabUtilisateurs];
}

//Destructeur
Groupe::~Groupe() {
	if (listeUtilisateurs_ != nullptr) {
		delete[] listeUtilisateurs_;
	}
	if (listeDepenses_ != nullptr) {

		delete[] listeDepenses_;
	}
	if (comptes_ != nullptr) {
		delete[] comptes_;
	}
	if (listeTransferts_ != nullptr) {
		delete[] listeTransferts_;
	}
	comptes_ = nullptr;
	listeDepenses_ = nullptr;
	listeUtilisateurs_ = nullptr;
}

//methode d'acces
string Groupe::getNom() {
	return nom_;
}
unsigned int Groupe::getNombreDepenses() {
	return nombreDepenses_;
}
double Groupe::getTotal() {
	return totalDepenses_;
}

//Methodes de modification
void Groupe::setNom(string& nom) {
	nom_ = nom;
}

//Methodes d'ajout
void Groupe::ajouterDepense(Depense* uneDepense, Utilisateur* payePar) {
	if (nombreDepenses_ < tailleTabDepenses_) {
		listeDepenses_[nombreDepenses_] = uneDepense;
	}
	else {
		tailleTabDepenses_ *= 2;
		Depense** listeDepensesTemp = new Depense*[tailleTabDepenses_];
		for (unsigned int i=0; i < nombreDepenses_; i++) {
			listeDepensesTemp[i] = listeDepenses_[i];
		}
		listeDepensesTemp[nombreDepenses_] = uneDepense;
		delete[] listeDepenses_;
		listeDepenses_ = listeDepensesTemp;

		
	}
	nombreDepenses_++;
	
	payePar->ajouterDepense(uneDepense);
	calculerTotalDepenses();
	
}
void Groupe::ajouterUtilisateur(Utilisateur* unUtilisateur) {
	if (nombreUtilisateurs_ < tailleTabUtilisateurs_) {
		listeUtilisateurs_[nombreUtilisateurs_] = unUtilisateur;
	}
	else {
		tailleTabUtilisateurs_ *= 2;
		Utilisateur** listeUtilisateursTemp = new Utilisateur*[tailleTabUtilisateurs_];
		for (unsigned int i=0;i < nombreUtilisateurs_; i++) {
			listeUtilisateursTemp[i] = listeUtilisateurs_[i];
		}
		listeUtilisateursTemp[nombreUtilisateurs_] = unUtilisateur;
		delete[] listeUtilisateurs_;
		listeUtilisateurs_ = listeUtilisateursTemp;
				
	}
	nombreUtilisateurs_++;

}

//Methode de calcul
void Groupe::calculerTotalDepenses() {
	double total = 0;
	delete[] comptes_;
	for (unsigned int i = 0; i < nombreDepenses_; i++) {
		total=total+listeDepenses_[i]->getMontant();
	}
	totalDepenses_ = total;
	double debitInd = totalDepenses_ / nombreUtilisateurs_;
	comptes_ = new double[nombreUtilisateurs_];
	for (unsigned int i = 0; i < nombreUtilisateurs_; i++) {
		comptes_[i] =  listeUtilisateurs_[i]->getTotal()-debitInd;
	}
	

}

unsigned int minArray(const double* arr, unsigned n) {
	unsigned int minIndex = 0;
	for (unsigned int i = 1; i < n; i++) {
		if (arr[minIndex] > arr[i]) {
			minIndex = i;
		}
	}
	return minIndex;
}

unsigned int maxArray(const double* arr, unsigned n) {
	unsigned int maxIndex = 0;
	for (unsigned int i = 1; i < n; i++) {
		//double temp2 = arr[i];
		if (arr[maxIndex] < arr[i]) {
		//	double temp = arr[i];
			maxIndex = i;
		}
	}
	return maxIndex;
}

void Groupe::equilibrerComptes() {
	nombreTrensferts_ = 0;
	delete[] listeTransferts_;
	unsigned int minIndex;
	unsigned int maxIndex;
	double solde;
	listeTransferts_ = new Transfert*[nombreUtilisateurs_];

	while (comptes_[minArray(comptes_, nombreUtilisateurs_)] != 0) {
		minIndex = minArray(comptes_, nombreUtilisateurs_);
		maxIndex = maxArray(comptes_, nombreUtilisateurs_);
		listeTransferts_[nombreTrensferts_] = new Transfert(min(comptes_[maxIndex], abs(comptes_[minIndex])),listeUtilisateurs_[maxIndex],listeUtilisateurs_[minIndex]);
		double temp= min(comptes_[maxIndex], abs(comptes_[minIndex]));
		solde = comptes_[minIndex] + comptes_[maxIndex];
		comptes_[minIndex] = min(0.0, solde);
		comptes_[maxIndex] = max(0.0, solde);
		nombreTrensferts_++;
	}

 }



//methode d'affichage
void Groupe::afficherGroupe()
{
	cout << "\nL'evenement : " << nom_ << " a coute pour le groupe de : " << totalDepenses_ << " voici les depences : " << endl;
	for (unsigned int i = 0; i < nombreUtilisateurs_; i++)
	{
		listeUtilisateurs_[i]->afficherUtilisateur();
	}
	
	if (nombreTrensferts_ == 0)
	{	cout << "\nsoit les comptes suivants : " << endl;
		for (unsigned int i = 0; i < nombreUtilisateurs_; i++)
		{
			cout << listeUtilisateurs_[i]->getNom() << " : " << comptes_[i] << "\n";
		}
	}
	else
	{
		cout << "\npour equilibrer : " << endl;
		for (unsigned int i = 0; i < nombreTrensferts_; i++)
		{
			cout << "\tTranfert fait part : " << listeTransferts_[i]->getDonneur()->getNom() << " pour : " << listeTransferts_[i]->getReceveur()->getNom()
				<< " d'un montant de : " << listeTransferts_[i]->getMontant() << endl;
		}
	}
	cout << "-----------------------------------------------------------------------------\n";
	cout << "-----------------------------------------------------------------------------";
}



//cout << "\nsoit les comptes suivantes : " << endl;
//for (unsigned int i = 0; i < nombreDepenses_; i++)
//	cout << "\nAchat : " << listeDepenses_[i]->getTitre() << endl;