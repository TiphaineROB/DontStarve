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

	virtual std::string getType(){
		return "Element indéfini";
	}
	virtual bool utiliser(){}
	int getVie(){return _vie;}
	void setVie(int v){_vie = v;}
	virtual ~Outil(){ std::cout << "Destructeur outil" << std::endl;}
protected:
	double _vie;
	//sf::Texture _img;
};

#endif
