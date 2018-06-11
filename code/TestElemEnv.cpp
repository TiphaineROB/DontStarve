/// ROB4-POO Projet Don't Starve
/// Fichier : TestElemEnv.cpp
///	Autheurs : Benjamin Delbos et Tiphaine Diot


/*
* Fichier servant à tester les fonctions de la classe ElemEnv et de ses classes héritières
*
*/
#include <iostream>
#include "ElemEnv.hpp"
#include "Baie.hpp"
#include "Feu.hpp"
#include "Roche.hpp"
#include "Arbre.hpp"

int main()
{

  std::vector<ElemEn> elems;

  Arbre a1();
  Roche r1();
  Feu f1();
  Baie b1();

  //Test sur l'ajout des éléments dérivés de ElemEnv dans un vecteur de type ElemEnv
  try
  {

    elems.push_back(a1);
    elems.push_back(r1);
    elems.push_back(f1);
    elems.push_back(b1);
  }
  catch(...)
  {
     std::cerr << "Erreur dans l'ajout des éléments dérivés de ElemEnv dans le vecteur" << std::endl;
     return -1;

  }
  //On vérifie si les types des éléments dérivés sont bien les bons
  try
  {

    if(a1.getType().compare("Arbre") != 0)
      throw("Erreur dans la comparaison du type Arbre");
    if(r1.getType().compare("Roche") != 0)
      throw("Erreur dans la comparaison du type Roche");
    if(f1.getType().compare("Feu") != 0)
      throw("Erreur dans la comparaison du type Feu");
    if(b1.getType().compare("Baie") != 0)
      throw("Erreur dans la comparaison du type Baie");

  }
  catch(...)
  {
     std::cerr << "Erreur dans la récupération des types directement à partir des classes" << std::endl;
     return -1;

  }

  try
  {

    if(elems[0].getType().compare("Arbre") != 0)
      throw("Erreur dans la comparaison du type Arbre dans le vecteur");
    if(elems[1].getType().compare("Roche") != 0)
      throw("Erreur dans la comparaison du type Roche dans le vecteur");
    if(elems[2].getType().compare("Feu") != 0)
      throw("Erreur dans la comparaison du type Feu dans le vecteur");
    if(elems[3].getType().compare("Baie") != 0)
      throw("Erreur dans la comparaison du type Baie dans le vecteur");

  }
  catch(...)
  {
     std::cerr << "Erreur dans la récupération des types à partir des éléments du vecteur" << std::endl;
     return -1;

  }

  //On ne teste pas la fonction getTypeRessource car très similaire au cas précédirectement


  //On teste maintenant les fonctions un peu plus compliquées comme interagir, on teste surtout sur les éléments eux même

  try
  {
    if(!a1.interagir("Hache")) //ON sait que ça devrait renvoyer true, si ça renvoie false on rentre dans le if donc Erreur
      throw("Erreur dans la fonction interagir de Arbre");
    if(!elems[0].interagir("Hache")) //Pareil ici
      throw("Erreur dans la fonction interagir de Arbre issu du vecteur");

    //On ne teste pas pour Roche car fonction identique avec "Pioche" en paramètre

    //On teste la fonction interagir du feu
    int oldVie = f1.getVie();
    f1.interagir("Inutile");
    if(f1.getVie() != oldVie +1)
      throw("Erreur dans la fonction interagir/raviver feu")


  }
  catch(...)
  {
    std::cerr << "Erreur dans le test des fonctions interagir" << std::endl;
    return -1;
  }

  //Tests des fonctions coupDestructif

  try
  {
    //On ne fait pas les tests pour roche car la fonction de cette classe se base sur la même fonction que celle de l'Arbre
     if(a1.coupDestructif() && a1.getVie() !=0) //Si on a encore de la vie alors la fonction ne doit pas renvoyer true
       throw("Erreur dans la fonction coupdestructif de ElemEnv");
     a1.setVie(1); //On met la vie de l'arbre à 1, le prochain coup sera destructif
     if(!a1.coupDestructif()) //Doit renvoyer true, si renvoie false == Erreur
       throw("Erreur dans la fonction coupDestructif de ElemEnv");

    //On teste aussi pour la baie
    b1.setVie(0);
    if(b1.coupDestructif())
      throw("Erreur dans la fonction coupDestructif de Baie");
    b1.setVie(3); //On lui donne une vie positive donc coupDestructif doit renvoyer true car tant qu'il y a des baies le coup doit donner des ressources
    if(!b1.coupDestructif())
      throw("Erreu dans la fonction coupDestructif de Baie");

    //Pour le feu, coupDestructif doit toujours renvoyer false même sil n'a plus de vie
    f1.setVie(1);
    if(f1.coupDestructif())
      throw("Erreur dans la fonction coupDestructif de Feu");

  }
  catch
  {
    std::cerr << "Erreur dans le test des fonctions coupDestructif()" << std::endl;
    return -1;
  }

  try
  {
     //On ne repète pas les premiers tests car les fonctions sont celles de ElemEnv donc ne devrait pas être interprêter différemment
    //On teste aussi pour la baie
    elems[3].setVie(0);
    if(elems[3].coupDestructif())
      throw("Erreur dans la fonction coupDestructif de Baie issu du vecteur");
    elems[3].setVie(3); //On lui donne une vie positive donc coupDestructif doit renvoyer true car tant qu'il y a des baies le coup doit donner des ressources
    if(!elems[3].coupDestructif())
      throw("Erreu dans la fonction coupDestructif de Baie issu du vecteur");

    //Pour le feu, coupDestructif doit toujours renvoyer false même sil n'a plus de vie
    elems[2].setVie(1);
    if(elems[2].coupDestructif())
      throw("Erreur dans la fonction coupDestructif de Feu issu du vecteur");

  }
  catch
  {
    std::cerr << "Erreur dans le test des fonctions coupDestructif() issu du vecteur" << std::endl;
    return -1;
  }


  return 0;
}
