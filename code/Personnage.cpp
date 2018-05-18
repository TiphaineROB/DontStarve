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
	_nbComm = 0;
}
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

/*
* @function manger()
* @return int : Le niveau de faim du personnage
*/
int Personnage::manger()
{
	//Par défaut on mange des baies ça fait moins 1 à notre faim
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
	}
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
