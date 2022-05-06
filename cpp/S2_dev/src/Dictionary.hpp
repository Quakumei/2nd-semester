#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdexcept>
#include <utility>

#include "ForwardList.hpp"
namespace tampio
{
  template< class Key, class Value, class Compare >
  class Dictionary
  {
  public:
    using List = ForwardList< std::pair< Key, Value > >;
    void push(const Key&, const Value&);
    Value get(const Key&);
    Value drop(const Key&);

  private:
  };
}

#endif