#include "puzzle.hpp"
#include "constants.hpp"
#include <iostream>

puzzle::puzzle()
{
  window = new
    sf::RenderWindow(sf::VideoMode( PUZZLE_WINDOW_SIZE, PUZZLE_WINDOW_SIZE), PUZZLE_APP_TITLE);
  window->setVerticalSyncEnabled(true);
  game = new board(window);
}
  
void puzzle::run()
{
  // Start the game loop
  while (window->isOpen())
  {
    // Process events
    sf::Event event;
    while (window->pollEvent(event))
      {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	  game->update(direction::left);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	  game->update(direction::right);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	  game->update(direction::up);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	  game->update(direction::down);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	  window->close();
      
	if (event.type == sf::Event::Closed)
	  window->close();
    }
    
    window->clear();
    game->display();
    window->display();

    if(game->is_finished())
      std::cout << "Done." << std::endl;
    
  }
}

puzzle::~puzzle()
{
  delete game;
  delete window;
}
