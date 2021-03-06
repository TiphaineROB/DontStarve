/// ROB4-POO Projet Don't Starve
/// Fichier : Hache.hpp
///	Autheurs : Benjamin Delbos et Tiphaine Diot
/// Classe Hache

#ifndef HACH_HPP
#define HACH_HPP

#include <iostream>
#include "Outil.hpp"

class Hache : public Outil{

	public:
		Hache():Outil(){
			_vie = 5;
		}
		
		std::string getType(){
			return "Hache";
		}

		bool utiliser(){
			_vie--;
			if(_vie==0)
				return false;
			return true;
		}
};

#endif
