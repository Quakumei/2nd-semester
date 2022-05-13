#ifndef UTILITY_H
#define UTILITY_H

#include <ostream>
#include <string>
#include "BidirectionalList.hpp"
#include "Dictionary.hpp"

namespace tampio
{
  using Dict = tampio::Dictionary< std::string, std::string >;
  void print(const BidirectionalList< long >& l, const std::string& name, std::ostream& os);
  void replace(BidirectionalList< long >& l, long what, const BidirectionalList< long >& lother);
  void replace(BidirectionalList< long >& l, long what, long towhat);
}
#endif
