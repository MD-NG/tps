#include <iostream>
#include "groupe.h"


using namespace std; 


int main(int argc, const char * argv[]) {
    cout << "\t \tBienvenue sur PolyCount " << endl << " *****************************************" << endl;
	using namespace std;
	// Creer un  groupe pour  6 depenses et 4 utilisateurs.
	string nom = "Groupe1";
	unsigned int nbUtilisateurs=4;
	unsigned int nbDepenses=6;
	Groupe* grp=new Groupe(nom,nbDepenses,nbUtilisateurs);
    
    // Creer 5 utlisateurs.
	string nom0="Jean";
	string nom1="Pierre";
	string nom2="Paul";
	string nom3="Henry";
	string nom4="Julien";
	
	Utilisateur u0(nom0);
	Utilisateur u1(nom1);
	Utilisateur u2(nom2);
	Utilisateur u3(nom3);
	Utilisateur u4(nom4);
	   	     
    //Creer 7 depenses.
	string titre0 = "d0";
	string titre1 = "d1";
	string titre2 = "d2";
	string titre3 = "d3";
	string titre4 = "d4";
	string titre5 = "d5";
	string titre6 = "d6";
	Depense d0(titre0, 10);
	Depense d1(titre1, 20);
	Depense d2(titre2, 30);
	Depense d3(titre3, 40);
	Depense d4(titre4, 50);
	Depense d5(titre5, 60);
	Depense d6(titre6, 70);

    
    //ajouter les utilisateurs au groupe
	grp->ajouterUtilisateur(&u0);
	grp->ajouterUtilisateur(&u1);
	grp->ajouterUtilisateur(&u2);
	grp->ajouterUtilisateur(&u3);
	grp->ajouterUtilisateur(&u4);


    //ajouter les depenses au groupe
	grp->ajouterDepense(&d0, &u0);
	grp->ajouterDepense(&d1, &u1);
	grp->ajouterDepense(&d2, &u2);
	grp->ajouterDepense(&d3, &u3);
	grp->ajouterDepense(&d4, &u4);
	grp->ajouterDepense(&d5, &u0);
	grp->ajouterDepense(&d6, &u1);
    
    //calculer le total du grouoe et de chaque utilisateur
	grp->calculerTotalDepenses();

    //Afficher  le groupe
	grp->afficherGroupe();
    
    //Equilibrer les comptes
	grp->equilibrerComptes();

    //Afficher le groupe
	grp->afficherGroupe();
   
    //terminer le programme correctement
	delete grp;

}
