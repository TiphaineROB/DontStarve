/// ROB4-POO Projet Don't Starve
/// Fichier : ElemEnv.hpp
///	Autheurs : Benjamin Delbos et Tiphaine Diot
/// Classe ElemEnv


#ifndef ELEM_HPP
#define ELEM_HPP

#include <iostream>
#include <string>
#include "ToDraw.hpp"

class ElemEnv : public ToDraw
{

public: 

	ElemEnv()
	{
		_vie = 3;
	}
	
	virtual std::string getType(){
		return "Element indéfini";
	}

	int getVie(){
		return this->_vie;
	}

	//Fonction qui dit si le coup que l'élement a reçu est destructif
	bool coupDestructif(){
		_vie--;
		if(_vie==0)
			return true;
		else
			return false; 
	}

protected:
	int _vie;

};

#endif
