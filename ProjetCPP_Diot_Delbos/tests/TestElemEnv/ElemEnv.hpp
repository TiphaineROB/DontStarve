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

	~ElemEnv(){
		std::cout << "Destructeur ElemEnv" << std::endl;
	}

	virtual std::string getType(){
		return "Element indéfini";
	}

	virtual std::string getRessourceName(){
		return "indefini";
	}

	virtual int getRessource(){ return 0;}

	virtual bool interagir(std::string s){ return false;}
	int getVie(){
		return this->_vie;
	}

	void setVie(int v){this->_vie = v;}
	//Fonction qui dit si le coup que l'élement a reçu est destructif
	virtual bool coupDestructif(){
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
