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

		bool interagir(std::string s){
			 raviver();
			 return true;
		}
		int getRessource(){return 0;}
		bool coupDestructif()
		{
			return false; //Il n'y a jamais de coup destructif pour le feu
		}

};

#endif
