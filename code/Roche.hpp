/// ROB4-POO Projet Don't Starve
/// Fichier : Roche.hpp
///	Autheurs : Benjamin Delbos et Tiphaine Diot
/// Classe Roche


#ifndef ROC_HPP
#define ROC_HPP

#include <iostream>
#include <string>

class Roche : public SurCarte
{

public: 
	Roche(){
		this._vie = 3; //Une roche est cassée au bout de 3 coups
		//On doit lui attribuer un sprite aussi
	}

	string getType(){
		return "Roche";
	}

protected:


};

#endif