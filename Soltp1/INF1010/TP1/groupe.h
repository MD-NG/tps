
#ifndef GROUPE_H
#define GROUPE_H

const int TAILLE_UTILISATEURS = 5;

#include "transfert.h"
#include <string>
using namespace std;

class Groupe{
    public :
    //Constructeurs
		Groupe();
		Groupe(string& nom, unsigned int tailleTabDepenses, unsigned int tailleTabUtilisateurs);
    
    //Destructeur
    ~Groupe();
    
    //methode d'acces
    string getNom() ;
    unsigned int getNombreDepenses();
    double getTotal();
    
    //Methodes de modification
    void setNom(string& nom);
    
    //Methodes d'ajout
    void ajouterDepense(Depense* uneDepense, Utilisateur* payePar);
    void ajouterUtilisateur(Utilisateur* unUtilisateur);
    
    //Methode de calcul
    void calculerTotalDepenses();
    void equilibrerComptes();
    
    //methode d'affichage
    void afficherGroupe();
    
    private :
        string nom_;
        double totalDepenses_;
        Utilisateur** listeUtilisateurs_;
        unsigned int nombreDepenses_;
        unsigned int nombreUtilisateurs_;
        unsigned int tailleTabUtilisateurs_;
        unsigned int tailleTabDepenses_;
        Depense** listeDepenses_;
        double* comptes_;
        Transfert** listeTransferts_;
        unsigned int nombreTrensferts_; 
    
};

#endif 
