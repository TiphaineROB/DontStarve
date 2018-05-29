
#include "Simulation.hpp"
#include <string>
#include "time.h"

using namespace sf;


int main()
{
	srand(time(NULL));
  RenderWindow window(VideoMode(1280,720),"ROB Starve Looser");
  Texture texture;
  Sprite sprite;
 	
  std::vector<ToDraw> Objets;
  ToDraw _perso;
  _perso.setTexture("../images/fond.jpg");
  _perso.setSize(100,100);
  _perso.setSprite();

  Objets.push_back(_perso);

  Simulation* sim = new Simulation();
  Sprite currentSpr = sim->getSprAcc(); 

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
   	  				if(event.type == Event::MouseButtonPressed and sim->isClicChoixJ(event.mouseButton.x, event.mouseButton.y) == -1)
   	  				{
						throw("Ce mode de jeu n'est pas implementé encore"); //On a cliqué sur le bouton contre l'IA
   	  				}	
   	  				else if(event.type == Event::MouseButtonPressed and sim->isClicChoixJ(event.mouseButton.x, event.mouseButton.y) == 1)
   	  				{
   	  					//on a choisi le mode joueur solo
   	  					//sim->creerEnv(1,"../images/fond.jpg");
   	  				}
   	  				else if(event.type == Event::MouseButtonPressed and sim->isClicChoixJ(event.mouseButton.x, event.mouseButton.y) == 2)
   	  				{
   	  					//on a choisi le mode 2 joueurs
   	  					//sim->creerEnv(2, "../images/fond.jpg");
   	  				}
   	  				break; 
   	  			case 2: //On a lancé le jeu donc on est dans la vraie simulation
   	  				if(event.type == Event::KeyPressed)
						sim->tour(event.key);
   	  			default: 
   	  				throw("Erreur dans l'obtention de l'état de la simulation");

   	  		}	
      	}
    }
    window.clear();
    window.draw(currentSpr);
    //if(sim->getEtat() == 2)
    //{
	  //Afficher un par un tout les drawables
    //}
    window.display();
  }
  return 0;
}



