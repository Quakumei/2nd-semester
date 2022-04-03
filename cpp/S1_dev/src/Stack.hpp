#ifndef STACK_H
#define STACK_H

#include "List.hpp"
namespace tampio
{
    template <class T>
    class Stack
    {
    public:
        Stack<T>() = default;
        ~Stack<T>() = default;

        void push(const T &a);
        T drop();
        T peek() const;

        bool isEmpty() const;

    private:
        List<T> list_;
    };

    template <class T>
    void Stack<T>::push(const T &a)
    {
        list_.pushHead(a);
    };
    template <class T>
    T Stack<T>::drop()
    {
        return list_.dropHead();
    };
    template <class T>
    T Stack<T>::peek() const
    {
        return list_.top();
    };
    template <class T>
    bool Stack<T>::isEmpty() const
    {
        return list_.isEmpty();
    };
}

#endif
