/// ROB4-POO Projet Don't Starve
/// Fichier : Personnage.hpp
///	Autheurs : Benjamin Delbos et Tiphaine Diot
/// Classe Personnage

#ifndef PERS_HPP
#define PERS_HPP

#include <iostream>
#include "Poche.hpp"
#include "Outil.hpp"
#include "ToDraw.hpp"
#include "Hache.hpp"
#include "Pioche.hpp"
#include "ElemEnv.hpp"
//#include "Ressource.hpp"

class Personnage : public ToDraw
{
public:
	sf::Texture texture;
	sf::Sprite sprite;
	
	Personnage();
	//Personnage(){
	//	_sens = 'B';
	//	_faim = 0;
	//	_fatigue = 0;
	//	_vie = 5;
	//	_myPack = new Poche();	
	//	_nbComm = 0;
	//}
	Personnage(int i){
		_sens = 'B';
		_faim = 0;
		_fatigue = 0;
		_vie = 5;
		_myPack = new Poche();	
		_nbComm = i;
	}

	bool creerHache();
	bool allumerFeu();
	bool creerPioche();
	int manger();
	int dormir();
	int reveil();
	
	bool interagir(ElemEnv env);
	Outil changerOut(int i);

protected:
	
	bool casser(ElemEnv e);
	bool couper(ElemEnv e);

	Poche* _myPack;
	std::vector<Outil> _outils;
	char _sens;
	int _faim;
	int _fatigue;
	int _vie;
	int _nbComm;
};

#endif
