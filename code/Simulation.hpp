/// ROB4-POO Projet Don't Starve
/// Fichier : Simulation.hpp
///	Autheurs : Benjamin Delbos et Tiphaine Diot
/// Classe Simulation

#ifndef SIM_HPP
#define SIM_HPP

#include <iostream>
#include <Environnement.hpp>
#include <map>

//typedef std::map<std::string, int> comdJ1;
// comdJ1["G"] = "K_LEFT";
// comdJ1["H"] = "K_UP";
// comdJ1["D"] = "K_RIGHT";
// comdJ1["B"] = "K_DOWN";
// comdJ1["agir"] = "K_1";
// comdJ1["chgOutil"] = "K_2";
// comdJ1["manger"] = "K_3";
// comdJ1["creerHache"] = "K_4";
// comdJ1["creerPioche"] = "K_5";
// comdJ1["allumerFeu"] = "K_6";
//typedef std::map<std::string, int> comdJ2;
// comdJ2["G"] = "K_d";
// comdJ2["H"] = "K_r";
// comdJ2["D"] = "K_g";
// comdJ2["B"] = "K_f";
// comdJ2["agir"] = "K_e";
// comdJ2["chgOutil"] = "K_s";
// comdJ2["manger"] = "K_z";
// comdJ2["creerHache"] = "K_x";
// comdJ2["creerPioche"] = "K_c";
// comdJ2["allumerFeu"] = "K_v";

class Simulation{

public:

	Simulation(){
		_etat = 0; //on met l'état à 0 cela correspond à la page d'accueil
		//On charge les images d'accueil
	}

	int getEtat(){return _etat;}
	void setEtat(int val){ _etat = val;}

	bool creerEnv(int nbJ, std::string s);
	int isClicAccueil(int x, int y);
	int isClicChoixJ(int x, int y);

protected:
	double _timer;
	Environnement _myEnv;
	int _day; 
	int _etat; 
	//ToDraw _accueil;
	//ToDraw _cmds;

};


int Simulation::isClicAccueil(int x, int y)
{
	return 0;
}
int Simulation::isClicChoixJ(int x, int y)
{
	return 0;
}


Environnement Simulation::creerEnv(int nbJ, std::string s){

	//Importation de l'environnement global

	for(int i = 0; i < nbJ; i++)
	{
		Personnage(i+1); //On lui passe son numero pour lui attribuer la bonne map pour ses commandes
	}

	//Creation des arbres, on en veut un nombre compris entre 1 et 10
	int nbrandom = rand()%9 +1; 
	for(int i=0; i < nbrandom; i++)
	{
		Arbre(); //donner une position random aussi
	}

	//Creation des roches de la même manière
	int nbrandom = rand()%9 +1; 
	for(int i=0; i < nbrandom; i++)
	{
		Roche(); //donner une position random aussi
	}

	//Dans la version 0 on ne crée pas de betes
	return this._myEnv;
}



#endif
