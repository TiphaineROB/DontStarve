/// ROB4-POO Projet Don't Starve
/// Fichier : Personnage.hpp
///	Autheurs : Benjamin Delbos et Tiphaine Diot
/// Classe Personnage

#ifndef PERS_HPP
#define PERS_HPP

#include <iostream>
//#include "Poche.hpp"
#include "Outil.hpp"
#include "ToDraw.hpp"
#include "Hache.hpp"
#include "Pioche.hpp"
#include "ElemEnv.hpp"
#include "Arbre.hpp"
#include "Baie.hpp"
#include "Feu.hpp"
#include "Roche.hpp"

typedef std::map<sf::Keyboard::Key, std::string> cmd_t;
typedef std::map<std::string, int> poche_t;

class Personnage : public ToDraw
{
public:
	Personnage();
	Personnage(int i){
		if(i==1){
			//std::cout << "Premier" << std::endl;
		if(!this->texture.loadFromFile("../images/perso.png"))
		{
			std::cout << "BAD MADAFAKA" << std::endl;
		}
		_position[0] = 1280/2;
		_position[1] = 720/2;
	this->sprite.setPosition(sf::Vector2f(_position[0],_position[1]));
	}
	if(i==2){
	if(!this->texture.loadFromFile("../images/perso2.png"))
	{
		std::cout << "BAD MADAFAKA" << std::endl;
	}
	_position[0] = 1280/2 +40;
	_position[1] = 720/2;
	this->sprite.setPosition(sf::Vector2f(_position[0],_position[1]));
}
  this->sprite.setTexture(this->texture);
  this->sprite.setTextureRect(sf::IntRect(0,2*256/4,576/9,256/4));

		_sens = 'B';
		_faim = 0;
		_fatigue = 0;
		_vie = 4;
		_cmd = createCmd(i); //On associe les commandes au joueur
		_origin[0] = 50; //Correspond au sens horizontal  0 à gauche
		_origin[1] = 50; //Correspond au sens vertical 0 en haut
 		_taillePas = 10;
		_pack["Baie"] = 0;
		_pack["Bois"] = 2; //On commence avec deux bois et deux pierres pour pouvoir créer des outils
		_pack["Pierre"] = 2;
		/*_position[0] = 1280/2;
		_position[1] = 720/2;*/

		std::cout << "Taille du vecteur outil" << _outils.size()<< std::endl;
	}

	~Personnage(){
		for(int i=0; i < _outils.size(); i++)
				delete _outils[i];
		_outils.clear();
		std::cout << "Destructeur Personnage" << std::endl;
	}

	cmd_t getCmd(){
		return _cmd;
	}

	int getLife(){return _vie;}
	void setLife(int i ){_vie = i; }
	int getFaim(){return _faim;}
	int getFatigue(){return _fatigue;}
	std::string getSens(){ return _sens;}
	int getOriginX(){return this->_origin[0];}
	int getOriginY(){return this->_origin[1];}


	void addOut(Outil* o){
		_outils.push_back(o);
	}
	int getNbOutils(){return _outils.size();}
	Outil* getOut(){return _outils[0];}

	void setRessourceBois(int i){ _pack["Bois"] = i;}
	int getRessourceBois(){ return _pack["Bois"];}
	void setRessourcePierre(int i){ _pack["Pierre"] = i;}
	int getRessourcePierre(){ return _pack["Pierre"];}
	void setRessourceBaie(int i){ _pack["Baie"] = i;}
	int getRessourceBaie(){ return _pack["Baie"];}

	bool bouger(std::string s, int sizeX, int sizeY);
	bool creerHache();
	bool allumerFeu(int i);
	bool creerPioche();
	int updateLife();
	int manger();
	int dormir();
	int reveil();

	bool interagir(ElemEnv* env);
	bool changerOut();

protected:

	cmd_t createCmd(int i);

	cmd_t _cmd;
	//Poche* _myPack;
	poche_t _pack;
	std::vector<Outil*> _outils;
	std::string _sens;
	int _faim;
	int _fatigue;
	int _vie;
	int _taillePas;

};

#endif
