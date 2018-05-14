/// ROB4-POO Projet Don't Starve
/// Fichier : Feu.hpp
///	Autheurs : Benjamin Delbos et Tiphaine Diot
/// Classe Feu

#ifndef FEU_HPP
#define FEU_HPP

#include <iostream>
#include "Outil.hpp"

class Feu : public Outil{

	public: 
		
		Feu(){
			_vie = 4;
		}

		string getType(){
			return "Feu";
		}

		void raviver(int nbB)
		{
			_vie+=nbB; //On ravive le feu en lui ajoutant du bois
		}

	protected:
	
};

#endif