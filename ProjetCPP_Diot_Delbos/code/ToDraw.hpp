/// ROB4-POO Projet Don't Starve
/// Fichier : Drawable.hpp
///	Autheurs : Benjamin Delbos et Tiphaine Diot
/// Classe Drawable

#ifndef DRAW_HPP
#define DRAW_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class ToDraw
{
public:
	std::string getType(){
		return "Ceci est un objet";
	}
	//Constructeur :
	ToDraw()
	{ //valeur par défault jsute pour tester 2-3 trucs, ne sert strictement à rien
		_origin[0] = 0;
		_origin[0] = 0;
		_size[0] = 40;
		_size[1] = 40;
		_state = 1;
		//if(!texture.loadFromFile("../images/Roches.png", sf::IntRect(_origin[0],_origin[1],_size[0],_size[1])))
		//if(!texture.loadFromFile("../images/Roches.png", sf::IntRect(0,0,50,50)))
		if(!texture.loadFromFile("../images/Roches.png"))
		{
			std::cout << "BAD MADAFAKA" << std::endl;
		}
		sprite.setTexture(texture);
	}
	//Getters :
	~ToDraw()
	{
	}
	sf::Sprite& getSprite()
	{
		return sprite;
	}
	//Setters :
	void setTexture(std::string textName)
	{
			if(!this->texture.loadFromFile(textName))
			{
				std::cout << "BAD MADAFAKA" << std::endl;
			}
	}
	void setState(int state)
	{
		this->_state = state;
	}
	void setSize(int size1, int size2)
	{
		this->_size[0]=size1;
		this->_size[1]=size1;
	}
	void setSprite()
	{
		this->sprite.setTextureRect(sf::IntRect(_origin[0],_state*_origin[1],_size[0],_size[1]));
	}

	void setPosition(int x, int y)
{
	_position[0]=x;
	_position[1]=y;
}

	int getSizeX(){return _size[0];}
	int getSizeY(){return _size[1];}
	int getPosition(int i){return _position[i];}
protected:
	double _vie;
	int _state;
	int _pos[2];
	int _origin[2];
	int _size[2];
	int _position[2];
	bool _interaction;
	sf::Sprite sprite;
	sf::Texture texture;
};

#endif
