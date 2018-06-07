/// ROB4-POO Projet Don't Starve
/// Fichier : AI.hpp
///	Autheurs : Benjamin Delbos et Tiphaine Diot
/// Classe AI

#ifndef AI_HPP
#define AI_HPP

#include <iostream>
#include "Personnage.hpp"
#include <string>

class AI : public Personnage
{

	public:
		AI(): Personnage(1){} //Il possède les mêmes commandes que le joueur 1 donc il va imiter toutes ces actions (mais pas le sens)

		bool bouger(std::string s, int sizeX, int sizeY)
		{
			int randomMove = rand()%4 +1;
			if(randomMove == 1) //On va bouger vers la gauche
			{
				//On regarde si l'origine dépasse vers la gauche, donc inférieur à 0
				if(this->_origin[0]-this->_taillePas < 0) //Comme l'origine du sprite du personnage est en haut à gauche, les cas où il veut aller à g ou h ne posent pas de problèmes
				{
		      this->_origin[0] = 0;
		      this->_sens = "G";
		      this->sprite.setTextureRect(sf::IntRect(0,256/4,576/9,256/4));
		      this->_position[1] -= this->_position[1];
		      this->sprite.setPosition(sf::Vector2f(this->_position[0],this->_position[1]));
		    }
		    return true;
			}
			else if(randomMove == 2) //On bouge vers la droite
			{
				if(this->_origin[0]+this->_size[0] > sizeX) //Dans ce cas il faut regarder que tout le sprite du personnage reste dans l'écran
					{
		        	this->_origin[0] = sizeX - this->_size[0];
		          this->_sens = "D";
		          this->sprite.setTextureRect(sf::IntRect(0,3*256/4,576/9,256/4));
		          this->_position[1] += this->_position[1];
		          this->sprite.setPosition(sf::Vector2f(this->_position[0],this->_position[1]));
		          }
		      return true;
			}
			else if(randomMove == 3) //On va vers le haut
			{
				if(this->_origin[1]-this->_taillePas < 0)
						this->_origin[1] = 0;
					return true;
		      this->sprite.setTextureRect(sf::IntRect(0,0,576/9,256/4));
		      this->_position[0] -= this->_position[0];
		      this->sprite.setPosition(sf::Vector2f(this->_position[0],this->_position[1]));
			}
			else if(randomMove == 4) //On va vers le bas
			{
				if(this->_origin[1]+this->_size[1] > sizeX) //Dans ce cas il faut regarder que tout le sprite du personnage reste dans l'écran
						this->_origin[0] = sizeY - this->_size[1];
		        this->sprite.setTextureRect(sf::IntRect(0,2*256/4,576/9,256/4));
		        this->_position[0] += this->_position[0];
		        this->sprite.setPosition(sf::Vector2f(this->_position[0],this->_position[1]));
					return true;
			}
			return false;
		}


};

#endif
