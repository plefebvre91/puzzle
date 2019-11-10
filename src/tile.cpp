#include "tile.hpp"
#include "constants.hpp"

tile::tile(sf::RenderWindow* w, const std::string& path, const sf::Vector2f& v):
  position(v),texture(),sprite(),thread()
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
  sf::Int32 after = clock.getElapsedTime().asMilliseconds();
  sf::Int32 dt = after - now;
  int t_max = PUZZLE_ANIM_DURATION;

  int old = position.y;
  int a;
  do
    {
      after = clock.getElapsedTime().asMilliseconds();
      a = interp(position.y,position.y -200, after - now, t_max);
      position.y = old+a;
      sprite.setPosition(position);
      dt = after - now;
    } while(dt < t_max);

  position.y = old - 200;
}


void tile::move_thread_down()
{
  sf::Clock clock; // démarre le chrono
  sf::Int32 now = clock.getElapsedTime().asMilliseconds();
  sf::Int32 after = clock.getElapsedTime().asMilliseconds();
  sf::Int32 dt = after - now;
  int t_max = PUZZLE_ANIM_DURATION;

  int old = position.y;
  int a;
  do
    {
      after = clock.getElapsedTime().asMilliseconds();
      a = interp(position.y,position.y +200, after - now, t_max);
      position.y = old+a;
      sprite.setPosition(position);
      dt = after - now;
    } while(dt < t_max);

    position.y = old + 200;
}


void tile::move_thread_left()
{
  sf::Clock clock; // démarre le chrono
  sf::Int32 now = clock.getElapsedTime().asMilliseconds();
  sf::Int32 after = clock.getElapsedTime().asMilliseconds();
  sf::Int32 dt = after - now;
  int t_max = PUZZLE_ANIM_DURATION;

  int old = position.x;
  int a;
  do
    {
      after = clock.getElapsedTime().asMilliseconds();
      a = interp(position.x,position.x - 200, after - now, t_max);
      position.x = old+a;
      sprite.setPosition(position);
      dt = after - now;
    } while(dt < t_max);

    position.x = old - 200;
}




void tile::move_thread_right()
{
  sf::Clock clock; // démarre le chrono
  sf::Int32 now = clock.getElapsedTime().asMilliseconds();
  sf::Int32 after = clock.getElapsedTime().asMilliseconds();
  sf::Int32 dt = after - now;
  int t_max = PUZZLE_ANIM_DURATION;

  int old = position.x;
  int a;
  do
    {
      after = clock.getElapsedTime().asMilliseconds();
      a = interp(position.x,position.x +200, after - now, t_max);
      position.x = old+a;
      sprite.setPosition(position);
      dt = after - now;
    } while(dt < t_max);

  position.x = old + 200;
}




void tile::move(direction d)
{
  int dir = (int)d;
  
  thread[dir]->launch();
}

