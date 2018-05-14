#include <SFML/Graphics.hpp>
#include "Simulation.hpp"
#include <string>
#include "time.h"

using namespace sf;


int main()
{
	srand(time(NULL));
  RenderWindow window(VideoMode(200,200),"ROB Starving");
  Texture texture;
  Sprite sprite;
  sprite perso

  Simulation sim = new Simulation();

  if(!texture.loadFromFile("../images/fond.jpg"))
  {
    std::cout << "BAD MADAFAKA" << std::endl;
  }
  sprite.setTexture(texture);
  while(window.isOpen())
  {
    Event event;
    while(window.pollEvent(event))
    {
    	if (event.type == Event::Closed)
    		window.close();
   		else
   	  	{
   	  		switch (sim.getEtat())
   	  		{
   	  			case 0: //On est sur l'écran d'accueil
   	  				if(event.type == Event::MouseButtonPressed and isClicAccueil(event.pos[0], event.pos[1]) == -1)
   	  				{
						window.close(); //On a cliqué sur le bouton quitter
   	  				}	
   	  				else if(event.type == Event::MouseButtonPressed and isClicAccueil(event.pos[0], event.pos[1]) == 1)
   	  				{
   	  					sim.setEtat(1); //On a cliqué sur le bouton play
   	  				}
   	  				break; 
   	  			case 1:  //On est sur la page qui nous donne les commandes des joueurs
   	  				if(event.type == Event::MouseButtonPressed and isClicChoixJ(event.pos[0], event.pos[1]) == -1)
   	  				{
						throw("Ce mode de jeu n'est pas implementé encore"); //On a cliqué sur le bouton contre l'IA
   	  				}	
   	  				else if(event.type == Event::MouseButtonPressed and isClicChoixJ(event.pos[0], event.pos[1]) == 1)
   	  				{
   	  					//on a choisi le mode joueur solo
   	  					//sim.creerEnv(1,"../images/fond.jpg");
   	  				}
   	  				else if(event.type == Event::MouseButtonPressed and isClicChoixJ(event.pos[0], event.pos[1]) == 2)
   	  				{
   	  					//on a choisi le mode 2 joueurs
   	  					//sim.creerEnv(2, "../images/fond.jpg");
   	  				}
   	  				break; 
   	  			case 2: //On a lancé le jeu donc on est dans la vraie simulation
   	  				break;
   	  			default: 
   	  				throw("Erreur dans l'obtention de l'état de la simulation");

   	  		}	
      	}
    }
    window.clear();
    window.draw(sprite);
    window.display();
  }
  return 0;
}



