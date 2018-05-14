/// ROB4-POO Projet Don't Starve
/// Fichier : Drawable.hpp
///	Autheurs : Benjamin Delbos et Tiphaine Diot
/// Classe Drawable

#ifndef DRAW_HPP
#define DRAW_HPP

#include <iostream>
#include <string>

class Drawable{

public: 
	string getType(){
		return "Ceci est un objet";
	}

protected:

	double _vie;
	int[2] _pos;

};

#endif