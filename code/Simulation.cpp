#include <SFML/Graphics.hpp>
#include "Simulation.hpp"

using namespace sf;


int main()
{
  RenderWindow window(VideoMode(200,200),"ROB Starving");
  Texture texture;
  Sprite sprite;
  sprite perso

  if(!texture.loadFromFile("../images/fond.jpg"))
  {
    std::cout << "BAD MADAFAKA" << std::endl;
  }
  sprite.setTexture(texture);
  while(window.isOpen())
  {
    Event event;
    while(window.pollEvent(event))
    {
      if (event.type == Event::Closed)
        window.close();
    }
    window.clear();
    window.draw(sprite);
    window.display();
  }
  return 0;
}
