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


#include "tile.hpp"
#include "constants.hpp"

tile::tile(sf::RenderWindow* w, const std::string& path, const sf::Vector2f& v):
  position(v),texture(),sprite(),thread(), mutex()
  {
    window = w;
    texture.loadFromFile(path);
    sprite.setTexture(texture, true);
    sprite.setPosition(position);

    thread.push_back(new sf::Thread(&tile::move_thread_up, this));
    thread.push_back(new sf::Thread(&tile::move_thread_down, this));
    thread.push_back(new sf::Thread(&tile::move_thread_left, this));
    thread.push_back(new sf::Thread(&tile::move_thread_right, this));
  }
  
void tile::display() const
{
  window->draw(sprite);
}


int interp(int a, int b, int dt, int t_max)
{
  float dm = (float)dt / (float)t_max;
  return (float)(b-a)*dm;
}


void tile::move_thread_up()
{
  sf::Clock clock;
  sf::Int32 now = clock.getElapsedTime().asMilliseconds();
  sf::Int32 after;
  int t_max = PUZZLE_ANIM_DURATION;

  int old = position.y;
  int a;
  mutex.lock();
  do
    {
      after = clock.getElapsedTime().asMilliseconds();
      a = interp(position.y,position.y -200, after - now, t_max);
      position.y = old+a;
      sprite.setPosition(position);
    } while(position.y > (old - 200));
  mutex.unlock();
  position.y = old - 200;

}



void tile::move_thread_down()
{
  sf::Clock clock; // démarre le chrono
  sf::Int32 now = clock.getElapsedTime().asMilliseconds();
  sf::Int32 after;
  int t_max = PUZZLE_ANIM_DURATION;

  int old = position.y;
  int a;

  mutex.lock();
  do
    {
      after = clock.getElapsedTime().asMilliseconds();
      a = interp(position.y,position.y +200, after - now, t_max);
      position.y = old+a;
      sprite.setPosition(position);
    } while(position.y < old + 200);
  
  position.y = old + 200;
  mutex.unlock();
}


void tile::move_thread_left()
{
  sf::Clock clock; // démarre le chrono
  sf::Int32 now = clock.getElapsedTime().asMilliseconds();
  sf::Int32 after;
  int t_max = PUZZLE_ANIM_DURATION;

  int old = position.x;
  int a;
  mutex.lock();
  do
    {
      after = clock.getElapsedTime().asMilliseconds();
      a = interp(position.x,position.x - 200, after - now, t_max);
      position.x = old+a;
      sprite.setPosition(position);

    } while(position.x > (old - 200));
  
  position.x = old - 200;
  mutex.unlock();
}




void tile::move_thread_right()
{
  sf::Clock clock; // démarre le chrono
  sf::Int32 now = clock.getElapsedTime().asMilliseconds();
  sf::Int32 after;
  int t_max = PUZZLE_ANIM_DURATION;

  int old = position.x;
  int a;

  mutex.lock();
  do
    {
      after = clock.getElapsedTime().asMilliseconds();
      a = interp(position.x,position.x +200, after - now, t_max);
      position.x = old+a;
      sprite.setPosition(position);
    } while(position.x < old + 200);

  position.x = old + 200;
  mutex.unlock();
}


void tile::move(direction d)
{
  int dir = (int)d;

  mutex.lock();
  thread[dir]->launch();
  mutex.unlock();
}
