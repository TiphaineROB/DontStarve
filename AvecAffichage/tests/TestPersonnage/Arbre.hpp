/// ROB4-POO Projet Don't Starve
/// Fichier : Arbre.hpp
///	Autheurs : Benjamin Delbos et Tiphaine Diot
/// Classe Arbre


#ifndef ARB_HPP
#define ARB_HPP

#include <iostream>
#include "ElemEnv.hpp"
#include <string>

class Arbre : public ElemEnv
{

	public:
		Arbre(){
			this->_vie = 3;
			this->texture.loadFromFile("../images/arbres.png");
			this->sprite.setTexture(this->texture);
			this->sprite.setTextureRect(sf::IntRect(0,0,512/4,512/4));
			this->sprite.setScale(sf::Vector2f(0.5,0.5));
			//On lui attribue son sprite aussi
		}

		Arbre(int x, int y){
			this->_vie = 3;
			this->texture.loadFromFile("../images/arbres.png");
			this->sprite.setTexture(this->texture);
			this->sprite.setTextureRect(sf::IntRect(0,0,512/4,512/4));
			this->sprite.setScale(sf::Vector2f(0.5,0.5));
			this->sprite.setPosition(sf::Vector2f(x, y));
		}


		~Arbre(){
				std::cout << "Destructeur Arbre" << std::endl;
		}

		std::string getType(){
			return "Arbre";
		}

		std::string getRessourceName(){return "Bois";}
		int getRessource(){return 3;}

		bool interagir(std::string s){
			if(s == "Hache")
			{
				return true;
			}
			return false;
		}

};

#endif
