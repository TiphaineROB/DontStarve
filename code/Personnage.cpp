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
}
/*
* @function creerHache()
* @return bool : true si la hache a bien été créée
*/
bool Personnage::creerHache()
{
	//Le personnage peut créer une pioche uniquement s'il a les ressources nécessaires
	return false;
}

/*
* @function allumerFeu()
* @return bool : true si le feu a été allumé
*/
bool Personnage::allumerFeu()
{
	//Le personnage peut créer une pioche uniquement s'il a les ressources nécessaires
	return false;
}

/*
* @function creerPioche()
* @return bool : true si la pioche a été créée
*/
bool Personnage::creerPioche(){

	//Le personnage peut créer une pioche uniquement s'il a les ressources nécessaires

	return false;
}

/*
* @function manger()
* @return int : Le niveau de faim du personnage
*/
int Personnage::manger()
{

	return 0;
}

/*
* @function dormir()
* @return int : ... ? 
*/
int Personnage::dormir(){

}

/*
* @function reveil()
* @return int : Le niveau de fatigue du personnage
*/
int Personnage::reveil(){

}

/*
* @function interagir()
* @return bool: si le joueur a pu intéragir ? 
* On regarde dans la direction du joueur s'il y a un obstacle et si il a l'outil adéquate
*/
bool Personnage::interagir()
{

}
>>>>>>> f2908df1d2e5153607c06e6479b75785a245eb6c
