#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <utility>

#include "ForwardList.hpp"

namespace tampio
{
  template< typename Key, typename Value, typename Compare >
  class Dictionary
  {
  public:
    void push(Key k, Value v);
    Value get(Key k);
    Value drop(Key k);

  private:
    ForwardList< std::pair< Key, Value > > listData_;
  };
}

#endif
