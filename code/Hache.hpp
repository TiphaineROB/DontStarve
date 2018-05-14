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
		Hache(){
			_vie = 5;
		}
		string getType(){
			return "Hache";
		}

		void utiliser(){
			_vie--; 
			if(vie==0)
				delete this;
		}
};

#endif