#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <string>


template <class T>
class Queue
{
public:
    Queue();
    Queue(const Queue &);                   // конструктор копирования
    Queue(Queue &&) noexcept;               // конструктор перемещения
    ~Queue();
    Queue & operator=(const Queue &);       // перегруженный оператор присваивания
    Queue & operator=(Queue &&) noexcept;   // перегруженный оператор перемещающего присваивания

    void swap(Queue &) noexcept;            // обмен двух очередей значениями (используется в операторе присваивания)

    void push(T);                          // добавить элемент в очередь
    T drop();                             // получить элемент из очереди

    void print(std::ostream &) const;
    std::string print() const;

    bool isEmpty() const;

private:
    struct node_t           // элемент очереди
    {
        T data;           // данные
        node_t *next;       // указатель на следующий элемент
    };

    node_t *head_;          // указатель на начало очереди
    node_t *tail_;          // указатель на конец очереди
};

template <class T>
Queue<T>::Queue() :
    head_(nullptr),
    tail_(nullptr)
{}

template <class T>
bool Queue<T>::isEmpty() const{
    return !head_;
}

// конструктор копирования
// кода объект класса содержит в себе какой-либо внешний ресурс (например, динамически выделенную память),
// необходимо(!) реализовать (или запретить) конструктор копирования, оператор присвивания и деструктор
// в C++11 желательно также определить конструктор перемещения и оператор перемещающего присваивания
template <class T>
Queue<T>::Queue(const Queue<T> &queue) :
    head_(nullptr),
    tail_(nullptr)
{
    // собираем копию очереди внутри временного объекта, чтобы не допустить утечки памяти
    // в случае возникновения исключения при выделени памяти под очередной элемент
    Queue<T> temp;
    node_t *src = queue.head_;
    while (src)
    {
        temp.push(src->data);
        src = src->next;
    }
    swap(temp);
}

// конструктор перемещения
template <class T>
Queue<T>::Queue(Queue<T> &&queue) noexcept :
    head_(nullptr),
    tail_(nullptr)
{
    swap(queue);
}

// деструктор
template <class T>
Queue<T>::~Queue()
{
    while (head_)
    {
        node_t *temp = head_;
        head_ = head_->next;
        delete temp;
    }
}

// оператор копирующего присваивания
template <class T>
Queue<T> & Queue<T>::operator=(const Queue<T> &queue)
{
    // если присваиваем объект самому себе, то делать ничего не нужно
    if (this == &queue)
    {
        return *this;
    }
    // создаём копию присваиваемой очереди
    Queue<T> tempQueue(queue);
    // меняем содержимое временной копии и контекстного объекта
    swap(tempQueue);
    // возвращаем ссылку на контекстный объект
    return *this;

    // временный объект tempQueue будет уничтожен при завершении метода
    // и его деструктор освободит память, занятую элементами изначальной очереди;
    // такой приём написания оператора присваивания называется copy-and-swap
}

// оператор перемещающего присваивания
template <class T>
Queue<T> & Queue<T>::operator=(Queue<T> &&queue) noexcept
{
    swap(queue);
    return *this;
}

// обмен значениями аргумента и контекстного объекта (просто меняем указатели)
template <class T>
void Queue<T>::swap(Queue<T> &queue) noexcept
{
    std::swap(head_, queue.head_);
    std::swap(tail_, queue.tail_);
}

// добавление элемента в очередь
template <class T>
void Queue<T>::push(T d)
{
    if (!head_)
    {
        head_ = tail_ = new node_t;
    }
    else
    {
        tail_->next = new node_t;
        tail_ = tail_->next;
    }
    tail_->data = d;
    tail_->next = nullptr;
}

// извлечение элемента из очереди
template <class T>
T Queue<T>::drop()
{
    if (!head_)
    {
        throw std::logic_error("Queue is empty");
    }
    T res = head_->data;
    node_t *temp = head_;
    if (head_ == tail_)
    {
        head_ = tail_ = nullptr;
    }
    else
    {
        head_ = head_->next;
    }
    delete temp;
    return res;
}

// вывод очереди на экран
template <class T>
void Queue<T>::print(std::ostream & stream) const
{
    node_t* temp = head_;
    while (temp)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}

//Возвращение строчного представления (для логов в тестах Catch2)
template <class T>
std::string Queue<T>::print() const
{
    std::string res = "[ ";
    node_t* temp = head_;
    while (temp){
        // Не используем sstream, чтобы не задействовать лишние библиотеки. А стринг его не импротит?
        res.append(std::to_string(temp->data));
        res.append(" ");
        temp = temp->next;
    }
    res.append("]");
    return res;
}

#endif
