/// ROB4-POO Projet Don't Starve
/// Fichier : Roche.hpp
///	Autheurs : Benjamin Delbos et Tiphaine Diot
/// Classe Roche


#ifndef ROC_HPP
#define ROC_HPP

#include <iostream>
#include <string>

class Roche : public ElemEnv
{

public:
	Roche(){
		this->_vie = 3; //Une roche est cassée au bout de 3 coups
		//On doit lui attribuer un sprite aussi
		if(!texture.loadFromFile("../images/rocheArbres.png"))
	  {
	    std::cout << "BAD MADAFAKA" << std::endl;
	  }
	  this->sprite.setTexture(texture);
	  this->sprite.setTextureRect(sf::IntRect(0,10,128/4,160/4));
	  //this->sprite.setPosition(sf::Vector2f(1280/2, 720/2));
		this->sprite.setScale(sf::Vector2f(1.5,1.5));

	}

	Roche(int x, int y){
			this->_vie = 3; //Une roche est cassée au bout de 3 coups
			//On doit lui attribuer un sprite aussi
			if(!texture.loadFromFile("../images/rocheArbres.png"))
			{
				std::cout << "BAD MADAFAKA" << std::endl;
			}
			this->sprite.setTexture(texture);
			this->sprite.setTextureRect(sf::IntRect(0,10,128/4,160/4));
			this->sprite.setScale(sf::Vector2f(1.5,1.5));
			this->sprite.setPosition(sf::Vector2f(x,y));
		}

		~Roche(){
			std::cout << "Destructeur Roche" << std::endl;
		}

	std::string getType(){
		return "Roche";
	}

	std::string getRessourceName(){return "Pierre";}
	int getRessource(){return 3;}

	bool interagir(std::string s){
		if(s.compare("Pioche"))
		{
			return true;
		}
		return false;
	}

};

#endif
