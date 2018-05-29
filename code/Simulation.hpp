/// ROB4-POO Projet Don't Starve
/// Fichier : Simulation.hpp
///	Autheurs : Benjamin Delbos et Tiphaine Diot
/// Classe Simulation

#ifndef SIM_HPP
#define SIM_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Environnement.hpp"
#include "ToDraw.hpp"
#include "Arbre.hpp"
#include "Roche.hpp"
#include "Personnage.hpp" 


class Simulation{

public:

	Simulation(){
		_etat = 0; //on met l'état à 0 cela correspond à la page d'accueil
		if(!_textAcc.loadFromFile("../images/PageAccueilBtn.png"))
		{
			std::cout << "BAD MADAFAKA" << std::endl;
		}
		_accueil.setTexture(_textAcc);
		
		if(!_textCmds.loadFromFile("../images/PageAccueilBtn.png"))
		{
			std::cout << "BAD MADAFAKA" << std::endl;
		}
		_cmds.setTexture(_textCmds);

	}

	int getEtat(){return _etat;}
	void setEtat(int val){ _etat = val;}

	sf::Sprite getSprAcc(){ return _accueil; }
	sf::Sprite getSprCmds(){ return _cmds; }
	sf::Sprite getSprEnv(){ return _myEnv->getSprite(); }

	Environnement* creerEnv(int nbJ, std::string s);
	Environnment* Simulation::tour(sf::Keyboard k)
	int isClicAccueil(int x, int y);
	int isClicChoixJ(int x, int y);

protected:
	double _timer;
	Environnement* _myEnv;
	int _day; 
	int _etat; 
	sf::Texture _textAcc;
	sf::Texture _textCmds;
	sf::Sprite _accueil;
	sf::Sprite _cmds;
};


int Simulation::isClicAccueil(int x, int y)
{
	if( (x >= 20 && x <= 280) && (y >= 530 && y <= 680)) //On est dans la zone du bouton play
		return 1;
	else if( (x >= 970 && x <= 1230) && (y >= 530 && y <= 680)) //On est dans la zone du bouton quitter
		return -1;
	else 
		return 0; //On a clické n'importe ou sur l'écran
}

int Simulation::isClicChoixJ(int x, int y)
{
	return 0;
}


Environnement* Simulation::creerEnv(int nbJ, std::string s){

	this->_myEnv = new Environnement();

	for(int i = 0; i < nbJ; i++)
	{
		this->_myEnv->addPers(Personnage(i+1)); //On lui passe son numero pour lui attribuer la bonne map pour ses commandes
	}
	
	//Creation des arbres, on en veut un nombre compris entre 1 et 10
	int nbrandom = rand()%9 +1; 
	for(int i=0; i < nbrandom; i++)
	{
		this->_myEnv->addObj(Arbre()); //donner une position random aussi
	}

	//Creation des roches de la même manière
	nbrandom = rand()%9 +1; 
	for(int i=0; i < nbrandom; i++)
	{
		this->_myEnv->addObj(Arbre()); //donner une position random aussi
	}

	//Dans la version 0 on ne crée pas de betes
	return this->_myEnv;
}

Environnment* Simulation::tour(sf::Keyboard k){
	
	//Il faut tester pour quel joueur la touche doit être prise en compte
	//Puis trouver la bonne action à réaliser
	//Si c'est une touche qui n'existe pas on renvoie quand même l'environnement sans rien changer
	
	return this->_myEnv; 
}



#endif
