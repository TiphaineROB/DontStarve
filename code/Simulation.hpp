/// ROB4-POO Projet Don't Starve
/// Fichier : Simulation.hpp
///	Autheurs : Benjamin Delbos et Tiphaine Diot
/// Classe Simulation

#ifndef SIM_HPP
#define SIM_HPP

//#include <SFML/Graphics.hpp> Normalement pas nécessaire
#include <iostream>
#include "Environnement.hpp"
#include "Arbre.hpp"
#include "Roche.hpp"


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

		_day = 0;
		_timer = 12; //Doit correspondre à 12 minutes, toutes les 10min on passe en nuit et toutes les 4 on perds de la vie
		_stateDay = true; //On commence la journée
	}

	int getEtat(){return _etat;}
	void setEtat(int val){ _etat = val;}

	bool changeStateDay(){
		if(_stateDay == true)
			_stateDay = false; 
		else
		{
			_stateDay = true; 
			_day++;
		}
		return _stateDay;
	}


	sf::Sprite getSprAcc(){ return _accueil; }
	sf::Sprite getSprCmds(){ return _cmds; }
	sf::Sprite getSprEnv(){ return _myEnv->getSprite(); }

	Environnement* creerEnv(int nbJ, std::string s);
	Environnement* tour(sf::Keyboard::Key k, double duration);
	bool appelActions(std::string s, Personnage p);
	int isClicAccueil(int x, int y);
	int isClicChoixJ(int x, int y);

protected:
	double _timer;
	Environnement* _myEnv;
	bool _stateDay; //Correspond si on est en journée ou pendant la nuit
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

	this->_myEnv = new Environnement(nbJ, s);
	
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


bool Simulation::appelActions(std::string s, Personnage p){

	if(s.compare("Interagir"))
	{
		return true; 
	}
	else if(s.compare("Manger"))
	{
		p.manger();
		return true; 
	}
	else if(s.compare("CreerHache"))
	{
		p.creerHache();
		return true; 
	}
	else if(s.compare("CreerPioche"))
	{
		p.creerPioche();
		return true;
	}
	else if(s.compare("AllumerFeu"))
	{
		p.allumerFeu();
		return true; 
	}
	else if(s.compare("Dormir"))
	{
		p.dormir();
		return true; 
	}
	else
	{
		p.bouger(s, this->_myEnv->getSizeX(), this->_myEnv->getSizeY()); //On lui passe la taille de l'image de l'environnement
		return true; 
	}
	return false; 
}


Environnement* Simulation::tour(sf::Keyboard::Key k, double duration){
	
	//Il faut tester pour quel joueur la touche doit être prise en compte
	std::map<sf::Keyboard::Key, std::string>::iterator cmd_it;
	std::string actionJ;
	for(int i=0 ; i < this->_myEnv->getNbPers(); i++)
	{
		cmd_t temp = this->_myEnv->getPers(i).getCmd(); 
		cmd_it = temp.find(k);
  		if(cmd_it != temp.end())
  		{
  			std::cout << "Le joueur " << i+1 << "a joue" << std::endl; //On a trouvé si un des joueurs à jouer
  			actionJ = temp.find(k)->second; //On récupère la String associé à la key
  			//Maintenant on doit lancer l'action correspondante
  			this->appelActions(actionJ, this->_myEnv->getPers(i));
  		}	
  	}

  	if(duration == 10)
  	{
  		this->changeStateDay();
  	} 

	return this->_myEnv; 
}


#endif
