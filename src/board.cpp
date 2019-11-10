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


#include "board.hpp"
#include "constants.hpp"
#include <chrono>
#include <random>
#include <thread>
#include <iostream>

board::board(sf::RenderWindow* w)
{
  for(int i=0; i<PUZZLE_MAX_INDEX+1; i++)
    indices.push_back(i);
  
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  shuffle (indices.begin(), indices.end(), std::default_random_engine(seed));

  int i=0;
  for(auto index: indices)
  {
    sf::Vector2i d(i % 3, i / 3);
    sf::Vector2f p(d.x * PUZZLE_TILE_SIZE, d.y * PUZZLE_TILE_SIZE);
    std::string path = "../resources/social/" + std::to_string(index) + ".png";
 
    if(index == PUZZLE_MAX_INDEX)
      libre = i;

    tiles.push_back(new tile(w, path, p));
    i++;    
  }
  
  buffer[0].loadFromFile("../resources/snd/move.wav");
  buffer[1].loadFromFile("../resources/snd/wrong_move.wav");
  sound[0].setBuffer(buffer[0]);
  sound[1].setBuffer(buffer[1]);
}


void board::update(direction d)
{
  unsigned int free_tile_index;
  unsigned int moving_tile_index;

  if(d == direction::up)
    {

      if (libre <=5)
	{
	  libre += 3;
	  tiles[libre]->move(d);
	  tiles[libre-3]->move(direction::down);
	  
	  std::swap<int>(indices[libre], indices[libre-3]);
	  std::swap<tile*>(tiles[libre], tiles[libre-3]);
	  sound[0].play();
	}
      else
	sound[1].play();
    }
    
  else if(d == direction::down)
    {
      if (libre >= 3)
	{
	  libre -= 3;
	  tiles[libre]->move(d);
	  tiles[libre+3]->move(direction::up);
	  std::swap<int>(indices[libre], indices[libre+3]);
	  std::swap<tile*>(tiles[libre], tiles[libre+3]);
	  sound[0].play();
	}
      else
	sound[1].play();
    }

    
  else if(d == direction::left)
    {
      if ((libre+1)%3 != 0)
	{
	  libre++;
	  tiles[libre]->move(d);
	  tiles[libre-1]->move(direction::right);
	  std::swap<int>(indices[libre], indices[libre-1]);
	  std::swap<tile*>(tiles[libre], tiles[libre-1]);
	  sound[0].play();
	}
      else
	sound[1].play();
    }
    
  else if(d == direction::right)
    {
      if ((libre)%3 !=  0)
	{
	  libre--;
	  tiles[libre]->move(d);
	  tiles[libre+1]->move(direction::left);
	  std::swap<int>(indices[libre], indices[libre+1]);
	  std::swap<tile*>(tiles[libre], tiles[libre+1]);
	  sound[0].play();
	}
      else
	sound[1].play();
    }
  else
    {
        sound[1].play();
    }
}

bool board::is_finished() const
{
  int i = 0;
  bool done = true;

  while((i < PUZZLE_MAX_INDEX) && done)
    {
      done = (bool)(indices[i] == i);
      i++;
    }
  
  return done;
}


void board::display() const
{
  for(auto t : tiles)
    t->display();
}

board::~board()
{
  for(auto t : tiles)
    delete t;
}
