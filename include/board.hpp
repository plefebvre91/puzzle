#ifndef BOARD_HPP
#define BOARD_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
   * Returns true if all tiles are at the right place
   */
  bool is_finished() const;
  
  /**
   * Destructor
   */
  ~board();

private:
  int libre;

  sf::SoundBuffer buffer[2];
  sf::Sound sound[2];
  /**
   * Tiles set
   */
  std::vector<tile*> tiles;
  std::vector<int> indices;
};

#endif
