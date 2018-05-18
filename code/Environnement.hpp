/// ROB4-POO Projet Don't Starve
/// Fichier : Environnement.hpp
///	Autheurs : Benjamin Delbos et Tiphaine Diot
/// Classe Environnement

#ifndef ENV_HPP
#define ENV_HPP

#include <iostream>
#include "ToDraw.hpp"
#include "Personnage.hpp"

class Environnement : ToDraw{

public: 

	//Constructeurs
	Environnement(int nbP, std::vector<Personnage> ps, std::string s)
	{
		for(int i=0; i < nbP; i++)
			addPers(ps[i]);
		//On charge le sprite lier 
	}

	//Destructeur
	~Environnement(){}

	//Accesseurs
	void addObj(ToDraw o){
		_objs.push_back(o);
	}
	void addPers(ToDraw p){
		_persos.push_back(p);
	}

	ToDraw* getObj(int i){
		return _objs[i];
	}

	Personnage* getPers(int i){
		return _persos[i];
	}

protected:
	std::vector<ToDraw*> _objs;
	std::vector<Personnage*> _persos;

};

#endif
