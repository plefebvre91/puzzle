#ifndef PUZZLE_HPP
#define PUZZLE_HPP

#include <SFML/Graphics.hpp>
#include "board.hpp"

class puzzle
{
public:
  /**
   * Constructor
   */
  puzzle();

  /**
   * Launch application
   */
  void run();

  /**
   * Destructor
   */
  ~puzzle();
  
private:
  board* game;
  sf::RenderWindow* window;
};



#endif
