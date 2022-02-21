#include <iostream>

#ifndef STACK_H
#define STACK_H

// Стек - структура данных, работающая по принципу LIFO (Last In, First Out),
// т.е. элементы извлекаются из стека в порядке, обратном порядку их добавления.
// Ниже реализован стек целых чисел на базе связного списка
template<class T>
class Stack
{
public:
    Stack();

    // деструктор освобождает память, выделенную под список (вызывается неявно при уничтожении объекта);
    // кода объект содержит в себе какой-либо внешний ресурс (например, динамически выделенную память),
    // необходимо(!) реализовать (или запретить) конструктор копирования, оператор присвивания и деструктор,
    // в C++11 желательно также определить конструктор перемещения и оператор перемещающего присваивания
    ~Stack();

    void push(int);	// добавление элемента в стек
    int pop();		// извлечение элемента из стека

    void print(std::ostream &) const;

private:
    // структура, описывающая элемент стека
    struct node_t
    {
        T data;		// данные
        node_t *next;	// указатель на следующий элемент
    };

    // указатель на вершину стека
    node_t *head_;

    // для упрощения примера копирование и перемещение объектов запрещены
    Stack<T>(const Stack<T> &) = delete;
    Stack<T>(Stack<T> &&) = delete;
    Stack<T> & operator=(const Stack<T> &) = delete;
    Stack<T> & operator=(Stack<T> &&) = delete;
};

// конструктор
template <class T>
Stack<T>::Stack() :
    head_(nullptr)	// nullptr - пустой указатель (не указывает ни на какой адрес)
                    // устаревший аналог - NULL
{}

// деструктор
template <class T> Stack<T>::~Stack()
{
    while (head_)	// то же, что while (head_ != nullptr)
    {
        node_t *temp = head_;
        head_ = head_->next;
        // обязательно освобождаем память, выделенную под каждый элемент
        delete temp;
    }
}

// метод, помещающий значение в стек
template <class T>
void Stack<T>::push(int val)
{
    node_t *newNode = new node_t;
    newNode->data = val;
    newNode->next = head_;
    head_ = newNode;
}

// метод, извлекающий значение из стека;
// извлекаемое значение возвращается функцией, элемент при этом удаляется из стека
template <class T>
int Stack<T>::pop()
{
    if (!head_)
    {
        throw std::logic_error("Stack is empty");
    }
    int res = head_->data;
    node_t *temp = head_;
    head_ = head_->next;
    delete temp;
    return res;
}

// вывод всего стека на экран
template <class T>
void Stack<T>::print(std::ostream &stream) const
{
    node_t *temp = head_;
    while (temp)
    {
        stream << temp->data << "  ";
        temp = temp->next;
    }
}
#endif