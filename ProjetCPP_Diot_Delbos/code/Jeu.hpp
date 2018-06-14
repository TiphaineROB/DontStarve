/// ROB4-POO Projet Don't Starve
/// Fichier : jeu.hpp
///	Autheurs : Benjamin Delbos et Tiphaine Diot
/// Classe Jeu

#ifndef JEU_HPP
#define JEU_HPP

//#include <SFML/Graphics.hpp>
#include <iostream>
#include "Personnage.hpp"
#include "Outil.hpp"
#include "Arbre.hpp"
#include "Roche.hpp"
#include "Baie.hpp"
#include "Feu.hpp"
#include <math.h>
//#include "ElemAffichage.hpp"

class Jeu{

public:

	//Dans le constructeur de la simulation on lui donne les trois sprites généraux et on initialise les valeurs de ces variables
	Jeu()
	{
		//Initialisation des sprites et textures pour le jeu
		std::cout << "Constructeur jeu" << std::endl;
		if(!_textAcc.loadFromFile("../images/PageAccueilBtn.png"))
		{
			std::cout << "Pas de page accueil" << std::endl;
		}
		_accueil.setTexture(_textAcc);

		if(!_textCmds.loadFromFile("../images/choixNbJ.png"))
		{
			std::cout << "Pas de page choix joueur" << std::endl;
		}
		_cmds.setTexture(_textCmds);

		if(!_textEnv.loadFromFile("../images/carte.png"))
		{
			std::cout << "Pas de carte" << std::endl;
		}
		_env.setTexture(_textEnv);

		if(!_textEnd.loadFromFile("../images/PageEnd.png"))
		{
			std::cout << "Pas de page end" << std::endl;
		}
		_end.setTexture(_textEnd);


		//Initialisation des variables de jeu
		_etat = 0; //on met l'état à 0 cela correspond à la page d'accueil
		_day = 0;
		_timer = 300000; //Doit correspondre à 10 minutes (soit 720s), toutes les 10min on passe en nuit et toutes les 4 on perds de la vie
		_stateDay = true; //On commence la journée
		_ifEnv = false; //On ne crée pas l'environnement en même temps que la simulation
	}

		//Opérateur =
	Jeu& operator=(const Jeu& j){
			this->_objs = j._objs;
			this->_persos = j._persos;
			return *this;
	}

	//Destructeur
	~Jeu()
	{
		for(int i=0; i < _objs.size(); i++)
				delete _objs[i];
		for(int i=0; i < _persos.size(); i++)
				delete _persos[i];

		std::cout << "Destructeur jeu" << std::endl;
	}

	//Accesseur/setter pour l'état du jeu
	int getEtat(){return _etat;}
	void setEtat(int val)
	{
		if(val!=0 || val !=1 || val!=2 || val!=3)
			_etat = val;
		else
			throw("Numero d'état non valide");
	}

	ElemEnv& getObj(int i){
		return *_objs[i];
	}

	Personnage& getPers(int i){
		return *_persos[i];
	}

	Feu& getFeu(int i)
	{
		return *_feu[i];
	}

	int getNbFeu()
	{
		return _feu.size();
	}

	int getNbPers(){
		return _persos.size();
	}
	int getNbObjs(){
		return _objs.size();
	}

	//Accesseur timer et sizes
	double getTimer(){return _timer;}
	int getSizeX(){return 1280;}
	int getSizeY(){return 720;}

	//Accesseurs pour les sprites du jeu
	sf::Sprite getSprAcc(){ return _accueil; }
	sf::Sprite getSprCmds(){ return _cmds; }
	sf::Sprite getSprEnd(){ return _end; }
	sf::Sprite getSprEnv(){ return _env; }

	//Fonction permettant de vérifier si un clic est dans la bonne zone en fonction du sprite afficher
	int isClicAccueil(int x, int y);
	int isClicChoixJ(int x, int y);
	int isClicEnd(int x, int y);


	//Accesseur et fonction créatrice de l'environnement de la simulation
	//void setObjet(std::vector<ElemEnv> elements){_objs = elements;}
	//void setPersos(std::vector<Personnage> perso){_persos = perso;}

	//Jeu* creerEnv(int nbJ, bool AI);
	void creerEnv(int x, int y, int z);
	void  creerJeu(int nbJ);
	//Fonction permettant d'interprêter l'appui sur une touche et de lancer l'action correspondante
	int tour(sf::Keyboard::Key k, long duration);
	clock_t clockCurrent;
	clock_t clockStart;
	bool jour;

	void	creerAffichage();
	void affichageStatique(sf::RenderWindow& window, int nbP);
	void affichageFeu(sf::RenderWindow& window);
	void affichagePerso(sf::RenderWindow& window);
	void affichageElement(sf::RenderWindow& window);

	std::vector<sf::Sprite*>& getAffichage(){return _affichage;}
	sf::Sprite& getAffichage(int i){return *_affichage[i];}

//Gestion des interactions :
double distanceToPerso(ElemEnv* element, Personnage& perso);
ElemEnv* getCloserObject(Personnage& perso);

void horloge();

private:
	bool appelActions(std::string s, Personnage& p);

	double _timer;
	bool _ifEnv;
	bool _stateDay; //Correspond si on est en journée ou pendant la nuit
	int _day;
	int _etat; //Etat du jeu 0 si on est sur la page d'accueil, 1 si sur la page des commandes, 2 pendant le jeu
	sf::Texture _textAcc;
	sf::Texture _textCmds;
	sf::Texture _textEnv;
	sf::Texture _textEnd;
	sf::Sprite _accueil;
	sf::Sprite _cmds;
	sf::Sprite _env;
	sf::Sprite _end;
	std::vector<ElemEnv*> _objs;
	std::vector<Personnage*> _persos;
	std::vector<Feu*> _feu;
	//ATTRIBUTS POUR L'affichageStatique
	std::vector<sf::Sprite*> _affichage;
	std::vector<sf::Texture*> _texture;
};

#endif
