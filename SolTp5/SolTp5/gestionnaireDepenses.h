#pragma once

#include "depense.h"
#include "utilisateur.h"
#include "gestionnaireGenerique.h"
#include "foncteur.h"
#include <algorithm>
#include <vector>

class GestionnaireDepenses:public GestionnaireGenerique<vector<Depense*>, Depense*,AjouterDepense, Depense* >{
public:

	double getTotalDepenses() const;
	
private:
};
