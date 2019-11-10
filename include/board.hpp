/* MIT License

Copyright (c) 2019 Pierre Lefebvre

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE. */


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
