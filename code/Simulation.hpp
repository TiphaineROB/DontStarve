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

	//Dans le constructeur de la simulation on lui donne les trois sprites généraux et on initialise les valeurs de ces variables
	Simulation(){
		if(!_textAcc.loadFromFile("../images/PageAccueilBtn.png"))
		{
			std::cout << "BAD MADAFAKA ACC" << std::endl;
		}
		_accueil.setTexture(_textAcc);
		
		if(!_textCmds.loadFromFile("../images/choixNbJ.png"))
		{
			std::cout << "BAD MADAFAKA CMD" << std::endl;
		}
		_cmds.setTexture(_textCmds);

		if(!_textCmds.loadFromFile("../images/PageEnd.png"))
		{
			std::cout << "BAD MADAFAKA END" << std::endl;
		}
		_cmds.setTexture(_textEnd);

		_etat = 0; //on met l'état à 0 cela correspond à la page d'accueil
		_day = 0;
		_timer = 720; //Doit correspondre à 12 minutes (soit 720min), toutes les 10min on passe en nuit et toutes les 4 on perds de la vie
		_stateDay = true; //On commence la journée
	}

	//Destructeur
	~Simulation()
	{
		delete this->_myEnv;

		std::cout << "Destructeur simulation" << std::endl;
	}

	//Accesseur pour l'état du jeu
	int getEtat(){return _etat;}
	void setEtat(int val)
	{ 
		if(val!=0 || val !=1 || val!=2 || val!=3)
			_etat = val;
		else
			throw("Numero d'état non valide");
	}

	//Fonction permettant de changer le jour et l'état de la journée au cours du jeu
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


	//Accesseurs pour les sprites du jeu
	sf::Sprite getSprAcc(){ return _accueil; }
	sf::Sprite getSprCmds(){ return _cmds; }
	sf::Sprite getSprEnd(){ return _end; }
	sf::Sprite getSprEnv(){ return _myEnv->getSprite(); }
	
	//Fonction permettant de vérifier si un clic est dans la bonne zone en fonction du sprite afficher
	int isClicAccueil(int x, int y);
	int isClicChoixJ(int x, int y);
	int isClicEnd(int x, int y);


	//Accesseur et fonction créatrice de l'environnement de la simulation
	Environnement* getEnv(){return this->_myEnv;}
	Environnement* creerEnv(int nbJ, std::string s);

	//Fonction permettant d'interprêter l'appui sur une touche et de lancer l'action correspondante
	int tour(sf::Keyboard::Key k, long duration);
	bool appelActions(std::string s, Personnage p);
	
protected:
	long _timer;
	Environnement* _myEnv;
	bool _stateDay; //Correspond si on est en journée ou pendant la nuit
	int _day; 
	int _etat; //Etat du jeu 0 si on est sur la page d'accueil, 1 si sur la page des commandes, 2 pendant le jeu
	sf::Texture _textAcc;
	sf::Texture _textCmds;
	sf::Texture _textEnd;
	sf::Sprite _accueil;
	sf::Sprite _cmds;
	sf::Sprite _end;
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
	if( (x >= 345 && x <= 515) && (y >= 600 && y <= 690)) //On est dans la zone du bouton joueur 1
		return 1;
	else if( (x >= 755 && x <= 930) && (y >= 595 && y <= 685)) //On est dans la zone du joueur 2
		return 2;
	else 
		return 0; //On a clické n'importe ou sur l'écran
}

int Simulation::isClicEnd(int x, int y)
{
	if( (x >= 775 && x <= 1050) && (y >= 500 && y <= 660)) //On est dans la zone du bouton quitter
		return -1;
	else 
		return 0; //On a clické n'importe ou sur l'écran
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


int Simulation::tour(sf::Keyboard::Key k, long duration){
	
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
  		
  		if(duration % (long)(this->_timer/4) == 0)
  			this->_myEnv->getPers(i).updateLife();
  	}


  	if(duration % this->_timer == 0) //12 min se sont écoulées donc on change l'état de la journée et éventuellement le numéro du jour
  	{
  		this->changeStateDay();
  	} 

  	if(this->_myEnv->getPers(0).getLife() == 0 || this->_myEnv->getPers(1).getLife() == 0 )
  		return 3; //Les deux joueurs ont perdus en même temps
  	else if(this->_myEnv->getPers(0).getLife() == 0)
  		return 1; //Le joueur 1 a perdu
  	else if(this->_myEnv->getPers(1).getLife() == 0)
  		return 2; //Le joueur 2 a perdu

  	//Si aucun des joueurs n'est mort on renvoie 0 pour dire de continuer
	return 0; 
}


#endif
