#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
// #include <map>
#include <string>

#include "Dictionary.hpp"

namespace tampio
{
  using Dict = tampio::Dictionary< std::string, std::string >;
  using DictOfDict = tampio::Dictionary< std::string, Dict >;

  void print(const Dict& list, const std::string& name, std::ostream& os);
  Dict complement(const Dict&, const Dict&);
  Dict intersect(const Dict&, const Dict&);
  Dict unionDict(const Dict&, const Dict&);
}
#endif