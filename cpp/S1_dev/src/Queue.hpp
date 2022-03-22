#ifndef QUEUE_H
#define QUEUE_H

#include "List.hpp"

template <class T>
class Queue
{
public:
    Queue<T>()
    {
        list_ = List<T>();
    };
    ~Queue<T>(){};

    void push(T a) { list_.pushTail(a); };
    T drop() { return list_.dropHead(); };

    T peek() const { return list_.top(); };
    bool isEmpty() const { return list_.isEmpty(); };

    Queue(const Queue &st)
    {
        list_ = st.list_;
    };
    Queue(Queue &&st)
    {
        list_ = st.list_;
    };
    Queue &operator=(const Queue &st)
    {
        list_ = st.list_;

        return *this;
    };
    Queue &operator=(Queue &&st)
    {
        list_ = st.list_;

        return *this;
    };

private:
    List<T> list_;
};
#endif
