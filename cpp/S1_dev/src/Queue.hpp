#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <string>

template <class T>
class Queue
{
public:
    Queue();
    Queue(const Queue &);
    Queue(Queue &&) noexcept;
    ~Queue();
    Queue &operator=(const Queue &);
    Queue &operator=(Queue &&) noexcept;

    void swap(Queue &) noexcept;

    void push(T);
    T drop();

    void print(std::ostream &) const;
    std::string print() const;

    bool isEmpty() const;
    T peek() const;

private:
    struct node_t
    {
        T data;
        node_t *next;
    };

    node_t *head_;
    node_t *tail_;
};

template <class T>
Queue<T>::Queue() : head_(nullptr),
                    tail_(nullptr)
{
}

template <class T>
bool Queue<T>::isEmpty() const
{
    return !head_;
}

/*
 конструктор копирования
 кода объект класса содержит в себе какой-либо
 внешний ресурс (например, динамически выделенную память),
 необходимо(!) реализовать (или запретить) конструктор
 копирования, оператор присвивания и деструктор
 в C++11 желательно также определить конструктор
 перемещения и оператор перемещающего присваивания
*/
template <class T>
Queue<T>::Queue(const Queue<T> &queue) : head_(nullptr),
                                         tail_(nullptr)
{

    Queue<T> temp;
    node_t *src = queue.head_;
    while (src)
    {
        temp.push(src->data);
        src = src->next;
    }
    swap(temp);
}

template <class T>
Queue<T>::Queue(Queue<T> &&queue) noexcept : head_(nullptr),
                                             tail_(nullptr)
{
    swap(queue);
}

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

template <class T>
Queue<T> &Queue<T>::operator=(const Queue<T> &queue)
{

    if (this == &queue)
    {
        return *this;
    }

    Queue<T> tempQueue(queue);

    swap(tempQueue);

    return *this;
}

template <class T>
Queue<T> &Queue<T>::operator=(Queue<T> &&queue) noexcept
{
    swap(queue);
    return *this;
}

template <class T>
void Queue<T>::swap(Queue<T> &queue) noexcept
{
    std::swap(head_, queue.head_);
    std::swap(tail_, queue.tail_);
}

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

template <class T>
void Queue<T>::print(std::ostream &stream) const
{
    node_t *temp = head_;
    while (temp)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}

template <class T>
std::string Queue<T>::print() const
{
    std::string res = "[ ";
    node_t *temp = head_;
    while (temp)
    {
        res.append("" + temp->data);
        res.append(" ");
        temp = temp->next;
    }
    res.append("]");
    return res;
}

template <class T>
T Queue<T>::peek() const
{
    return head_->data;
}

#endif
