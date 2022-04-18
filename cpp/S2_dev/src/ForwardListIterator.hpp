#ifndef FORWARDLISTITERATOR_H
#define FORWARDLISTITERATOR_H

namespace tampio
{
  template< class ForwardList >
  class ForwardListIterator
  {
  public:
    using StructType = typename ForwardList::StructType;
    using StructPointerType = StructType*;
    using ValueType = typename ForwardList::ValueType;
    using PointerType = ValueType*;
    using ReferenceType = ValueType&;

  public:
    ForwardListIterator(StructPointerType ptr) :
        mPtr_(ptr)
    {}
    ForwardListIterator& operator++()
    {
      // TODO:Rework
      mPtr_ = mPtr_->next;
      return *this;
    }
    ForwardListIterator operator++(int)
    {
      // TODO:Rework
      ForwardListIterator iterator = *this;
      ++(*this);
      return iterator;
    }
    // ForwardListIterator& operator--()
    // {
    //   // TODO:Rework
    //   mPtr_--;
    //   return *this;
    // }
    // ForwardListIterator operator--(int)
    // {
    //   // TODO:Rework
    //   ForwardListIterator iterator = *this;
    //   --(*this);
    //   return iterator;
    // }

    ReferenceType operator[](int index)
    {
      return *(mPtr_ + index);
    }

    PointerType operator->()
    {
      return mPtr_;
    }

    ReferenceType operator*()
    {
      return mPtr_->data;
    }

    bool operator==(const ForwardListIterator& other) const
    {
      return mPtr_ == other.mPtr_;
    }

    bool operator!=(const ForwardListIterator& other) const
    {
      return !(*this == other);
    }

  private:
    StructPointerType mPtr_;
  };

}
#endif
