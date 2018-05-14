/// ROB4-POO Projet Don't Starve
/// Fichier : Outil.hpp
///	Autheurs : Benjamin Delbos et Tiphaine Diot
/// Classe Outil

#ifndef OUT_HPP
#define OUT_HPP

#include <iostream>

class Outil{

public: 

	Outil(){
		_vie = 4;
	}
	std::string getType(){
		return "Element indéfini";
	}

protected:
	double _vie;
	//sf::Texture _img;
};

#endif
