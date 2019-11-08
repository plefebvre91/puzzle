#ifndef TILE_HPP
#define TILE_HPP

#include <SFML/Graphics.hpp>
#include "direction.hpp"

class tile
{
public:
  tile(sf::RenderWindow* w, const std::string& path, const sf::Vector2f& v);

  void display() const;  
  void move(direction d);
  
private:
  void move_thread_up();
  void move_thread_down();
  void move_thread_left();
  void move_thread_right();

  sf::Vector2f position;
  sf::Texture texture;
  sf::RenderWindow* window; 
  sf::Sprite sprite;
  std::vector<sf::Thread*> thread;
};


#endif
