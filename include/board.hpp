#ifndef BOARD_HPP
#define BOARD_HPP

#include <SFML/Graphics.hpp>
#include "direction.hpp"
#include "tile.hpp"

class board
{
public:
  /**
   * Constructor
   * \param Rendering window
   */
  board(sf::RenderWindow* w);

  /**
   * Update tiles positions on the board
   * \param user keyboard input
   */
  void update(direction d);

  /**
   * Display board game
   */
  void display() const;

  /**
   * Destructor
   */
  ~board();

private:
  int libre;
  /**
   * Tiles set
   */
  std::vector<tile*> tiles;
  std::vector<int> indices;
};

#endif
