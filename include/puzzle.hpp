#ifndef PUZZLE_HPP
#define PUZZLE_HPP

#include <SFML/Graphics.hpp>
#include "board.hpp"

class puzzle
{
public:
  puzzle();  
  void run();
  ~puzzle();
  
private:
  board* game;
  sf::RenderWindow* window;
};



#endif
