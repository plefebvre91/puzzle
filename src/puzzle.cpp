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

  bool game_is_finished = false;
  
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

    game_is_finished = game->is_finished();
  }

  if(game_is_finished)
  {
    std::cout << "Congratulations !\n" << std::endl;
  }
  
  if(window->isOpen())
      window->close();
  
}

puzzle::~puzzle()
{
  delete game;
  delete window;
}
