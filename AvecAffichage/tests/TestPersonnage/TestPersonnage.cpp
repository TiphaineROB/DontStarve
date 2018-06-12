/// ROB4-POO Projet Don't Starve
/// Fichier : TestPersonnage.cpp
///	Autheurs : Benjamin Delbos et Tiphaine Diot


/*
* Fichier servant à tester les fonctions de la classe Personnage
*
*/
#include <iostream>
#include "Personnage.hpp"
#include "Arbre.hpp"
#include "Roche.hpp"

int main()
{

  //Nous allons tester les fonctions
  /*

    //cmd_t createCmd(int i);

  bool interagir(ElemEnv env);
  */

  Personnage *pers = new Personnage(1);

  Hache *h1 = new Hache();
  Pioche *p1 = new Pioche();

  //Test sur la bonne mise en place des commandes
  try
  {

    //On ne les testes pas toutes mais quelques unes
    if(pers->getCmd()[sf::Keyboard::Left] != "Gauche" || pers->getCmd()[sf::Keyboard::Num1] != "Interagir" || pers->getCmd()[sf::Keyboard::Num7] != "Dormir")
      throw("Erreur dans la création des commandes pour le joueur");

    std::cout << "Test initial réussi" << std::endl;


  }
  catch(...)
  {
     std::cerr << "Erreur dans la création des commandes pour le joueur" << std::endl;
     return -1;

  }

  //Test sur l'ajout d'outils dans le vecteur du personnage + teste de changement d'outils
  try
  {

    pers->addOut(h1);
    pers->addOut(p1);
    if(pers->getNbOutils() != 2)
      throw("Erreur dans l'ajout des outils dans le vecteur");

    std::cout << "1er test réussi" << std::endl;

    pers->changerOut();
    if(pers->getNbOutils() != 2)
      throw("Erreur dans le changement d'outils dans le vecteur");

    std::cout << "2eme test réussi" << std::endl;


    if(pers->getOut()->getType() != "Pioche")
      throw("Erreur dans le changement d'outils dans le vecteur");


  }
  catch(...)
  {
     std::cerr << "Erreur dans l'ajout/changement des éléments dérivés de Outil dans le vecteur" << std::endl;
     return -1;

  }

  //Test sur les fonctions de création des outils, on fait le test avec la hache, identique à celui avec une pioche
  try
  {
    //Les ressources ne sont pas suffisantes
     if(pers->creerHache())
      throw("Erreur dans la création d'une hache");

    std::cout << "3eme test réussi" << std::endl;

    pers->setRessourceBois(5);
    pers->setRessourcePierre(5);
    if(pers->getRessourceBois() != 5 || pers->getRessourcePierre() != 5)
      throw("Erreur dans l'ajout de ressources dans la hashMap");

      std::cout << "4eme test réussi" << std::endl;


    bool succeed = pers->creerHache();
    if(!succeed || pers->getRessourceBois() != 4 || pers->getRessourcePierre() != 3 || pers->getNbOutils()!=3)
      throw("Erreur dans la création de la hache");

      std::cout << "5eme test réussi" << std::endl;


  }
  catch(...)
  {
     std::cerr << "Erreur dans la création des outils dans le vecteur à partir des ressources du joueur" << std::endl;
     return -1;

  }

  try
  {
      pers->setRessourceBaie(2);
      //On teste updateLife()
      int oldFaim = pers->getFaim();
      pers->updateLife();
      int faim = pers->getFaim();

      if(faim-1!=oldFaim)
        throw("Erreur dans l'updateLife pour la faim");

      std::cout << "6eme test réussi" << std::endl;

      int newFaim = pers->manger();
      if(newFaim+1 != faim)
        throw("Erreur dans la fonction manger");
      std::cout << "7eme test réussi" << std::endl;

  }
  catch(...)
  {
     std::cerr << "Erreur dans la fonction manger" << std::endl;
     return -1;

  }

  //On teste la fonction interagir
  try
  {
      Arbre *a = new Arbre();
      Roche *r = new Roche();
      std::cout << pers->getOut()->getType() << std::endl;

      if(pers->interagir(*a))
        throw("Erreur,  le joueur peut interagir avec le mauvais outil");

      std::cout << "8eme test réussi" << std::endl;


      if(!pers->interagir(*r))
        throw("Erreur dans la correspondance outil/elem");

      //Coup destructif a déjà été testé dans le test ElemEnv donc les tests sur la fonction s'arrête là
      std::cout << "9eme test réussi" << std::endl;

  }
  catch(...)
  {
     std::cerr << "Erreur dans la fonction interagir" << std::endl;
     return -1;

  }


  //On ne teste pas les accesseurs ou setters comme dormir par exemple



  free(h1);
  free(p1);
  free(pers);
  std::cout << "Pas d'erreurs dans la classe Personnage" << std::endl;

  return 0;
}
