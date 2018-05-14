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
	Environnement(int nbP, std::Vector<Personnage> ps, std::string s)
	{
		for(int i=0; i < nbP; i++)
			addPers(ps[i]);
		//On charge le sprite lier 
	}

	//Destructeur
	~Environnement(){
		~_objs;
		~_persos;
	}

	//Accesseurs
	void addObj(ToDraw o){
		_objs.push_back(o);
	}
	void addPers(ToDraw p){
		_persos.push_back(p);
	}

	ToDraw getObj(i){
		return _objs[i];
	}

	Personnage getPers(i){
		return _persos[i];
	}

protected:
	std::Vector<ToDraw> _objs;
	std::Vector<Personnage> _persos;

};

#endif
