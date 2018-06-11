/// ROB4-POO Projet Don't Starve
/// Fichier : Pioche.hpp
///	Autheurs : Benjamin Delbos et Tiphaine Diot
/// Classe Pioche

#ifndef PIOC_HPP
#define PIOC_HPP

#include <iostream>
#include "Outil.hpp"

class Pioche : public Outil{

	public:
		Pioche(){
			_vie = 5;
		}

		std::string getType(){
			return "Pioche";
		}

		void utiliser(){
			_vie--;
			if(_vie==0)
				delete this;
		}


};

#endif
