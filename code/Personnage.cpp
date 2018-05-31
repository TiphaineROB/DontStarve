/// ROB4-POO Projet Don't Starve
/// Fichier : Personnage.cpp
///	Autheurs : Benjamin Delbos et Tiphaine Diot
/// Classe Personnage

#include <iostream>
#include "Personnage.hpp"

using namespace sf;

Personnage::Personnage()
{
  if(!texture.loadFromFile("../images/arbres.png"))
  {
    std::cout << "BAD MADAFAKA" << std::endl;
  }
  sprite.setTexture(texture);

	
	_sens = 'B';
	_faim = 0;
	_fatigue = 0;
	_vie = 5;
	_myPack = new Poche();
	_cmd = createCmd(1);
}



bool Personnage::bouger(std::string s, int sizeX, int sizeY)
{
	//Dans tous les cas il faut vérifier qu'on est bien rester dans l'image
	if(s.compare("Gauche"))
	{
		//On regarde si l'origine dépasse vers la gauche, donc inférieur à 0
		if(this->_origin[0]-this->_taillePas < 0) //Comme l'origine du sprite du personnage est en haut à gauche, les cas où il veut aller à g ou h ne posent pas de problèmes
				this->_origin[0] = 0;
			return true;
	}
	else if(s.compare("Droite")){
		if(this->_origin[0]+this->_size[0] > sizeX) //Dans ce cas il faut regarder que tout le sprite du personnage reste dans l'écran
				this->_origin[0] = sizeX - this->_size[0];
			return true;
	}
	else if(s.compare("Haut"))
	{
		if(this->_origin[1]-this->_taillePas < 0)
				this->_origin[1] = 0;
			return true;
	}
	else if(s.compare("Bas"))
	{
		if(this->_origin[1]+this->_size[1] > sizeX) //Dans ce cas il faut regarder que tout le sprite du personnage reste dans l'écran
				this->_origin[0] = sizeY - this->_size[1];
			return true;
	}
	return false; }



/*
* @function creerHache()
* @return bool : true si la hache a bien été créée
*/
bool Personnage::creerHache(){
	if(this->_myPack->getNbPierre() < 2 || this->_myPack->getNbBois() < 1) //Il faut 2 pierres et un bois pour faire une hache
		return false;
	_outils.push_back(Hache());
	return true;
}

/*
* @function allumerFeu()
* @return bool : true si le feu a été allumé
*/
bool Personnage::allumerFeu(){
	if(this->_myPack->getNbPierre() < 2 || this->_myPack->getNbBois() < 2) //Il faut 2 de chaque ressources
		return false;
	//On ajoute un drawable ??
	return true;
}

/*
* @function creerPioche()
* @return bool : true si la pioche a été créée
*/
bool Personnage::creerPioche(){
	if(this->_myPack->getNbPierre() < 1 || this->_myPack->getNbBois() < 1) //La pioche est l'outil le plus facile à faire
		return false;
	_outils.push_back(Pioche());
	return true;
}


int Personnage::updateLife()
{
	this->_faim++; 
	this->_fatigue++;
	this->_vie -=2;

	return this->_vie;
}

/*
* @function manger()
* @return int : Le niveau de faim du personnage
*/
int Personnage::manger()
{
	//Par défaut on mange des baies ça fait moins 1 à notre faim
	if(this->_myPack->getNbBaie() > 0)
		this->_faim--;
	return this->_faim;
}

/*
* @function dormir()
* @return int : ... ? 
*/
int Personnage::dormir(){
return 0;
}

/*
* @function reveil()
* @return int : Le niveau de fatigue du personnage
*/
int Personnage::reveil(){
return 0;
}

/*
* @function private createCmd(int i)
* @return : std::map<sf::Keyboard::Key, std::string>
* Permet de donner à joueur son ensemble de touche correspondant à des actions
*/
cmd_t Personnage::createCmd(int i){
	
	cmd_t cmd;
	if(i==1)
	{	
		cmd[sf::Keyboard::Left] = "Gauche" ;
		cmd[sf::Keyboard::Right] = "Droite";
		cmd[sf::Keyboard::Up] = "Haut";
		cmd[sf::Keyboard::Down] = "Bas";
		cmd[sf::Keyboard::Num1] =  "Interagir";
		cmd[sf::Keyboard::Num2] = "ChangerOutil";
		cmd[sf::Keyboard::Num3] = "Manger" ;
		cmd[sf::Keyboard::Num4] = "CreerHache"; 
		cmd[sf::Keyboard::Num5] = "CreerPioche";
		cmd[sf::Keyboard::Num6] = "AllumerFeu"; 
		cmd[sf::Keyboard::Num7] = "Dormir"; 
	}
	else if(i==2)
	{
		cmd[sf::Keyboard::D] = "Gauche";
		cmd[sf::Keyboard::G] = "Droite";
		cmd[sf::Keyboard::R] = "Haut";
		cmd[sf::Keyboard::F] = "Bas";
		cmd[sf::Keyboard::E] = "Interagir";
		cmd[sf::Keyboard::S] = "ChangerOutil";
		cmd[sf::Keyboard::Z] = "Manger";
		cmd[sf::Keyboard::X] = "CreerHache"; 
		cmd[sf::Keyboard::C] = "CreerPioche";
		cmd[sf::Keyboard::V] = "AllumerFeu"; 
		cmd[sf::Keyboard::W] = "Dormir"; 
	}
	return cmd;
}


/*
* @function couper(ElemEnv e)
* @return : bool
* Permet de dire si l'élément devant peut être couper
*/
bool Personnage::couper(ElemEnv e)
{
	if(e.getType() == "Arbre" && this->_outils[0].getType() == "Hache")
		return true;
	return false;
}

bool Personnage::casser(ElemEnv e)
{
	if(e.getType() == "Roche" && this->_outils[0].getType() == "Pioche")
		return true;
	return false;
}


/*
* @function interagir()
* @return bool: si le joueur a pu intéragir ? 
* On regarde dans la direction du joueur s'il y a un obstacle et si il a l'outil adéquate
*/
bool Personnage::interagir(ElemEnv e) //On lui passe l'élément devant lui, l'erreur d'agir s'il n'y a pas d'élément est regardé avant d'appeler la fonction
{
	if(this->couper(e))
	{
		if(e.coupDestructif())
			this->_myPack->addBois(3);
		return true;
	}
	else if(this->casser(e))
	{
		if(e.coupDestructif())
			this->_myPack->addPierre(3);
		return true; 
	}
	return false;
}


/*
* @function changerOutil()
* @return outil en main 
*/
Outil Personnage::changerOut(int i)
{
	Outil outil;
	return outil;
}
