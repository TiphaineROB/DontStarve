/// ROB4-POO Projet Don't Starve
/// Fichier : Environnement.hpp
///	Autheurs : Benjamin Delbos et Tiphaine Diot
/// Classe Environnement

#ifndef ENV_HPP
#define ENV_HPP

#include <iostream>
#include "ElemEnv.hpp"
#include "Personnage.hpp"

class Environnement : public ToDraw{

public:

	//Constructeurs
	Environnement(){}
	Environnement(int nbP, std::string s)
	{

		std::cout << "Constructeur Environnement" << std::endl;
		for(int i=0; i < nbP; i++)
			addPers(Personnage(i+1));

		this->setSize(1280,720);


		this->setTexture(s);
		//On charge le sprite lier
		this->setSprite();

	}

	//Destructeur
	~Environnement(){
		std::cout << "Destructeur Environnement" << std::endl;
		_objs.clear();
		_persos.clear();
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

	ElemEnv getCloserElem(Personnage p){
		for(int i=0;i<_objs.size();i++)
		{
				if(p.getSens().compare("B"))
				{
						std::cout << "A faire" << std::endl;
				}
				if(p.getSens().compare("H"))
				{
						std::cout << "A faire" << std::endl;
				}
				if(p.getSens().compare("G"))
				{
						std::cout << "A faire" << std::endl;
				}
				if(p.getSens().compare("D"))
				{
						std::cout << "A faire" << std::endl;
				}
		}
		//Si on a pas trouvé de bon élément on lance une erreur
		throw("Pas d'élément à côté !");
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
