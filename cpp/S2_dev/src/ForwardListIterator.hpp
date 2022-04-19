#ifndef FORWARDLISTITERATOR_H
#define FORWARDLISTITERATOR_H

namespace tampio
{
  template< class ForwardList >
  class ForwardListIterator
  {
  public:
    using StructType = typename ForwardList::StructType;
    using StructPointerType = StructType *;
    using ValueType = typename ForwardList::ValueType;
    using PointerType = ValueType *;
    using ReferenceType = ValueType &;

  public:
    ForwardListIterator(StructPointerType ptr) :
        ptr_(ptr)
    {}
    ForwardListIterator &operator++()
    {
      ptr_ = ptr_->next;
      return *this;
    }
    ForwardListIterator operator++(int)
    {
      ForwardListIterator iterator = *this;
      ++(*this);
      return iterator;
    }
    ReferenceType operator[](int index)
    {
      return *(ptr_ + index);
    }

    PointerType operator->()
    {
      return ptr_;
    }

    ReferenceType operator*()
    {
      return ptr_->data;
    }

    bool operator==(const ForwardListIterator &other) const
    {
      return ptr_ == other.ptr_;
    }

    bool operator!=(const ForwardListIterator &other) const
    {
      return !(*this == other);
    }

  private:
    StructPointerType ptr_;
  };

} // namespace tampio
#endif
