#include "puzzle.hpp"

int main(int argc, char** argv)
{
  (void) argc;
  (void) argv;
  
  puzzle* application = new puzzle();

  application->run();

  delete application;
  
  return 0;
}
