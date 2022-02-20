#include "Container.h"
#include <iostream>
#include <utility>

template <typename T>
Container<T>::Container() : size_(0),
                            capacity_(1),
                            array_(new T **[capacity_])
{}

template <typename T>
Container<T>::~Container()
{
    delete[] array_;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Container<T>& container)
{
    os << "[";
    for (size_t i = 0; i < container.size_; i++)
    {
        os << container.array_[i];
        if (i != container.size_ - 1)
        {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

template<class U>
void swap(Container<U>& a, Container<U>& b) noexcept {
    std::swap(a.array_, b.array_);
    std::swap(a.capacity_, b.capacity_);
    std::swap(a.size_, b.size_);
}

//Конструктор копирования
template <typename T>
Container<T>::Container(const Container<T> &other)
{
    array_ = new T **[other.capacity_];
    capacity_ = other.capacity_;
    size_ = other.size_;
    for (size_t i = 0; i < other.size_; i++)
    {
        *array_[i] = *other.array_[i];
    }
}

// Конструктор перемещения
template <typename T>
Container<T>::Container(Container<T> &&other) noexcept : 
    Container<T>() //May not work on some machines
{
    swap(*this, other);
}

// Оператор присваивания копированием
template<typename T>
Container<T>& Container<T>::operator=(const Container<T>& other) noexcept {
    Container<T> temp(other);
    swap(*this, temp);
    return *this;
}

// Оператор присваивания перемещением
template<typename T>
Container<T>& Container<T>::operator=(Container<T>&& other) noexcept {
    swap(*this, other);
    return *this;
}

template<typename T>
void Container<T>::push(T rhs){
    if (capacity_ == size_) {
		capacity_ *= OVERFLOW_MULTIPLIER;
		T** temp = new T * [capacity_];
		for (size_t i = 0; i < size_; i++) {
			temp[i] = array_[i];
		}
		delete[] array_;
		array_ = temp;
	}
	array_[size_] = new T();
	*(array_[size_]) = rhs;
	++size_;
}
