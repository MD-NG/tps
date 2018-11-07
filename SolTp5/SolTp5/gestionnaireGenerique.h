/********************************************
* Titre: Travail pratique #5 - gestionnaireGenerique.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

/*
	class GestionnaireGenerique
	
	Méthodes :
	C getConteneur() const;
	void ajouter(T t);
	int getNombreElements() const;
	D getElementParIndex(int i) const;

	Attributs :
	C conteneur_;
*/
#ifndef GESTIONNAIRE_GENERIQUE_H
#define GESTIONNAIRE_GENERIQUE_H

template<typename C, typename T, typename FoncteurAjouter, typename D>
class GestionnaireGenerique {
public:
	C getConteneur() { return conteneur_; }const;
	void ajouter(T t) {	conteneur_=FoncteurAjouter(conteneur_)(T);}
	int getNombreElements() const;
	D getElementParIndex(int i) const;

protected:
	C conteneur_;
		
};
#endif

template<typename C, typename T, typename FoncteurAjouter, typename D>
inline int GestionnaireGenerique<C, T, FoncteurAjouter, D>::getNombreElements() const
{
	return conteneur_.size(); ;
}

template<typename C, typename T, typename FoncteurAjouter, typename D>
inline D GestionnaireGenerique<C, T, FoncteurAjouter, D>::getElementParIndex(int i) const
{
	return { return conteneur_[i] };
}
