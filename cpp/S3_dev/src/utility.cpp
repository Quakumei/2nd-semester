#include <ostream>
#include "utility.hpp"
#include "BidirectionalList.hpp"
#include "Dictionary.hpp"

// void tampio::print(const tampio::Dict& d, const std::string& name, std::ostream& os)
// {
//   if (d.empty())
//   {
//     os << "<EMPTY>" << '\n';
//     return;
//   }
//   os << name << ' ';
//   d.print(os);
//   os << '\n';
//   return;
// }
void tampio::print(const tampio::BidirectionalList< long >& d, const std::string& name, std::ostream& os)
{
  if (d.empty())
  {
    os << "<EMPTY>" << '\n';
    return;
  }
  os << name << ' ';
  d.print(os);
  os << '\n';
  return;
}
void tampio::replace(BidirectionalList< long >& l, long what, const BidirectionalList< long >& lother)
{
  for (typename tampio::BidirectionalList< long >::Iterator i = l.begin(); i != l.end(); i++)
  {
    if (*i == what)
    {
      l.deleteNode(i++);
      for (typename tampio::BidirectionalList< long >::Iterator j = lother.begin(); j != lother.end(); j++)
      {
        l.insertBefore(i, *j);
      }
    }
  }
}
void tampio::replace(BidirectionalList< long >& l, long what, long towhat)
{
  for (typename tampio::BidirectionalList< long >::Iterator i = l.begin(); i != l.end(); i++)
  {
    if (*i == what)
    {
      *i = towhat;
    }
  }
}

void tampio::removeElems(BidirectionalList< long >& l, const BidirectionalList< long >& what_list)
{
  for (typename tampio::BidirectionalList< long >::Iterator i = what_list.begin(); i != l.end(); i++)
  {
    removeElems(l, *i);
  }
}
void tampio::removeElems(BidirectionalList< long >& l, long what)
{
  for (typename tampio::BidirectionalList< long >::Iterator i = l.begin(); i != l.end(); i++)
  {
    if (*i == what)
    {
      l.deleteNode(i++);
    }
  }
}