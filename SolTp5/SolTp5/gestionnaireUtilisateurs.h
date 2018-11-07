/********************************************
* Titre: Travail pratique #5 - gestionnaireUtilisateurs.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once

#include "utilisateur.h"
#include "foncteur.h"
#include <map>
#include <vector>
#include "gestionnaireGenerique.h"


class GestionnaireUtilisateurs :GestionnaireGenerique <map<Utilisateur, double>, Utilisateur*, jouterUtilisateur,pair<Utilisateur*, double>> {
public:
	get

private:

};