/// ROB4-POO Projet Don't Starve
/// Fichier : TestElemEnv.cpp
///	Autheurs : Benjamin Delbos et Tiphaine Diot


/*
* Fichier servant à tester les fonctions de la classe ElemEnv et de ses classes héritières
*
*/
#include <iostream>
#include "Outil.hpp"
#include "Pioche.hpp"
#include "Hache.hpp"
#include "Roche.hpp"
#include "Arbre.hpp"

int main()
{

  std::vector<Outil> outils;

  Hache h1();
  Pioche p1();

  //Test sur l'ajout des éléments dérivés de Outil dans un vecteur de type Outil
  try
  {

    outils.push_back(h1);
    outils.push_back(p1);
    if(outils.size() != 2)
      throw("Erreur dans l'ajout des outils dans le vecteur");
  }
  catch(...)
  {
     std::cerr << "Erreur dans l'ajout des éléments dérivés de Outil dans le vecteur" << std::endl;
     return -1;

  }
  //On vérifie si les types des éléments dérivés sont bien les bons
  try
  {

    if(h1.getType().compare("Hache") != 0)
      throw("Erreur dans la comparaison du type Hache");
    if(p1.getType().compare("Pioche") != 0)
      throw("Erreur dans la comparaison du type Pioche");

  }
  catch(...)
  {
     std::cerr << "Erreur dans la récupération des types directement à partir des classes" << std::endl;
     return -1;

  }

  try
  {
    if(outils[0].getType().compare("Hache") != 0)
      throw("Erreur dans la comparaison du type Hache dans le vecteur");
    if(outils[1].getType().compare("Pioche") != 0)
      throw("Erreur dans la comparaison du type Pioche dans le vecteur");
  }
  catch(...)
  {
     std::cerr << "Erreur dans la récupération des types à partir des éléments du vecteur" << std::endl;
     return -1;
  }

  //On teste la fonction utiliser()
  try
  {
    outils[0].utiliser(); //La fonction utiliser de pioche est identique
    if(outils.size() != 2)
      throw("Erreur dans la fonction utiliser de Hache issu de vecteur");
    outils[0].setVie(1);
    outils[0].utiliser();
    if(outils.size() != 1)
      throw("Erreur dans la fonction utiliser de Hache issu de vecteur")


  }
  catch(...)
  {
    std::cerr << "Erreur dans le test de la fonction utiliser à partir du vecteur" << std::endl;
    return -1;
  }


  return 0;
}
