#ifndef QUEUE_H
#define QUEUE_H
#include "Container.h"

template<typename T>
class Queue : public Container<T> {
    public:
        void push(T rhs) override;
        T drop() override;
};

#endif