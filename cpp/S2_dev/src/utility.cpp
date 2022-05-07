#include <ostream>

#include "utility.hpp"

#include "Dictionary.hpp"

void tampio::print(const tampio::Dict& d,
    const std::string& name,
    std::ostream& os)
{
  if (d.empty())
  {
    std::cout << "<EMPTY>" << '\n';
    return;
  }
  os << name << ' ';
  d.print(os);
  os << '\n';
  return;
}