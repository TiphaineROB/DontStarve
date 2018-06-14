
//#include "Simulation.hpp"
#include <string>
#include "time.h"
#include "Jeu.hpp"

using namespace sf;

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
* Fonction qui crée les personnages
*/
void Jeu::creerJeu(int nbJ)
{
	if (nbJ==1)
	{
		Personnage* perso = new Personnage(1);
		Personnage& p = *perso;
		this->_persos.push_back(perso);
	}
	else if (nbJ == 2)
	{
		Personnage *perso1 = new Personnage(1);
		Personnage& p1 = *perso1;
		this->_persos.push_back(perso1);
		Personnage* perso2 = new Personnage(2);
		Personnage& p2 = *perso2;
		this->_persos.push_back(perso2);
	}
	creerEnv(rand()%10,rand()%7,rand()%3+1);
	creerAffichage();
	clockStart = clock();
}


/*
* Fonction qui crée leséléments de l'environnement
*/
void Jeu::creerEnv(int x, int y, int z)
{
  int n1,n2;
	for(int i=0 ; i<x; i++)
	{
		std::cout << "Creation des arbres" <<std::endl;
  	n1 = rand();
  	n2 = rand();
		Arbre* arbre = new Arbre(n1%1280,n2%720);
		std::cout << arbre->getPosition(0)<< "arbre" << arbre->getPosition(1)<< std::endl;
		this->_objs.push_back(arbre);
	}
	std::cout << _objs[0]->getPosition(0)<< "arbre" << _objs[0]->getPosition(1)<< std::endl;
	for(int i=0 ; i<y; i++)
	{
		std::cout << "Creation des roches" <<std::endl;
   	n1 = rand();
  	n2 = rand();
  	Roche* roche = new Roche(n1%1280,n2%720);
		this->_objs.push_back(roche);
	}
	for(int i=0 ; i<z; i++)
	{
		std::cout << "Creation des baies" <<std::endl;
   	n1 = rand();
  	n2 = rand();
  	Baie* baie = new Baie(n1%1280,n2%720);
		this->_objs.push_back(baie);
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
		//std::cout <<"arbre " << _objs[0]->getPosition(0) << "  " << _objs[0]->getPosition(1) << std::endl;
		//std::cout <<"roche " << _objs[1]->getPosition(0) << "  " << _objs[1]->getPosition(1) << std::endl;
		//std::cout <<"arbres " << _persos[1]->getPosition(0) << "  " << _persos[1]->getPosition(1) << std::endl;

		//On cherche un élément proche et dans la bonne direction
		if(distanceToPerso(getCloserObject(p),p)<30)
    {
    		std::cout << "Interaction Possible" << std::endl;
		   	p.interagir(getCloserObject(p));
		  	return true;
		}
		else
			std::cout << "INTERACTION IMPOSSIBLE" << std::endl;
		return false;
	}
	else if(s == "Manger")
	{
		p.manger();
		std::cout << "Joueur a mangé" << std::endl;
		return true;
	}
	else if(s == "CreerHache")
	{
		std::cout << "Tentative pour créer une hache" << std::endl;
		if(p.creerHache())
		{
			std::cout << "Le joueur a : " << p.getNbOutils() << "Outils" << std::endl;
			return true;
		}
	}
	else if(s == "CreerPioche")
	{
		std::cout << "Tentative pour créer une pioche" << std::endl;
		if(p.creerPioche())
		{
			std::cout << "Le joueur a : " << p.getNbOutils() << "Outils" << std::endl;
			return true;
		}
	}
	else if(s == "AllumerFeu")
	{
		std::cout << "Tentative pour créer un feu" << std::endl;
		if(p.allumerFeu(getNbFeu()) == true){
		Feu* feu = new Feu(p.getPosition(0),p.getPosition(1));
			_feu.push_back(feu);}
			return true;
	}
	else if(s == "Dormir")
	{
		p.dormir();
		std::cout << "Joueur a dormi" << std::endl;
		return true;
	}
	else if(s == "ChangerOutil")
	{
		std::cout << "Le joueur veut changer d'outil" << std::endl;
		if(p.changerOut())
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

  		/*if(duration % (long)(this->_timer/4) == 0)
  			this->getPers(i).updateLife();*/
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
  			return 1; //Le joueur 1 a perdu
	}
  	//Si aucun des joueurs n'est mort on renvoie 0 pour dire de continuer
	return 0;
}

/*
* Fonction qui crée les l'affichage
*/
void Jeu::creerAffichage()
{
//Icones d'invocateurs
	sf::Texture* indicateurVie = new sf::Texture();
	sf::Sprite* perso1 = new sf::Sprite();
	sf::Sprite* perso2 = new sf::Sprite();
	indicateurVie->loadFromFile("../images/indicateurVie.png");
	perso1->setTexture(*indicateurVie);
	perso1->setTextureRect(sf::IntRect(0,0,129,134));
	perso2->setTexture(*indicateurVie);
	perso2->setTextureRect(sf::IntRect(213-134,0,134,129));
	perso2->setPosition(sf::Vector2f(1280-134,0));
//Affichage des Jauges de vie
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

//HORLOGE
sf::Texture* textHorloge = new sf::Texture();
sf::Sprite* sprHorloge = new sf::Sprite();
	textHorloge->loadFromFile("../images/horloge.png");
	sprHorloge->setTexture(*textHorloge);
	sprHorloge->setTextureRect(sf::IntRect(0,0,640/4,246/2));
	sprHorloge->setPosition(sf::Vector2f(1280/2-320/4,0));

_texture.push_back(textHorloge);
_texture.push_back(indicateurVie);
_texture.push_back(jauge);

	_affichage.push_back(perso1);
	_affichage.push_back(perso2);
	_affichage.push_back(jauge1);
	_affichage.push_back(jauge2);
	_affichage.push_back(jauge3);
	_affichage.push_back(jauge4);
	_affichage.push_back(jauge5);
	_affichage.push_back(jauge6);
	_affichage.push_back(sprHorloge);

}

void Jeu::horloge()
{
clockCurrent = clock();
double duration;
duration = (((float)clockCurrent/CLOCKS_PER_SEC) - ((float)clockStart/CLOCKS_PER_SEC));
int dureeJour = 30;
int dureeNuit = 5;
int duree =0;
if (duration <= dureeJour)
	{
		duree = (duration/dureeJour)*4;
		_stateDay = true;
		_affichage[8]->setTextureRect(sf::IntRect(640/4*duree,0,640/4,246/2));
	}
else{
	duree = ((duration-dureeJour)/dureeNuit)*4;
	_stateDay = false;
	_affichage[8]->setTextureRect(sf::IntRect((3*640/4)- (640/4*duree),246/2,640/4,246/2));
	}
if(duration > dureeJour+dureeNuit){
	_stateDay = true;
	clockStart = clock();
	_objs.clear();
	_feu.clear();
	getPers(0).setLife(2);
	getPers(1).setLife(2);
	creerEnv(rand()%10,rand()%7,rand()%3+1);
	}

}

double Jeu::distanceToPerso(ElemEnv* element, Personnage& perso)
{
	return sqrt(pow(element->getPosition(0)-perso.getPosition(0),2)+pow(element->getPosition(1)-perso.getPosition(1),2));
}

ElemEnv* Jeu::getCloserObject(Personnage& perso)
{
	ElemEnv* element = _objs[0];
	int j = 0;
	for(int i = 0; i<_objs.size();i++)
		{
			if(distanceToPerso(_objs[i],perso) < distanceToPerso(element,perso)){
				element = _objs[i];
				j=i;
			}
		}
		return element;
}

void Jeu::affichagePerso(sf::RenderWindow& window)
{
if(_feu.size()>0)
	{
		if(!_stateDay && distanceToPerso(_feu[0], *_persos[0])<200)
			_persos[0]->setLife(4);
			else if(!_stateDay)
			_persos[0]->setLife(0);
		if(_persos.size()>1)
		{
		if(!_stateDay && distanceToPerso(_feu[0], *_persos[1])<200)
			_persos[1]->setLife(4);
			else if(!_stateDay)
			_persos[1]->setLife(0);
		}
	}
else if(!_stateDay)
		{
			_persos[0]->setLife(0);
			_persos[1]->setLife(0);
				}

		for(int i = 0; i<_persos.size();i++)
	{
		window.draw(_persos[i]->getSprite());
	}
}

void Jeu::affichageElement(sf::RenderWindow& window)
{
	for(int i = 0; i<_objs.size();i++)
	{
		window.draw(_objs[i]->getSprite());
	}
}

void Jeu::affichageFeu(sf::RenderWindow& window)
{
	if(getNbFeu()>0 && _stateDay == true)
	{
			for(int i =0; i<getNbFeu();i++)
			{
				window.draw(getFeu(i).getSprite());
			}
		}
	else if(getNbFeu()>0 && _stateDay == false)
	{
			for(int i =0; i<getNbFeu();i++)
			{
				window.draw(getFeu(i).getSprite());
				window.draw(getFeu(i).getSpriteNuit());
			}
	}
	//if(getNbFeu()<0 && _stateDay == false)
else if(!_stateDay)
	{
		sf::RectangleShape* _rectangle = new sf::RectangleShape(sf::Vector2f(1280,720));
		_rectangle->setFillColor(sf::Color(0,0,0,200));
			window.draw(*_rectangle);
}
//	else
		return;
}

void Jeu::affichageStatique(sf::RenderWindow& window, int nbP)
{

	if(nbP ==2)
	{
		//Pour PERSONNAGE 2
		_affichage[5]->setTextureRect(sf::IntRect(0,215/5*(4-_persos[1]->getLife()),72,215/5));
		_affichage[6]->setTextureRect(sf::IntRect(0,215/5*(_persos[1]->getFatigue()),72,215/5));
		_affichage[7]->setTextureRect(sf::IntRect(0,215/5*(_persos[1]->getFaim()),72,215/5));
	}
	//pour le PERSONNAGE 1
	_affichage[2]->setTextureRect(sf::IntRect(0,215/5*(4-_persos[0]->getLife()),72,215/5));
	_affichage[3]->setTextureRect(sf::IntRect(0,215/5*(_persos[0]->getFatigue()),72,215/5));
	_affichage[4]->setTextureRect(sf::IntRect(0,215/5*(_persos[0]->getFaim()),72,215/5));


	for(int i =0; i<_affichage.size();i++)
	{
		window.draw(getAffichage(i));
	}
}

int main()
{
std::vector<ElemEnv> obj;
std::vector<Personnage> perso;
	int nbJ = 0;

	srand(time(NULL));
  RenderWindow window(VideoMode(1280,720),"ROB Starve Looser");
  Jeu* sim = new Jeu();
  Sprite currentSpr = sim->getSprAcc();

  clock_t clockStart;
  clock_t clockCurrent;
  double duration = 0;

  while(window.isOpen())
  {
    Event event;
    while(window.pollEvent(event))
    {
    	if (event.type == Event::Closed)
    		window.close();
   		else
   	  	{
   	  		switch (sim->getEtat())
   	  		{
   	  			case 0: //On est sur l'écran d'accueil
   	  				if(event.type == Event::MouseButtonPressed and sim->isClicAccueil(event.mouseButton.x, event.mouseButton.y) == -1)
   	  				{
								window.close(); //On a cliqué sur le bouton quitter
   	  				}
   	  				else if(event.type == Event::MouseButtonPressed and sim->isClicAccueil(event.mouseButton.x, event.mouseButton.y) == 1)
   	  				{
   	  					sim->setEtat(1); //On a cliqué sur le bouton play
								currentSpr = sim->getSprCmds();
   	  				}
   	  				break;
   	  			case 1:  //On est sur la page qui nous donne les commandes des joueurs
   	  				if(event.type == Event::MouseButtonPressed)
   	  				{
								nbJ = sim->isClicChoixJ(event.mouseButton.x, event.mouseButton.y);
								if(nbJ == -1)
								{
									std::cout << "Ce mode n'est pas implémenter, fermeture du jeu" <<std::endl;
									sim->setEtat(0);
									currentSpr = sim->getSprAcc();
								}
								else if(nbJ == 1 || nbJ == 2) //On est dans le cas où on a 1 ou deux joueurs
								{
									std::cout << "Creation de l'environnement" << std::endl;
									//on a choisi le mode joueur solo
									sim->creerJeu(nbJ);
									currentSpr = sim->getSprEnv();
									sim->setEtat(2);
									clockStart = clock();
								}
   	  				}
   	  				break;
   	  			case 2: //On a lancé le jeu donc on est dans la vraie simulation
							if(event.type == Event::KeyPressed)
   	  				{

								if( sim->tour(event.key.code, duration) != 0)
								{
									std::cout << "Le jeu est fini" << std::endl;
									sim->setEtat(3); //On met le jeu sur la page final où les joueurs ne peuvent que quitter
 									currentSpr = sim->getSprEnd();
 								}
   	  				}
							break;
   	  			case 3:
   	  				if(event.type == Event::MouseButtonPressed and sim->isClicEnd(event.mouseButton.x, event.mouseButton.y) == -1)
   	  				{
								window.close(); //On a cliqué sur le bouton quitter
   	  				}
							break;
   	  			default:
   	  				std::cout << "Mauvais état fourni" << std::endl;
   	  		}
      	}
    }

    window.clear();
    window.draw(currentSpr);

		if(sim->getEtat()==2)
		{
			sim->affichagePerso(window);
			sim->affichageElement(window);
			sim->affichageFeu(window);
			sim->affichageStatique(window, nbJ);
			sim->horloge();
		}
    window.display();
	}
  delete sim;
  return 0;
}
