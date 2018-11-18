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
	C getConteneur() const;
	void ajouter(T t);
	int getNombreElements() const;
	D getElementParIndex(int i) const;

protected:
	C conteneur_;
		
};


template<typename C, typename T, typename FoncteurAjouter, typename D>
inline C GestionnaireGenerique<C, T, FoncteurAjouter, D>::getConteneur() const
{
	return conteneur_;
}

template<typename C, typename T, typename FoncteurAjouter, typename D>
inline void GestionnaireGenerique<C, T, FoncteurAjouter, D>::ajouter(T t)
{
	conteneur_=FoncteurAjouter(conteneur_)(t);
	

}

template<typename C, typename T, typename FoncteurAjouter, typename D>
inline int GestionnaireGenerique<C, T, FoncteurAjouter, D>::getNombreElements() const
{
	return conteneur_.size();
}

template<typename C, typename T, typename FoncteurAjouter, typename D>
inline D GestionnaireGenerique<C, T, FoncteurAjouter, D>::getElementParIndex(int i) const
{
	auto it=conteneur_.begin();
	std::advance(it, i);
	return *it;
	

}
#endif