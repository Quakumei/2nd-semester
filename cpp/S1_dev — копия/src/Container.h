#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>



template<class T>
class Container{
    public:
        //Конструктор
        Container();

        // Деструктор
        virtual ~Container();

        // Конструктор копирования
        // Создать копию объекта
        Container(const Container<T>& other);

        // Конструктор перемещения
        // Взять данные
        Container(Container<T>&& other) noexcept;

        // Оператор присваивания копированием
        Container<T>& operator=(const Container<T>& other) noexcept;

        // Оператор присваивания перемещением
        Container<T>& operator=(Container<T>&& other) noexcept;

        // Оператор вывода
        template <class U>
        friend std::ostream& operator<< (std::ostream&, const Container<U>&);

        // TODO: Должен ли swap иметь noexcept? 
        template <class U>
        friend void swap(Container<U>&, Container<U>&) noexcept;

        
        virtual void push(T rhs);
        virtual T drop() = 0;
    private: 
        static const int OVERFLOW_MULTIPLIER = 2;
        
        T** array_;
        size_t size_;
        size_t capacity_;

};
#endif