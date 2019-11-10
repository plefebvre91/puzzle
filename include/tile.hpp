#ifndef TILE_HPP
#define TILE_HPP

#include <SFML/Graphics.hpp>
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
    sf::Vector2f position;
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
};


#endif
