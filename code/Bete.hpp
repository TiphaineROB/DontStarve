/// ROB4-POO Projet Don't Starve
/// Fichier : Bete.hpp
///	Autheurs : Benjamin Delbos et Tiphaine Diot
/// Classe Bete


#ifndef BETE_HPP
#define BETE_HPP

#include <iostream>

class Bete : public Drawable{

	public: 
		Bete()
		{
			_vie = 3;
			_danger = 0; 
		}	
	
		std::string getType(){
			return "Bete indefinie";
		}

		int getVie(){
			return this._vie;
		}

		//Fonction qui dit si le coup que l'élement a reçu est destructif
		bool coupMortel(){
			_vie--;
			if(vie==0)
				return true;
			else
				return false; 
		}

	protected:
		int _vie; 
		int _danger; //Niveau de dangerosité de la bête

};

#endif
