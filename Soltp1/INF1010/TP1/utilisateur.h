
#ifndef UTILISATEUR_H
#define UTILISATEUR_H
const int TAILLE_DEPENSES = 10;

#include <string>
#include <iostream>

#include "depense.h"

using namespace std;

class Utilisateur {
    public :
    // constructeurs
	Utilisateur();
    Utilisateur( string& nom);
    
    //Destructeur
    ~Utilisateur(); 
    
    //Methodes d'accès
    string getNom() ;
    unsigned int getNombreDepense() ;
    double getTotal() ;
  
    //Methode de modification
    void setNom(string& nom);
    
    // Methode ajout de depense
    void ajouterDepense(Depense* uneDepense);
    
    //Methode de calcul total
    void calculerTotal();
    
    //Mathode d'affichage
    void afficherUtilisateur() ;
    
    private :
        string nom_;
        unsigned int tailleTabDepense_;
        unsigned int nombreDepenses_;
        double totalDepense_;
        Depense ** listeDepenses_;
    
    
};
#endif /* utilisateur_hpp */
