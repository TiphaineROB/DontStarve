/// ROB4-POO Projet Don't Starve
/// Fichier : Baie.hpp
///	Autheurs : Benjamin Delbos et Tiphaine Diot
/// Classe Baie

#ifndef BAIE_HPP
#define BAIE_HPP

#include <iostream>
#include "ElemEnv.hpp"

class Baie : public ElemEnv{

	public:

	Baie(){
		this->_vie = 3;
		//On lui attribue son sprite aussi
	}

	Baie(int x, int y){
		this->_vie = 3;
		this->texture.loadFromFile("../images/baies.png");
		this->sprite.setTexture(this->texture);
		this->sprite.setTextureRect(sf::IntRect(0,0,512/4,512/4));
		this->sprite.setScale(sf::Vector2f(0.5,0.5));
		this->sprite.setPosition(sf::Vector2f(x, y));
		this->_position[0]=x;
		this->_position[1]=y;
	}

	std::string getType(){
		return "Baie";
	}

	std::string getRessourceName()
	{
		return "Baie";
	}

	int getRessource(){return 1;}

  bool interagir(std::string s){
		if(this->_vie !=0)
		{
			return true;
		}
		return false;
	}

	bool coupDestructif(){
		this->_vie--;
		if(this->_vie <= 0) //S'il n'y a plus de baies sur l'arbre à baie
			return false;
		else
			return true;
	}

};

#endif
