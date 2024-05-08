#include <iostream>
#include <vector>
#include <iterator>
#include <limits>
#include <fstream>
#include <algorithm>
#include "Polygon.hpp"
#include "CommandFacade.hpp"

using namespace sazanov;
int main(int argc, char* argv[])
{
 if (argc < 2)
  {
    std::cerr << "missed filename argument\n";
    return 1;
  }
  std::ifstream file(argv[1]);
  if (!file.is_open())
  {
    std::cerr << "cant open file\n";
    return 2;
  }

  std::vector< Polygon > polygons;
  using input_it_t = std::istream_iterator< Polygon >;
  while (!file.eof())
  {
    std::copy(input_it_t{file}, input_it_t{}, std::back_inserter(polygons));
    file.clear();
    file.ignore(std::numeric_limits< std::streamsize >::max(), '\n');
  }
  file.close();

  CommandFacade facade(polygons);
  while (!std::cin.eof())
  {
    facade.nextCommand(std::cin, std::cout);
    std::cin.clear();
    std::cin.ignore(std::numeric_limits< std::streamsize >::max(), '\n');
    if (!std::cin.eof())
    {
      std::cout << '\n';
    }
  }
  return 0;
}