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
		_timer = 720; //Doit correspondre à 12 minutes (soit 720min), toutes les 10min on passe en nuit et toutes les 4 on perds de la vie
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
		_objs.clear();
		_persos.clear();
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

	//Accesseurs pour Personnages et objets
	void addObj(ElemEnv e){
		_objs.push_back(e);
	}
	void addPers(Personnage p){
		_persos.push_back(p);
	}

	ElemEnv& getObj(int i){
		return _objs[i];
	}

	Personnage& getPers(int i){
		return _persos[i];
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
	Personnage& getPersonnage(int i){return this->_persos[i];}

	//Fonction permettant de vérifier si un clic est dans la bonne zone en fonction du sprite afficher
	int isClicAccueil(int x, int y);
	int isClicChoixJ(int x, int y);
	int isClicEnd(int x, int y);


	//Accesseur et fonction créatrice de l'environnement de la simulation
	void setObjet(std::vector<ElemEnv> elements){_objs = elements;}
	void setPersos(std::vector<Personnage> perso){_persos = perso;}

	//Jeu* creerEnv(int nbJ, bool AI);
	void creerEnv(int x, int y);
	void  creerJeu(int nbJ);
	//Fonction permettant d'interprêter l'appui sur une touche et de lancer l'action correspondante
	int tour(sf::Keyboard::Key k, long duration);

	void	creerAffichage();
	void affichageStatique(sf::RenderWindow& window);

	std::vector<sf::Sprite*>& getAffichage(){return _affichage;}
	sf::Sprite& getAffichage(int i){return *_affichage[i];}

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
	std::vector<ElemEnv> _objs;
	std::vector<Personnage> _persos;
	//ATTRIBUTS POUR L'affichageStatique
	std::vector<sf::Sprite*> _affichage;
};

/*
* Fonction qui regarde si on a cliqué sur une zone qui entraine une nouvelle action sur la page d'accueil
*/
int Jeu::isClicAccueil(int x, int y)
{
	if( (x >= 20 && x <= 280) && (y >= 530 && y <= 680)) //On est dans la zone du bouton play
		return 1;
	else if( (x >= 970 && x <= 1230) && (y >= 530 && y <= 680)) //On est dans la zone du bouton quitter
		return -1;
	else
		return 0; //On a clické n'importe ou sur l'écran
}


/*
* Fonction qui regarde si on a cliqué sur une zone qui entraine une nouvelle action sur la page du choix nombre joueur
*/
int Jeu::isClicChoixJ(int x, int y)
{
	if( (x >= 345 && x <= 515) && (y >= 600 && y <= 690)) //On est dans la zone du bouton joueur 1
		return 1;
	else if( (x >= 755 && x <= 930) && (y >= 595 && y <= 685)) //On est dans la zone du joueur 2
		return 2;
	else
		return 0; //On a clické n'importe ou sur l'écran
}

/*
* Fonction qui regarde si on a cliqué sur le bouton qui nous permet de quitter le jeu
*/
int Jeu::isClicEnd(int x, int y)
{
	if( (x >= 775 && x <= 1050) && (y >= 500 && y <= 660)) //On est dans la zone du bouton quitter
		return -1;
	else
		return 0; //On a clické n'importe ou sur l'écran
}

/*
* Fonction qui crée le reste de l'environnement, les élements plus les personnages
*/
void Jeu::creerJeu(int nbJ)
{
	if (nbJ==1)
	{
		Personnage* perso = new Personnage(1);
		Personnage& p = *perso;
		this->_persos.push_back(p);
	}
	else if (nbJ == 2)
	{
		Personnage *perso1 = new Personnage(1);
		Personnage& p1 = *perso1;
		this->_persos.push_back(p1);
		Personnage* perso2 = new Personnage(2);
		Personnage& p2 = *perso2;
		this->_persos.push_back(p2);
	}
	creerEnv(rand()%10,rand()%10);
	//	creerAffichage();
}

void Jeu::creerEnv(int x, int y)
{
  int n1,n2;
	for(int i=0 ; i<x; i++)
	{
		std::cout << "CREATION ELEMENTS" <<std::endl;
  	n1 = rand();
  	n2 = rand();
		Arbre* arbre = new Arbre(n1%1280,n2%720);
		Arbre& arbre1 = *arbre;
		this->_objs.push_back(arbre1);
	}
	for(int i=0 ; i<y; i++)
	{
		std::cout << "CREATION ELEMENTS" <<std::endl;
   	n1 = rand();
  	n2 = rand();
  	Roche* roche = new Roche(n1%1280,n2%720);
		Roche& roche1 = *roche;
		this->_objs.push_back(roche1);
	}
	std::cout << " Elements créés"<< std::endl;
}

/*
* Fonction qui fait correspondre à la string issue du hashmap contenant les commandes d'un joueur et l'action associée
* Appelle les fonctions internes du joueur passé en paramètre
*/
bool Jeu::appelActions(std::string s, Personnage& p){
	if(s == "Interagir")
	{
		//On cherche un élément propre et dans la bonne direction
		for(int i =0; i<9; i++){
    	if (abs(p.getPosition(0)-_objs[i].getPosition(0))<20 && abs(p.getPosition(1)-_objs[i].getPosition(1))<20)
    	{
      	std::cout << "Interaction Possible" << std::endl;
				p.interagir(_objs[i]);
				return true;
			}
  	}
		return false;
	}
	else if(s == "Manger")
	{
		p.manger();
		return true;
	}
	else if(s == "CreerHache")
	{
		if(p.creerHache())
			return true;
	}
	else if(s == "CreerPioche")
	{
		if(p.creerPioche())
			return true;
	}
	else if(s == "AllumerFeu")
	{
		if(p.allumerFeu())
			return true;
	}
	else if(s == "Dormir")
	{
		p.dormir();
		return true;
	}
	else
	{
		p.bouger(s, this->getSizeX(), this->getSizeY()); //On lui passe la taille de l'image de l'environnement
		return true;
	}
	return false;
}


/*
* Fonction qui permet de jouer un "tour" est appelé à chaque fois qu'une touche est appuyée une fois que le jeu est lancé
* Si la touche appuyée correspond à une des commandes d'un joueur on appelle la fonction appelActions qui permet de jouer l'action correspondante
*/
int Jeu::tour(sf::Keyboard::Key k, long duration){

	//Il faut tester pour quel joueur la touche doit être prise en compte
	std::map<sf::Keyboard::Key, std::string>::iterator cmd_it;
	std::string actionJ;
	for(int i=0 ; i < this->getNbPers(); i++)
	{
		cmd_t temp = this->getPers(i).getCmd();
		cmd_it = temp.find(k);
  		if(cmd_it != temp.end())
  		{
  			std::cout << "Le joueur " << i+1 << "a joue" << std::endl; //On a trouvé si un des joueurs à jouer
  			actionJ = temp.find(k)->second; //On récupère la String associé à la key
  			//Maintenant on doit lancer l'action correspondante
  			this->appelActions(actionJ, this->getPers(i));
  		}

  		if(duration % (long)(this->_timer/4) == 0)
  			this->getPers(i).updateLife();
  	}
	if(this->getNbPers() == 2)
  {
			if(this->getPers(0).getLife() == 0 || this->getPers(1).getLife() == 0 )
  		return 3; //Les deux joueurs ont perdus en même temps
  	else if(this->getPers(0).getLife() == 0)
  		return 1; //Le joueur 1 a perdu
  	else if(this->getPers(1).getLife() == 0)
  		return 2; //Le joueur 2 a perdu
	}
	if(this->getNbPers() == 1)
  {
		if(this->getPers(0).getLife() == 0)
  		return 1; //Le joueur 2 a perdu
	}
  	//Si aucun des joueurs n'est mort on renvoie 0 pour dire de continuer
	return 0;
}

void Jeu::creerAffichage()
{
	sf::Texture* indicateurVie = new sf::Texture();
	sf::Sprite* perso1 = new sf::Sprite();
	sf::Sprite* perso2 = new sf::Sprite();
	indicateurVie->loadFromFile("../images/indicateurVie.png");
	perso1->setTexture(*indicateurVie);
	perso1->setTextureRect(sf::IntRect(0,0,129,134));
	perso2->setTexture(*indicateurVie);
	perso2->setTextureRect(sf::IntRect(213-134,0,134,129));
	perso2->setPosition(sf::Vector2f(1280-134,0));
	sf::Texture* jauge = new sf::Texture();
	jauge->loadFromFile("../images/EnsembleJauges.png");
	sf::Sprite* jauge1 = new sf::Sprite();
	sf::Sprite* jauge2 = new sf::Sprite();
	sf::Sprite* jauge3 = new sf::Sprite();
	sf::Sprite* jauge4 = new sf::Sprite();
	sf::Sprite* jauge5 = new sf::Sprite();
	sf::Sprite* jauge6 = new sf::Sprite();

	jauge1->setTexture(*jauge);
	jauge1->setTextureRect(sf::IntRect(0,0,72,215/5));
	jauge1->setPosition(sf::Vector2f(134,0));
	*jauge2 = *jauge1;
	*jauge3 = *jauge1;
	*jauge4 = *jauge1;
	*jauge5 = *jauge1;
	*jauge6 = *jauge1;

	jauge2->setPosition(sf::Vector2f(134,215/5));
	jauge3->setPosition(sf::Vector2f(134,2*215/5));

	jauge4->setPosition(sf::Vector2f(1280-134-72,0));
	jauge5->setPosition(sf::Vector2f(1280-134-72,215/5));
	jauge6->setPosition(sf::Vector2f(1280-134-72,2*215/5));

	sf::Sprite& j1 = *jauge1;
	sf::Sprite& j2 = *jauge2;
	sf::Sprite& j3 = *jauge3;
	sf::Sprite& j4 = *jauge4;
	sf::Sprite& j5 = *jauge5;
	sf::Sprite& j6 = *jauge6;

	_affichage.push_back(perso1);
	_affichage.push_back(perso2);
	_affichage.push_back(jauge1);
	_affichage.push_back(jauge2);
	_affichage.push_back(jauge3);
	_affichage.push_back(jauge4);
	_affichage.push_back(jauge5);
	_affichage.push_back(jauge6);
/*
_affichage.push_back(*perso1);
_affichage.push_back(*perso2);
_affichage.push_back(*jauge1);
_affichage.push_back(*jauge2);
_affichage.push_back(*jauge3);
_affichage.push_back(*jauge4);
_affichage.push_back(*jauge5);
_affichage.push_back(*jauge6);*/
}
/*
void Jeu::affichageStatique(sf::RenderWindow& window)
{
//Pour PERSONNAGE 1
std::cout << "PERSONNAGE VIE : " << _persos[0].getLife() << std::endl;
_affichage[2]->setTextureRect(sf::IntRect(0,215/5*(4-_persos[0].getLife()),72,215/5));
//_affichage[2]->setTextureRect(sf::IntRect(0,0,10,10 ));
_affichage[3]->setTextureRect(sf::IntRect(0,215/5*(4-_persos[0].getFatigue()),72,215/5));
_affichage[4]->setTextureRect(sf::IntRect(0,215/5*(4-_persos[0].getFaim()),72,215/5));
//Pour PERSONNAGE 2
_affichage[5]->setTextureRect(sf::IntRect(0,215/5*(4-_persos[0].getLife()),72,215/5));
_affichage[6]->setTextureRect(sf::IntRect(0,215/5*(4-_persos[0].getFatigue()),72,215/5));
_affichage[7]->setTextureRect(sf::IntRect(0,215/5*(4-_persos[0].getFaim()),72,215/5));

for(int i =0; i<_affichage.size();i++)
{
	window.draw(*_affichage[i]);
}
}*/
#endif
