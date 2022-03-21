#ifndef STACK_H
#define STACK_H
#include "List.hpp"

template <class T>
class Stack
{
public:
    Stack<T>()
    {
        list_data = List<T>();
    };
    ~Stack<T>(){};

    void push(T a) { list_.pushHead(a); };
    T drop() { return list_.dropHead(); };

    T peek() const { return list_.top(); };
    bool isEmpty() const { return list_.isEmpty(); };

    Stack(const Stack &st)
    {
        list_ = st.list_;
    };
    Stack(Stack &&st)
    {
        list_ = st.list_;
    };
    Stack &operator=(const Stack &st)
    {
        list_ = st.list_;

        return *this;
    };
    Stack &operator=(Stack &&st)
    {
        list_ = st.list_;

        return *this;
    };

private:
    List<T> list_data;
    List<T> &list_ = list_data;
};

#endif