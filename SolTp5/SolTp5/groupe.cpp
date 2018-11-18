/********************************************
* Titre: Travail pratique #5 - groupe.cpp
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

#include "groupe.h"

// Constructeurs
Groupe::Groupe() {
	nom_ = "";
	gestionnaireDepenses_ = new GestionnaireDepenses();
	gestionnaireUtilisateurs_ = new GestionnaireUtilisateurs();
}

Groupe::Groupe(const string& nom) : nom_(nom) {
	gestionnaireDepenses_ = new GestionnaireDepenses();
	gestionnaireUtilisateurs_ = new GestionnaireUtilisateurs();
}

Groupe::~Groupe() {
	vector<Depense*> depenses = gestionnaireDepenses_->getConteneur();
	for (int i = 0; i < depenses.size(); i++) {
		delete depenses[i];
	}
	for (int i = 0; i < transferts_.size(); i++) {
		delete transferts_[i];
	}

	delete gestionnaireDepenses_;
	delete gestionnaireUtilisateurs_;
}

// Methodes d'acces
string Groupe::getNom() const {
	return nom_;
}

// TODO : À modifier :
vector<Depense*> Groupe::getDepenses() const
{
	return gestionnaireDepenses_->getConteneur();
}

map<Utilisateur*, double> Groupe::getUtilisateurs() const
{
	return gestionnaireUtilisateurs_->getConteneur();
}

// TODO : À modifier :


vector<Transfert*> Groupe::getTransferts() const
{
	return transferts_;
}

// TODO : À modifier :
vector<double> Groupe::getComptes() const {
	return gestionnaireUtilisateurs_->getComptes();
}

double Groupe::getTotalDepenses() const {
	return gestionnaireDepenses_->getTotalDepenses();
}

GestionnaireUtilisateurs * Groupe::getGestionnaireUtilisateurs()
{
	return gestionnaireUtilisateurs_;
}

GestionnaireDepenses * Groupe::getGestionnaireDepenses()
{
	return gestionnaireDepenses_;
}

// Methodes de modifications
void Groupe::setNom(const string& nom) {
	nom_ = nom;
}

// Methodes d'ajout
// TODO : À modifier :
Groupe& Groupe::ajouterDepense(double montant, Utilisateur* payePar, const string& nom, const string& lieu)
{

	if (!gestionnaireUtilisateurs_->estExistant(payePar)) {
		return *this;
	}

	Depense* depense = new Depense(nom, montant, lieu);

	// Modifié :
	gestionnaireDepenses_->ajouter(depense);

	*payePar += depense;

	// Mise a jour des comptes
	gestionnaireUtilisateurs_->mettreAjourComptes(payePar, montant);

	return *this;
}

Groupe& Groupe::operator+=(Utilisateur* utilisateur)
{

	// Ajouté :
	UtilisateurRegulier* utilisateurRegulier = dynamic_cast<UtilisateurRegulier*>(utilisateur);
	UtilisateurPremium* utilisateurPremium = dynamic_cast<UtilisateurPremium*>(utilisateur);

	if (utilisateurRegulier != nullptr) {
		if (!utilisateurRegulier->getPossedeGroupe()) {
			utilisateurRegulier->setPossedeGroupe(true);
		}
		else {
			cout << "Erreur : L'utilisateur " << utilisateur->getNom() << " n'est pas un utilisateur premium et est deja dans un groupe." << endl;
			return *this;
		}
	}
	else {
		if (utilisateurPremium != nullptr && utilisateurPremium->getJoursRestants() <= 0) {
			cout << "Erreur : L'utilisateur " << utilisateur->getNom() << " doit renouveler son abonnement premium" << endl;
			return *this;
		}
	}

	gestionnaireUtilisateurs_->ajouter(utilisateur);
	return *this;
}

// TODO : À modifier :
void Groupe::equilibrerComptes() {

	bool calcul = true;
	int count = 0;
	pair<Utilisateur*, double> maxU;
	pair<Utilisateur*, double> minU;

	while (calcul) {

		// On cherche le compte le plus eleve et le moins eleve

		maxU = gestionnaireUtilisateurs_->getmax();
		minU = gestionnaireUtilisateurs_->getmin();



		// On cherche lequel des deux a la dette la plus grande
		if (-minU.second <= maxU.second && minU.second != 0 && maxU.second != 0) {
			if (minU.first->getMethodePaiement() == Interac) {
				TransfertInterac* transfert = new TransfertInterac(-minU.second, minU.first, maxU.first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			else {
				TransfertPaypal* transfert = new TransfertPaypal(-minU.second, minU.first, maxU.first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			maxU.second += minU.second;
			minU.second = 0;
			gestionnaireUtilisateurs_->setCompte(maxU);
			gestionnaireUtilisateurs_->setCompte(minU);
			//gestionnaireUtilisateurs_->getmax().second += minU.second;
			//gestionnaireUtilisateurs_->getmin().second = 0;
		}
		else if (-minU.second > maxU.second  && -minU.second != 0 && maxU.second != 0) {
			if (minU.first->getMethodePaiement() == Interac) {
				TransfertInterac* transfert = new TransfertInterac(maxU.second, minU.first, maxU.first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			else {
				TransfertPaypal* transfert = new TransfertPaypal(maxU.second, minU.first, maxU.first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			minU.second += maxU.second;
			maxU.second = 0;			
			gestionnaireUtilisateurs_->setCompte(maxU);
			gestionnaireUtilisateurs_->setCompte(minU);
			//gestionnaireUtilisateurs_->getmax().second = 0;
			//gestionnaireUtilisateurs_->getmin().second += maxU.second;
		}

		// On incremente le nombre de comptes mis a 0
		count++;
		if (-minU.second == maxU.second) {
			count++;
		}
		if (count >= gestionnaireUtilisateurs_->getNombreElements() - 1) {
			calcul = false;
		}
	}

}

// Methode d'affichage
// TODO : À modifier :
ostream & operator<<(ostream& os, const Groupe& groupe)
{
	os << "\nGroupe " << groupe.nom_ << ".\nCout total: " << groupe.getTotalDepenses() << "$ \nUtilisateurs:    \n\n";
	for (int i = 0; i < groupe.gestionnaireUtilisateurs_->getNombreElements(); i++) {
		os << "\t- " << *groupe.gestionnaireUtilisateurs_->getElementParIndex(i).first;
	}
	os << endl;

	if (groupe.transferts_.size() != 0) {
		os << "Transferts :" << endl;
		for (int i = 0; i < groupe.transferts_.size(); i++)
			os << "\t" << *(groupe.transferts_[i]);
	}
	else {
		os << "Les comptes ne sont pas equilibres" << endl << endl;
		for (int i = 0; i < groupe.gestionnaireUtilisateurs_->getNombreElements(); i++) {
			os << groupe.gestionnaireUtilisateurs_->getElementParIndex(i).first->getNom() << " : " << groupe.gestionnaireUtilisateurs_->getElementParIndex(i).second << endl;
		}
	}

	os << endl;
	return os;
}
