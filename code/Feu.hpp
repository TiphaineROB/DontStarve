/// ROB4-POO Projet Don't Starve
/// Fichier : Feu.hpp
///	Autheurs : Benjamin Delbos et Tiphaine Diot
/// Classe Feu

#ifndef FEU_HPP
#define FEU_HPP

#include <iostream>
#include "Outil.hpp"

class Feu : public ElemEnv{

	public: 
		
		Feu(){
			_vie = 4;
		}

		std::string getType(){
			return "Feu";
		}

		void raviver()
		{
			_vie++; //On ravive le feu en lui ajoutant du bois
		}
		void raviver(int nbB)
		{
			_vie+=nbB; //On ravive le feu en lui ajoutant du bois
		}

	protected:
	
};

#endif