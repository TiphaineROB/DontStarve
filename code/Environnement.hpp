/// ROB4-POO Projet Don't Starve
/// Fichier : Environnement.hpp
///	Autheurs : Benjamin Delbos et Tiphaine Diot
/// Classe Environnement

#ifndef ENV_HPP
#define ENV_HPP

#include <iostream>
#include "ToDraw.hpp"
#include "Personnage.hpp"

class Environnement : public ToDraw{

public: 

	//Constructeurs
	Environnement(){}		
	Environnement(int nbP, std::string s)
	{
		for(int i=0; i < nbP; i++)
			addPers(Personnage(i+1));
		this->setTexture("../images/PageAccueilBtn.png");
		//On charge le sprite lier 
	}

	//Destructeur
	~Environnement(){}

	//Accesseurs
	void addObj(ToDraw o){
		_objs.push_back(o);
	}
	void addPers(Personnage p){
		_persos.push_back(p);
	}

	ToDraw getObj(int i){
		return _objs[i];
	}

	Personnage getPers(int i){
		return _persos[i];
	}

	Environnement& operator=(const Environnement& e){
			this->_objs = e._objs;
			this->_persos = e._persos;
			return *this;
	} 


protected:
	std::vector<ToDraw> _objs;
	std::vector<Personnage> _persos;

};

#endif
