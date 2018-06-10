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

typedef std::map<sf::Keyboard::Key, std::string> cmd_t;
typedef std::map<std::string, int> poche_t;

class Personnage : public ToDraw
{
public:
	Personnage();
	Personnage(int i){
		if(!this->texture.loadFromFile("../images/perso.png"))
  {
    std::cout << "BAD MADAFAKA" << std::endl;
  }
  this->sprite.setTexture(this->texture);
  this->sprite.setTextureRect(sf::IntRect(0,2*256/4,576/9,256/4));
  this->sprite.setPosition(sf::Vector2f(1280/2, 720/2));

		_sens = 'B';
		_faim = 0;
		_fatigue = 0;
		_vie = 5;
		_cmd = createCmd(i);
		_origin[0] = 50; //Correspond au sens horizontal  0 à gauche
		_origin[1] = 50; //Correspond au sens vertical 0 en haut
 		_taillePas = 10;
		_pack["Baie"] = 0;
		_pack["Bois"] = 0;
		_pack["Pierre"] = 0;

	}

	~Personnage(){
		_outils.clear();
		std::cout << "Destructeur Personnage" << std::endl;
	}

	cmd_t getCmd(){
		return _cmd;
	}
	int getLife(){return _vie;}
	std::string getSens(){ return _sens;}
	int getOriginX(){return this->_origin[0];}
	int getOriginY(){return this->_origin[1];}


	void addOut(Outil o){
		_outils.push_back(o);
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
	Outil changerOut();

protected:

	cmd_t createCmd(int i);

	cmd_t _cmd;
	//Poche* _myPack;
	poche_t _pack;
	std::vector<Outil> _outils;
	std::string _sens;
	int _faim;
	int _fatigue;
	int _vie;
	int _taillePas;

};

#endif
