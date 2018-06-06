
#include "Simulation.hpp"
#include <string>
#include "time.h"

using namespace sf;


int main()
{
	srand(time(NULL));
  RenderWindow window(VideoMode(1280,720),"ROB Starve Looser");
  // Texture texture;
  // Sprite sprite;
 //
  // std::vector<ToDraw> Objets;
   Personnage *_perso = new Personnage(0);
	 Arbre arbre;
	// Arbre *_perso = new Arbre(10,300);
	 Roche *_roche = new Roche(300,300);
  // _perso->setTexture("../images/fond.jpg");
  // _perso->setSize(100,100);
  // _perso->setSprite();
	//
  // Objets.push_back(_perso);

  Simulation* sim = new Simulation();
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
   	  				if(event.type == Event::MouseButtonPressed and sim->isClicChoixJ(event.mouseButton.x, event.mouseButton.y) == -1)
   	  				{
								throw("Ce mode de jeu n'est pas implementé encore"); //On a cliqué sur le bouton contre l'IA
   	  				}
   	  				else if(event.type == Event::MouseButtonPressed and sim->isClicChoixJ(event.mouseButton.x, event.mouseButton.y) == 1)
   	  				{
   	  					//on a choisi le mode joueur solo
   	  					sim->creerEnv(1,"../images/carte.png");
								currentSpr = sim->getEnv()->getSprite();

										std::cout << "Constructeur TEST" << std::endl;
								sim->setEtat(2);
								//currentSpr = sim->getSprAcc();
   	  				}
   	  				else if(event.type == Event::MouseButtonPressed and sim->isClicChoixJ(event.mouseButton.x, event.mouseButton.y) == 2)
   	  				{
   	  					//on a choisi le mode 2 joueurs
   	  					sim->creerEnv(2, "../images/carte.png");
								std::cout << "Constructeur TEST" << std::endl;
								currentSpr = sim->getEnv()->getSprite();
								sim->setEtat(2);
   	  				}
   	  				clockStart = clock();
   	  				break;
   	  			case 2: //On a lancé le jeu donc on est dans la vraie simulation
   	  				if(event.type == Event::KeyPressed)
   	  				{
   	  					clockCurrent = clock();
   	  					duration = (long)(clockCurrent - clockStart) / ((long)CLOCKS_PER_SEC);
						if( sim->tour(event.key.code, duration) != 0)
						{
							std::cout << "Le jeu est fini" << std::endl;
							sim->setEtat(3); //On met le jeu sur la page final où les joueurs ne peuvent que quitter
 							currentSpr = sim->getSprEnd();
 						}
   	  				}
   	  			case 3:
   	  				if(event.type == Event::MouseButtonPressed and sim->isClicEnd(event.mouseButton.x, event.mouseButton.y) == -1)
   	  				{
								window.close(); //On a cliqué sur le bouton quitter
   	  				}
							break;
   	  			default:
   	  				throw("Erreur dans l'obtention de l'état de la simulation"); //Gérer cette erreur
   	  		}
      	}
    }
    window.clear();
    window.draw(currentSpr);
		if(sim->getEtat()==2){
			window.draw(sim->getEnv()->getPers(0).getSprite());
			std::cout << "On devrait afficher un personnage" << std::endl;
		}
		//else
		 //	std::cout << "Personnage n'existe pas encore" << std::endl;
		//if(sim->getEtat() == 2)
    //{
    //	for(sim->)
    //}
    window.display();
  }
  delete sim;
  return 0;
}
