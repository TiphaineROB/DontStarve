/// ROB4-POO Projet Don't Starve
/// Fichier : Personnage.hpp
///	Autheurs : Benjamin Delbos et Tiphaine Diot
/// Classe Personnage

#ifndef PERS_HPP
#define PERS_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
//#include "Ressource.hpp"

class Personnage //: //public SurCarte{
{
public:
	sf::Texture texture;
	sf::Sprite sprite;

	Personnage();

protected:
	//Ressource[] _ressources;
};

#endif
