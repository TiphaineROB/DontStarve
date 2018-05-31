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

typedef std::map<sf::Keyboard::Key, std::string> cmd_t;


class Personnage : public ToDraw
{
public:
	sf::Texture texture;
	sf::Sprite sprite;
	
	Personnage();
	Personnage(int i){
		_sens = 'B';
		_faim = 0;
		_fatigue = 0;
		_vie = 5;
		_myPack = new Poche();	
		_cmd = createCmd(i);
		_origin[0] = 50; //Correspond au sens horizontal  0 à gauche
		_origin[1] = 50; //Correspond au sens vertical 0 en haut
 		_taillePas = 10;
	}

	cmd_t getCmd(){
		return _cmd;
	}

	bool bouger(std::string s, int sizeX, int sizeY);
	bool creerHache();
	bool allumerFeu();
	bool creerPioche();
	int updateLife();
	int manger();
	int dormir();
	int reveil();
	
	bool interagir(ElemEnv env);
	Outil changerOut(int i);

protected:
	
	bool casser(ElemEnv e);
	bool couper(ElemEnv e);
	cmd_t createCmd(int i);
		
	cmd_t _cmd;
	Poche* _myPack;
	std::vector<Outil> _outils;
	char _sens;
	int _faim;
	int _fatigue;
	int _vie;	
	int _taillePas; 

};

#endif
