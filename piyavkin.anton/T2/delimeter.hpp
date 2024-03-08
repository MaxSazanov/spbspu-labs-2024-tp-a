#ifndef DELIMETER_HPP
#define DELIMETER_HPP
#include <istream>

namespace piyavkin
{
  struct DelimeterString
  {
    std::string expected;
  };
  struct DelimeterChar
  {
    char expected;
  };
  std::istream& operator>>(std::istream& in, DelimeterChar&& exp);
  std::istream& operator>>(std::istream& in, DelimeterString&& exp);
}
#endif