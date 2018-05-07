/// ROB4-POO Projet Don't Starve
/// Fichier : SurCarte.hpp
///	Autheurs : Benjamin Delbos et Tiphaine Diot
/// Classe SurCarte

#ifndef OBJ_HPP
#define OBJ_HPP

#include <iostream>
#include <string>

class SurCarte{

public: 
	string getType(){
		return "Ceci est un objet";
	}

protected:

	double _vie;
	int[2] _pos;

};

#endif