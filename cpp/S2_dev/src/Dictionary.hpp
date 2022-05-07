#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdexcept>
#include <utility>

#include "ForwardList.hpp"
namespace tampio
{
  template< class Key, class Value, class Compare = std::less< Key > >
  class Dictionary
  {
  public:
    using List = ForwardList< std::pair< Key, Value > >;
    using Dict = Dictionary< Key, Value, Compare >;

    Dictionary();
    ~Dictionary() = default;
    Dictionary(const Dict& other);
    Dictionary(Dict&& other);
    Dict& operator=(const Dict& other) = default;
    Dict& operator=(Dict&& other) = default;

    void push(const Key&, const Value&);
    Value get(const Key&) const;
    Value drop(const Key&);

    bool doesKeyExist(const Key&);

    // Iterator methods
    typename List::Iterator find(const Key&);

  private:
    Compare cmp_;
    /*
      p1 | p2 | p3,
      (p1 >= p2 >= p3)
    */
    List data_;
  };
}

template< class Key, class Value, class Compare >
tampio::Dictionary< Key, Value, Compare >::Dictionary() :
    cmp_(Compare()),
    data_()
{
}
template< class Key, class Value, class Compare >
tampio::Dictionary< Key, Value, Compare >::Dictionary(const Dict& other) :
    cmp_(Compare()),
    data_(other.data_)
{
}
template< class Key, class Value, class Compare >
tampio::Dictionary< Key, Value, Compare >::Dictionary(Dict&& other) :
    cmp_(Compare()),
    data_(other.data_)
{
}
template< class Key, class Value, class Compare >
bool tampio::Dictionary< Key, Value, Compare >::doesKeyExist(const Key& key)
{
  return find(key) != typename List::Iterator();
}

template< class Key, class Value, class Compare >
void tampio::Dictionary< Key, Value, Compare >::push(const Key& key,
    const Value& value)
{
  if (!doesKeyExist(key))
  {
    return;
  }
  std::pair< Key, Value > tempPair(key, value);
  typename List::Iterator it = data_.beforeBegin();
  while ((it + 1) != data_.end())
  {
    if (cmp(tempPair.first, (it + 1)->first))
    {
      data_.insertAfter(it, tempPair);
      return;
    }
    ++it;
  }
  data_.insertAfter(it, tempPair);
  return;
}
template< class Key, class Value, class Compare >
Value tampio::Dictionary< Key, Value, Compare >::get(const Key& key) const
{
  if (!doesKeyExist(key))
  {
    throw std::out_of_range("No such key in the dict. (get())");
  }
  return *find(key).second;
}
template< class Key, class Value, class Compare >
Value tampio::Dictionary< Key, Value, Compare >::drop(const Key& key)
{
  if (!doesKeyExist(key))
  {
    throw std::out_of_range("No such key in the dict. (get())");
  }
  typename List::Iterator it = find(key);
  Value temp = *it.second;
  data_.deleteNode(it);
  return temp;
}

// Iterator methods
template< class Key, class Value, class Compare >
typename tampio::Dictionary< Key, Value, Compare >::List::Iterator
tampio::Dictionary< Key, Value, Compare >::find(const Key& key)
{
  // Небольшой костыль при работе с кастрированным end()
  typename List::Iterator i = data_.begin();
  while (i != data_.end())
  {
    if (*i.first == key)
    {
      return i;
    }
    i++;
  }
  return typename List::Iterator();
}

#endif