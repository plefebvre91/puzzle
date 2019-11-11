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


#ifndef TILE_HPP
#define TILE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "direction.hpp"

class tile
{
public:
  /**
   * Constructor
   * \param rendering window
   * \param images path
   * \param intial position
   */
  tile(sf::RenderWindow* w, const std::string& path, const sf::Vector2f& v);

  /**
   * Draw the tile
   */
  void display() const;  

  /**
   * Move the tile
   * \param direction to move
   */
  void move(direction d);

private:
  /**
   * Animation threads
   */
  void move_thread_up();
  void move_thread_down();
  void move_thread_left();
  void move_thread_right();


  /**
   * Tile position
   */
  sf::Vector2f position;

  /**
   * Texture associated to the sprite
   */
  sf::Texture texture;

  /**
   * Rendering window
   */
  sf::RenderWindow* window; 

  /**
   * Image
   */
  sf::Sprite sprite;

  /**
   * Animation thread pool
   */
  std::vector<sf::Thread*> thread;

  /**
   * Protect position updates
   */
  sf::Mutex mutex;

};


#endif
