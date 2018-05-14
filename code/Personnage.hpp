/// ROB4-POO Projet Don't Starve
/// Fichier : Personnage.hpp
///	Autheurs : Benjamin Delbos et Tiphaine Diot
/// Classe Personnage

#ifndef PERS_HPP
#define PERS_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
//#include "Ressource.hpp"

<<<<<<< HEAD
class Personnage : public Drawable{
=======
class Personnage //: //public SurCarte{
{
public:
	sf::Texture texture;
	sf::Sprite sprite;
>>>>>>> 54602e8153ae5df17def151c398820c2ed83f0cb

<<<<<<< HEAD
	Personnage();

<<<<<<< HEAD
=======
protected:
	//Ressource[] _ressources;
=======
	Personnage(){

	}

	
>>>>>>> 54602e8153ae5df17def151c398820c2ed83f0cb

	bool creerHache();
	bool allumerFeu();
	bool creerPioche();
	int manger();
	int dormir();
	int reveil();
	bool interagir();

protected:
	Ressource[] _ressources;
	char _sens;
	Outil[] _outils;
	int _faim;
	int _fatigue;
	int _vie;

>>>>>>> f2908df1d2e5153607c06e6479b75785a245eb6c
};

#endif
