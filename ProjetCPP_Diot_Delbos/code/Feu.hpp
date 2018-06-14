/// ROB4-POO Projet Don't Starve
/// Fichier : Feu.hpp
///	Autheurs : Benjamin Delbos et Tiphaine Diot
/// Classe Feu

#ifndef FEU_HPP
#define FEU_HPP

#include <iostream>
#include "ElemEnv.hpp"

class Feu : public ElemEnv{

	public:

		Feu(int x, int y){
			std::cout <<"CREATION FEU" << std::endl;
			_vie = 4;
			if(!this->texture.loadFromFile("../images/Feu.png"))
					std::cout << "BAD MADAFAKA" << std::endl;
				this->sprite.setTexture(this->texture);
				this->sprite.setScale(sf::Vector2f(0.75,0.75));
				this->sprite.setPosition(sf::Vector2f(x+40,y+40));
				this->_position[0] = x;
				this->_position[1] = y;

				_circle = new sf::CircleShape(200);
				this->_circle->setOrigin(sf::Vector2f(100-x,100-y));
				this->_circle->setFillColor(sf::Color::Transparent);
				this->_circle->setOutlineThickness(1000);
					this->_circle->setOutlineColor(sf::Color(0,0,0,200));
				}

		std::string getType(){
			return "Feu";
		}

		void raviver()
		{
			_vie++; //On ravive le feu en lui ajoutant du bois
		}
		void raviver(int nbB)
		{
			_vie+=nbB; //On ravive le feu en lui ajoutant du bois
		}

		bool interagir(std::string s){
			 raviver();
			 return true;
		}
		int getRessource(){return 0;}
		bool coupDestructif()
		{
			return false; //Il n'y a jamais de coup destructif pour le feu, il ne donne jamais de ressources
		}

		sf::CircleShape& getSpriteNuit(){return *_circle;}

private:
		sf::CircleShape* _circle;

};

#endif
