#include "board.hpp"
#include "constants.hpp"

board::board(sf::RenderWindow* w)
{
  libre = 8;
  
  for(int i=0; i<PUZZLE_MAX_INDEX; i++)
    {
      int dx = i % 3;
      int dy = i / 3;
      
      float x = dx * PUZZLE_TILE_SIZE;
      float y = dy * PUZZLE_TILE_SIZE;
      sf::Vector2f p(x,y);
      std::string path = "../resources/social/" + std::to_string(i) + ".jpg";
      tiles.push_back(new tile(w, path, p));
      indices.push_back(i);
    }

  indices.push_back(PUZZLE_MAX_INDEX);
}


void board::update(direction d)
{
  if(d == direction::up)
    {
      if (libre <=5)
	{
	  libre += 3;
	  tiles[indices[libre]]->move(d);
	  std::swap<int>(indices[libre], indices[libre-3]);
	}
    }
    
  else if(d == direction::down)
    {
      if (libre >= 3)
	{
	  libre -= 3;
	  tiles[indices[libre]]->move(d);
	  std::swap<int>(indices[libre], indices[libre+3]);
	}
    }

    
  else if(d == direction::left)
    {
      if ((libre+1)%3 != 0)
	{
	  libre++;
	  tiles[indices[libre]]->move(d);
	  std::swap<int>(indices[libre], indices[libre-1]);
	}
    }
    
  else if(d == direction::right)
    {
      if ((libre)%3 !=  0)
	{
	  libre--;
	  tiles[indices[libre]]->move(d);
	  std::swap<int>(indices[libre], indices[libre+1]);
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

