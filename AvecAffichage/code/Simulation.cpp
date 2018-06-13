
//#include "Simulation.hpp"
#include <string>
#include "time.h"
#include "Jeu.hpp"

using namespace sf;

void Jeu::affichageStatique(sf::RenderWindow& window, int nbP)
{

	if(nbP ==2)
	{
		//Pour PERSONNAGE 2
		_affichage[5]->setTextureRect(sf::IntRect(0,215/5*(4-_persos[1]->getLife()),72,215/5));
		_affichage[6]->setTextureRect(sf::IntRect(0,215/5*(4-_persos[1]->getFatigue()),72,215/5));
		_affichage[7]->setTextureRect(sf::IntRect(0,215/5*(4-_persos[1]->getFaim()),72,215/5));
	}
	//pour le PERSONNAGE 1
	_affichage[2]->setTextureRect(sf::IntRect(0,215/5*(4-_persos[0]->getLife()),72,215/5));
	_affichage[3]->setTextureRect(sf::IntRect(0,215/5*(4-_persos[0]->getFatigue()),72,215/5));
	_affichage[4]->setTextureRect(sf::IntRect(0,215/5*(4-_persos[0]->getFaim()),72,215/5));


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
	RenderWindow& fen = window;
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
							clockCurrent = clock();
							duration = (long)(clockCurrent - clockStart) / ((long)CLOCKS_PER_SEC);
							//Cette partie est à mettre dans une nouvelle fonction elle sert à faire en sorte que le jour se transforme en nuit et inversement
							if(int(duration) % int(sim->getTimer()) == 0) //12 min se sont écoulées donc on change l'état de la journée et éventuellement le numéro du jour
							{
								sim->changeStateDay();
							}
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
		sf::Texture indicateurVie;
		sf::Sprite perso1;
		sf::Sprite perso2;
		indicateurVie.loadFromFile("../images/indicateurVie.png");
		
		perso1.setTexture(indicateurVie);
		perso2.setTexture(indicateurVie);
		sf::Texture jauge;
		sf::Sprite jauge1;
		sf::Sprite jauge2;
		jauge1.setTexture(jauge);
		jauge2.setTexture(jauge);
		perso2.setPosition(sf::Vector2f(1280-100,0));

    window.clear();
    window.draw(currentSpr);

		if(sim->getEtat()==2)
		{
			for(int i = 0; i <sim->getNbObjs(); i++){
					window.draw(sim->getObj(i).getSprite());
					//window.draw(obj[i].getSprite());
				}
			for(int i = 0; i < sim->getNbPers(); i++){
				window.draw(sim->getPers(i).getSprite());
			}
			sim->affichageStatique(window, nbJ);
			double distance;
		//	distance = sim->distanceToPerso(sim->getCloserObject(sim->getPers(0)),sim->getPers(0));
				//sim->getCloserObject(sim->getPers(0))->getSprite().setColor(sf::Color::Red);
			//std::cout << distance << std::endl;
		}
		//else
		 //	std::cout << "Personnage n'existe pas encore" << std::endl;
    window.display();
	}
  delete sim;
  return 0;
}
