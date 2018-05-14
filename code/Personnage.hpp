/// ROB4-POO Projet Don't Starve
/// Fichier : Personnage.hpp
///	Autheurs : Benjamin Delbos et Tiphaine Diot
/// Classe Personnage

#ifndef PERS_HPP
#define PERS_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Outil.hpp"
#include "Ressource.hpp"
#include "ToDraw.hpp"
#include "Hache.hpp"
#include "Pioche.hpp"
#include "ElemEnv.hpp"
//#include "Ressource.hpp"

class Personnage : public ToDraw
{
public:
	sf::Texture texture;
	sf::Sprite sprite;

	Personnage();

protected:
	//Ressource[] _ressources;


	int comptBois(){
		int nbBois = 0;
		for(std::vector<Ressource>::iterator r = _ressources.begin(); r != _ressources.end(); ++r)
		{
			if(*r.getType() == "Bois")
				nbBois ++; 
		}
		return nbBois; 
	}

	int comptPierre(){
		int nbPierre = 0;
		for(std::vector<Ressource>::iterator r = _ressources.begin(); r != _ressources.end(); ++r)
		{
			if(*r.getType() == "Pierre")
				nbPierre++;
		}
		return nbPierre;
	}



	bool creerHache();
	bool allumerFeu();
	bool creerPioche();
	int manger();
	int dormir();
	int reveil();
	bool interagir(ElemEnv env);
	Outil changerOut(int i);

protected:
	std::vector<Ressource> _ressources;
	std::vector<Outil> _outils;
	char _sens;
	int _faim;
	int _fatigue;
	int _vie;
};

#endif
