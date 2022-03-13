#include "Stack.h"

template <typename T>
T Stack<T>::drop(){
    //Double-check
    if (*this->size_ == 0){
        throw std::logic_error("Empty!");
    }
    --*this->size_;
    return *(*this->array_[*this->size]);
}

