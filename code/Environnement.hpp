/// ROB4-POO Projet Don't Starve
/// Fichier : Environnement.hpp
///	Autheurs : Benjamin Delbos et Tiphaine Diot
/// Classe Environnement

#ifndef ENV_HPP
#define ENV_HPP

#include <iostream>
#include "SurCarte.hpp"
#include "Personnage.hpp"

class Environnement{

public: 

	//Constructeurs
	Environnement()
	{

	}

	//Destructeur
	~Environnement(){
		~_objs;
		~_persos;
	}

	//Accesseurs

	void addObj(SurCarte o){
		_objs.push_back(o);
	}
	void addPers(Personnage p){
		_persos.push_back(p);
	}

	SurCarte getObj(i){
		return _objs[i];
	}

	Personnage getPers(i){
		return _persos[i];
	}

protected:
	std::Vector<SurCarte> _objs;
	std::Vector<Personnage> _persos;

};

#endif