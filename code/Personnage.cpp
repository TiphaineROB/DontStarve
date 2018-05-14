
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
