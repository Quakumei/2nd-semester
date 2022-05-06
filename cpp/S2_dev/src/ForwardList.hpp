#ifndef FORWARDLIST_H
#define FORWARDLIST_H

#include <stdexcept>
#include <utility>

namespace tampio
{
  template< class T >
  class ForwardList
  {
  private:
    struct node_t;

  public:
    ForwardList();
    ForwardList(const ForwardList &);
    ForwardList(ForwardList &&) noexcept;
    ~ForwardList();
    ForwardList &operator=(const ForwardList &);
    ForwardList &operator=(ForwardList &&) noexcept;

    void pushBack(const T &);
    void pushFront(const T &);
    void deleteFront();
    T front() const;
    T tail() const;
    bool empty() const noexcept;

    // Iterator
    class Iterator;
    Iterator begin();
    Iterator end();
    Iterator beforeBegin();
    Iterator insertAfter(Iterator, const T &);

  private:
    struct node_t
    {
      T data;
      node_t *next;
    };

    void swap(ForwardList &) noexcept;

    node_t *head_;
    node_t *tail_;
  };

  template< class T >
  class ForwardList< T >::Iterator
  {
  public:
    Iterator();
    Iterator(node_t *);
    Iterator(const Iterator &);
    ~Iterator() = default;
    Iterator &operator=(const Iterator &);
    T &operator*();
    const T &operator*() const;
    T *operator->();
    const T *operator->() const;
    bool operator!=(const Iterator &) const;
    bool operator==(const Iterator &) const;
    Iterator &operator++();
    Iterator operator++(int);

  private:
    node_t *nodeptr_;

    // friend ForwardList::node_t;
  };
}

template< class T >
void tampio::ForwardList< T >::deleteFront()
{
  if (!head_)
  {
    throw std::logic_error("ForwardList is empty");
  }
  node_t *temp = head_;
  head_ = (head_ == tail_) ? tail_ = nullptr : head_->next;
  delete temp;
}
template< class T >
T tampio::ForwardList< T >::front() const
{
  return head_->data;
}

template< class T >
void tampio::ForwardList< T >::pushBack(const T &d)
{
  if (!head_)
  {
    head_ = tail_ = new node_t;
  }
  else
  {
    tail_->next = new node_t;
    tail_ = tail_->next;
  }
  tail_->data = d;
  tail_->next = nullptr;
}
template< class T >
void tampio::ForwardList< T >::pushFront(const T &val)
{
  node_t *newNode = new node_t;
  newNode->data = val;
  newNode->next = head_;
  head_ = newNode;
}

template< class T >
T tampio::ForwardList< T >::tail() const
{
  return tail_->data;
}

template< class T >
tampio::ForwardList< T >::ForwardList() :
    head_(nullptr),
    tail_(nullptr)
{
}

template< class T >
tampio::ForwardList< T >::ForwardList(const ForwardList &ForwardList) :
    head_(nullptr),
    tail_(nullptr)
{
  tampio::ForwardList< T > temp;
  node_t *src = ForwardList.head_;
  while (src)
  {
    temp.pushBack(src->data);
    src = src->next;
  }
  swap(temp);
}

template< class T >
tampio::ForwardList< T >::ForwardList(ForwardList &&ForwardList) noexcept :
    head_(nullptr),
    tail_(nullptr)
{
  swap(ForwardList);
}

template< class T >
tampio::ForwardList< T >::~ForwardList()
{
  while (head_)
  {
    node_t *temp = head_;
    head_ = head_->next;
    delete temp;
  }
}

template< class T >
tampio::ForwardList< T > &tampio::ForwardList< T >::operator=(
    const ForwardList &ForwardList)
{
  if (this == &ForwardList)
  {
    return *this;
  }

  tampio::ForwardList< T > tempForwardList(ForwardList);
  swap(tempForwardList);

  return *this;
}

template< class T >
tampio::ForwardList< T > &tampio::ForwardList< T >::operator=(
    ForwardList &&ForwardList) noexcept
{
  swap(ForwardList);
  return *this;
}

template< class T >
bool tampio::ForwardList< T >::empty() const noexcept
{
  return !head_;
}

template< class T >
void tampio::ForwardList< T >::swap(ForwardList &ForwardList) noexcept
{
  std::swap(head_, ForwardList.head_);
  std::swap(tail_, ForwardList.tail_);
}

// Iterator
template< class T >
tampio::ForwardList< T >::Iterator::Iterator() :
    nodeptr_(nullptr){};
template< class T >
tampio::ForwardList< T >::Iterator::Iterator(const Iterator &other) :
    nodeptr_(other.nodeptr_){};
template< class T >
tampio::ForwardList< T >::Iterator::Iterator(node_t *node) :
    nodeptr_(node){};

template< class T >
typename tampio::ForwardList< T >::Iterator &
tampio::ForwardList< T >::Iterator::operator=(const Iterator &other)
{
  nodeptr_ = other.nodeptr_;
}

template< class T >
T &tampio::ForwardList< T >::Iterator::operator*()
{
  return nodeptr_;
}
template< class T >
const T &tampio::ForwardList< T >::Iterator::operator*() const
{
  return nodeptr_;
}
template< class T >
T *tampio::ForwardList< T >::Iterator::operator->()
{
  return nodeptr_;
}
template< class T >
const T *tampio::ForwardList< T >::Iterator::operator->() const
{
  return nodeptr_;
}
template< class T >
bool tampio::ForwardList< T >::Iterator::operator==(const Iterator &oth) const
{
  return nodeptr_ == oth.nodeptr_;
}
template< class T >
bool tampio::ForwardList< T >::Iterator::operator!=(const Iterator &oth) const
{
  return !(nodeptr_ == oth.nodeptr_);
}
template< class T >
typename tampio::ForwardList< T >::Iterator &
tampio::ForwardList< T >::Iterator::operator++()
{
  nodeptr_ = nodeptr_->next;
  return *this;
}
template< class T >
typename tampio::ForwardList< T >::Iterator
tampio::ForwardList< T >::Iterator::operator++(int)
{
  typename tampio::ForwardList< T >::Iterator temp(nodeptr_);
  ++(*this);
  return temp;
}
// Iterator methods in ForwardList
template< class T >
typename tampio::ForwardList< T >::Iterator tampio::ForwardList< T >::begin()
{
  return typename tampio::ForwardList< T >::Iterator(head_);
}
template< class T >
typename tampio::ForwardList< T >::Iterator tampio::ForwardList< T >::end()
{
  // По факту, некорректно, поскольку должен указывать на элемент, после
  // последнего. TODO: FIX ME
  return typename tampio::ForwardList< T >::Iterator(tail_);
}

#endif