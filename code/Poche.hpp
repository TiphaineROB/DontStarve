/// ROB4-POO Projet Don't Starve
/// Fichier : Ressource.hpp
///	Autheurs : Benjamin Delbos et Tiphaine Diot
/// Classe Ressource

#ifndef POCHE_HPP
#define POCHE_HPP

#include <iostream>

class Poche{

	public: 
		Poche(){
			_nbPierre = 0;
			_nbBois = 0;		
		}
		
		int getNbPierre() {return _nbPierre; }
		int getNbBois() {return _nbBois; }
		const int getNbPierre() const {return _nbPierre; } 
		const int getNbBois() const {return _nbBois; }
		void addPierre(int i) { _nbPierre +=i; }
		void addBois(int i) { _nbBois +=i; }

		Poche& operator=(const Poche& p){
			this->_nbPierre = p.getNbPierre();
			this->_nbBois = p.getNbBois();
			return *this;
		} 

	protected:
		int _nbPierre;
		int _nbBois;
	
};

#endif
