#ifndef QUEUE_H
#define QUEUE_H

#include "List.hpp"
namespace tampio
{

    template <class T>
    class Queue
    {
    public:
        Queue<T>() = default;

        void push(const T &a);
        T drop();
        T peek() const;

        bool isEmpty() const;

    private:
        List<T> list_;
    };

    template <class T>
    void Queue<T>::push(const T &a)
    {
        list_.pushTail(a);
    };
    template <class T>
    T Queue<T>::drop()
    {
        return list_.dropHead();
    };
    template <class T>
    T Queue<T>::peek() const
    {
        return list_.top();
    };
    template <class T>
    bool Queue<T>::isEmpty() const
    {
        return list_.isEmpty();
    };
}

#endif
