/// ROB4-POO Projet Don't Starve
/// Fichier : Environnement.hpp
///	Autheurs : Benjamin Delbos et Tiphaine Diot
/// Classe Environnement

#ifndef ENV_HPP
#define ENV_HPP

#include <iostream>
#include "ElemEnv.hpp"
#include "Personnage.hpp"
#include "AI.hpp"
#include "Arbre.hpp"

class Environnement : public ToDraw{

public:

	//Constructeurs
	Environnement(){}
	Environnement(int nbP, std::string s, bool AI)
	{

		std::cout << "Constructeur Environnement" << std::endl;
		this->setSize(1280,720);
		this->setTexture(s);
		//On charge le sprite lier
		this->setSprite();
		// Arbre arbre;
		// this->addObj(arbre);
		for(int i=0; i < nbP; i++)
		{
			Personnage p(i+1);
//			_persos.push_back(p);
		}
		/*if(AI) //On est dans le mpment où on a une IA
		{
			addPers(new AI());
		}*/
	}

	//Destructeur
	~Environnement(){
		_objs.clear();
		_persos.clear();
		std::cout << "Destructeur Environnement" << std::endl;
	}

	//Accesseurs
	void addObj(ElemEnv e){
		_objs.push_back(e);
	}
	void addPers(Personnage p){
		_persos.push_back(p);
	}

	ElemEnv getObj(int i){
		return _objs[i];
	}

	Personnage getPers(int i){
		return _persos[i];
	}

	int getNbPers(){
		return _persos.size();
	}

	Environnement& operator=(const Environnement& e){
			this->_objs = e._objs;
			this->_persos = e._persos;
			return *this;
	}


protected:
	std::vector<ElemEnv> _objs;
	std::vector<Personnage> _persos;
};

#endif
