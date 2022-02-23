#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <string>

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

    void push(T);	// добавление элемента в стек
    T drop();		// извлечение элемента из стека

    void print(std::ostream &) const;
    std::string print() const;

    bool isEmpty() const;

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

template <class T>
bool Stack<T>::isEmpty() const{
    return !head_;
}

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
void Stack<T>::push(T val)
{
    node_t *newNode = new node_t;
    newNode->data = val;
    newNode->next = head_;
    head_ = newNode;
}

// метод, извлекающий значение из стека;
// извлекаемое значение возвращается функцией, элемент при этом удаляется из стека
template <class T>
T Stack<T>::drop()
{
    if (!head_)
    {
        throw std::logic_error("Stack is empty");
    }
    T res = head_->data;
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
    stream << "[ ";
    while (temp)
    {
        stream << temp->data << "  ";
        temp = temp->next;
    }
    stream << "]";
}

//Возвращение строчного представления (для логов в тестах Catch2)
template <class T>
std::string Stack<T>::print() const
{
    std::string res = "[ ";
    node_t* temp = head_;
    while (temp){
        // Не используем sstream, чтобы не задействовать лишние библиотеки.
        res.append(std::to_string(temp->data));
        res.append(" ");
        temp = temp->next;
    }
    res.append("]");
    return res;
}
#endif