#ifndef STACK_H
#define STACK_H
#include "Container.h"

template <typename T> class Stack : public Container<T> {
    public:
        Stack() : Container<T>(){};
        void push(T rhs);
        T drop() override;
};

#endif