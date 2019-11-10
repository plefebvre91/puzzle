#include "board.hpp"
#include "constants.hpp"
#include <chrono>
#include <random>
#include <thread>
#include <iostream>

board::board(sf::RenderWindow* w)
{
  libre = 8;

  for(int i=0; i<PUZZLE_MAX_INDEX; i++) {
    indices.push_back(i);
    std::cout << i << "\n";
  }

  indices.push_back(8);
  
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  shuffle (indices.begin(), indices.end(), std::default_random_engine(seed));

  int i=0;
  for(auto index: indices)
    {
      if(index != 8){
	sf::Vector2i d(i % 3, i / 3);
	sf::Vector2f p(d.x * PUZZLE_TILE_SIZE, d.y * PUZZLE_TILE_SIZE);
	
	std::string path = "../resources/default/"
	  + std::to_string(index) + ".jpg";
	std::cout << "loading: " << path << std::endl;
      std::cout << index << " ";
      tiles.push_back(new tile(w, path, p));

      }
      else
	{
	  sf::Vector2i d(i % 3, i / 3);
	  sf::Vector2f p(d.x * PUZZLE_TILE_SIZE, d.y * PUZZLE_TILE_SIZE);

	std::string path = "../resources/default/image.jpg";
	tiles.push_back(new tile(w, path, p));
	libre = i;
      }
      i++;    

    }

  std::cout << std::endl;
}


void board::update(direction d)
{
  if(d == direction::up)
    {

      if (libre <=5)
	{
	  libre += 3;
	  tiles[libre]->move(d);
	  tiles[libre-3]->move(direction::down);
	  
	  std::swap<int>(indices[libre], indices[libre-3]);
	  std::swap<tile*>(tiles[libre], tiles[libre-3]);
	}
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
	}
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
	}
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
	}
    }
  else
    {
    }
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

