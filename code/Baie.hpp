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
	std::string getType(){
		return "Baie";
	}

	std::string getRessourceName()
	{
		return "Baie";
	}

  bool interagir(std::string s){
		if(this->_vie !=0)
		{
			return true;
		}
		return false;
	}

};

#endif
