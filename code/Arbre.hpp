/// ROB4-POO Projet Don't Starve
/// Fichier : Arbre.hpp
///	Autheurs : Benjamin Delbos et Tiphaine Diot
/// Classe Arbre


#ifndef ARB_HPP
#define ARB_HPP

#include <iostream>
#include <string>

class Arbre : public ElemEnv
{

	public:
		Arbre(){
			this->_vie = 3;
			//On lui attribue son sprite aussi
		}
		std::string getType(){
			return "Arbre";
		}

		std::string getRessourceName(){return "Bois";}


		bool interagir(std::string s){
			if(s.compare("Hache"))
			{
				return true;
			}
			return false;
		}

};

#endif
