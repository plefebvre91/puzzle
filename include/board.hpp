#ifndef BOARD_HPP
#define BOARD_HPP

#include <SFML/Graphics.hpp>
#include "direction.hpp"
#include "tile.hpp"

class board
{
public:
  board(sf::RenderWindow* w);
  void update(direction d);
  void display() const;
  ~board();

private:
  int libre;
  std::vector<tile*> tiles;
  std::vector<int> indices;
};

#endif
