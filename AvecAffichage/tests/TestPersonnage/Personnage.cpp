/// ROB4-POO Projet Don't Starve
/// Fichier : Personnage.cpp
///	Autheurs : Benjamin Delbos et Tiphaine Diot
/// Classe Personnage

#include <iostream>
#include "Personnage.hpp"

using namespace sf;

Personnage::Personnage()
{
  if(!this->texture.loadFromFile("../images/perso.png"))
  {
    std::cout << "BAD MADAFAKA" << std::endl;
  }
  this->sprite.setTexture(this->texture);
  this->sprite.setTextureRect(sf::IntRect(0,2*256/4,576/9,256/4));
  this->sprite.setPosition(sf::Vector2f(1280/2, 720/2));


	_sens = 'B';
	_faim = 0;
	_fatigue = 0;
	_vie = 5;
	_cmd = createCmd(1);
}

/*
* Fonction qui change la position du personnage en fonction de la touche appuyée
*
*/

bool Personnage::bouger(std::string s, int sizeX, int sizeY)
{
	//Dans tous les cas il faut vérifier qu'on est bien rester dans l'image
	if(s == "Gauche")
	{
    std::cout << " LEFT "<< std::endl;
		//On regarde si l'origine dépasse vers la gauche, donc inférieur à 0
		//if(this->_origin[0]-this->_taillePas < 0) //Comme l'origine du sprite du personnage est en haut à gauche, les cas où il veut aller à g ou h ne posent pas de problèmes
		//{
      this->_origin[0] = 0;
      this->_sens = "G";
      this->sprite.setTextureRect(sf::IntRect(0,256/4,576/9,256/4));
      this->_position[0] = this->_position[0]-10;
      this->sprite.setPosition(Vector2f(this->_position[0],this->_position[1]));
  //  }
    return true;
	}
	 if(s == "Droite"){
		//if(this->_origin[0]+this->_size[0] > sizeX) //Dans ce cas il faut regarder que tout le sprite du personnage reste dans l'écran
			//{
      std::cout << " RIGHT "<< std::endl;
        	this->_origin[0] = sizeX - this->_size[0];
          this->_sens = "D";
          this->_position[0] = this->_position[0]+10;
          this->sprite.setTextureRect(sf::IntRect(0,3*256/4,576/9,256/4));
      //    }
      this->sprite.setPosition(Vector2f(this->_position[0],this->_position[1]));
      return true;
	}
	else if(s == "Haut")
	{
	//	if(this->_origin[1]-this->_taillePas < 0){
std::cout << " UP "<< std::endl;
				this->_origin[1] = 0;
			//return true;
      this->sprite.setTextureRect(sf::IntRect(0,0,576/9,256/4));
      this->_position[1] = this->_position[1] - 10;
      this->sprite.setPosition(Vector2f(this->_position[0],this->_position[1]));
//      std::cout << "POSITION PERSONNAGE " << _position[0]<< " " << getPosition(0) << std::endl;

      std::cout << "POSITION PERSONNAGE " << getPosition(0)<< " " << getPosition(1) << std::endl;
    //}
    return true;
	}
	else if(s == "Bas")
	{
    std::cout << " DOWN "<< std::endl;
		//if(this->_origin[1]+this->_size[1] > sizeX){ //Dans ce cas il faut regarder que tout le sprite du personnage reste dans l'écran
				this->_origin[0] = sizeY - this->_size[1];
        this->sprite.setTextureRect(sf::IntRect(0,2*256/4,576/9,256/4));
        this->_position[1] = this->_position[1]+10;
        this->sprite.setPosition(Vector2f(this->_position[0],this->_position[1]));
      //}
			return true;
	}
	return false;
}

/*
bool Personnage::bouger(std::string s, int sizeX, int sizeY)
{
	//Dans tous les cas il faut vérifier qu'on est bien rester dans l'image
	if(s.compare("Gauche"))
	{
		//On regarde si l'origine dépasse vers la gauche, donc inférieur à 0
		if(this->_origin[0]-this->_taillePas < 0) //Comme l'origine du sprite du personnage est en haut à gauche, les cas où il veut aller à g ou h ne posent pas de problèmes
		{
      this->_origin[0] = 0;
      this->_sens = "G";
      this->sprite.setTextureRect(sf::IntRect(0,256/4,576/9,256/4));
      this->_position[1] -= this->_position[1];
      this->sprite.setPosition(Vector2f(this->_position[0],this->_position[1]));
    }
    return true;
	}
	else if(s.compare("Droite")){
		if(this->_origin[0]+this->_size[0] > sizeX) //Dans ce cas il faut regarder que tout le sprite du personnage reste dans l'écran
			{
        	this->_origin[0] = sizeX - this->_size[0];
          this->_sens = "D";
          this->sprite.setTextureRect(sf::IntRect(0,3*256/4,576/9,256/4));
          this->_position[1] += this->_position[1];
          this->sprite.setPosition(Vector2f(this->_position[0],this->_position[1]));
          }
      return true;
	}
	else if(s.compare("Haut"))
	{
		if(this->_origin[1]-this->_taillePas < 0)
				this->_origin[1] = 0;
			return true;
      this->sprite.setTextureRect(sf::IntRect(0,0,576/9,256/4));
      this->_position[0] -= this->_position[0];
      this->sprite.setPosition(Vector2f(this->_position[0],this->_position[1]));
	}
	else if(s.compare("Bas"))
	{
		if(this->_origin[1]+this->_size[1] > sizeX) //Dans ce cas il faut regarder que tout le sprite du personnage reste dans l'écran
				this->_origin[0] = sizeY - this->_size[1];
        this->sprite.setTextureRect(sf::IntRect(0,2*256/4,576/9,256/4));
        this->_position[0] += this->_position[0];
        this->sprite.setPosition(Vector2f(this->_position[0],this->_position[1]));
			return true;
	}
	return false; }
*/


/*
* @function creerHache()
* @return bool : true si la hache a bien été créée
*/
bool Personnage::creerHache(){
	if(this->_pack.find("Pierre")->second < 2 || this->_pack.find("Bois")->second < 1) //Il faut 2 pierres et un bois pour faire une hache
		return false;
	_outils.push_back(new Hache());
  this->_pack["Pierre"] -= 2;
  this->_pack["Bois"] -= 1;
	return true;
}

/*
* @function allumerFeu()
* @return bool : true si le feu a été allumé
*/
bool Personnage::allumerFeu(){
	if(this->_pack.find("Pierre")->second < 2 || this->_pack.find("Bois")->second < 2) //Il faut 2 de chaque ressources
		return false;
  this->_pack["Pierre"] -= 2;
  this->_pack["Bois"] -= 2;
	return true;
}

/*
* @function creerPioche()
* @return bool : true si la pioche a été créée
*/
bool Personnage::creerPioche(){
	if(this->_pack.find("Pierre")->second < 1 || this->_pack.find("Bois")->second < 1) //La pioche est l'outil le plus facile à faire
		return false;
	_outils.push_back(new Pioche());
  this->_pack["Pierre"] -= 1;
  this->_pack["Bois"] -= 1;
	return true;
}

/*
* @function updateLife()
* @return int : la valeur de la vie du personnage
*/
int Personnage::updateLife()
{
	//TODO rajouter des conditions pour que juste après manger la vie ne baisse pas !! (chrono en interne du personnage ?)
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
	if(this->_pack.find("Baie")->second > 0)
  {
		if(this->_faim != 0)
    {
    this->_faim--;
    this->_pack["Baie"]-=1;
    }
  }
  return this->_faim;
}

/*
* @function dormir()
* @return int : ... ?
*/
int Personnage::dormir(){
  this->_fatigue--;
  return this->_fatigue;
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
* @function interagir()
* @return bool: si le joueur a pu intéragir ?
* On regarde dans la direction du joueur s'il y a un obstacle et si il a l'outil adéquate
*/
bool Personnage::interagir(ElemEnv e) //On lui passe l'élément devant lui, l'erreur d'agir s'il n'y a pas d'élément est regardé avant d'appeler la fonction
{
    //Erreur ici on appelle la fonction de ElemEnv au lieu de celle non virtuelle du type envoyé en paramètre
    if(e.interagir(this->_outils[0]->getType()))
    {
           if(e.coupDestructif())
              this->_pack.find(e.getRessourceName())->second += e.getRessource();
          if(e.getType().compare("Arbre") || e.getType().compare("Roche"))
                this->_outils[0]->utiliser();
            return true;
    }

	return false;
}


/*
* @function changerOutil()
* @return outil en main
*/
Outil* Personnage::changerOut()
{
	//On met le premier à la fin et le deuxième au début
	if(this->_outils.size() > 1) //Le personnage a au moins deux outils
	{	Outil *temp = this->_outils[0];
		this->_outils.erase (this->_outils.begin()); //On supprime le premier élement puis on le met à la fin
		this->addOut(temp);
		return this->_outils[0];
	}
	else
		return this->_outils[0];
}
