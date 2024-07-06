#pragma once

#include "QueueNode.h"

template<typename T>
class Queue {
protected:
    QueueNode<T> *front;
    QueueNode<T> *rear;

public:
    Queue();

    virtual ~Queue();

    virtual void enqueue(T data) = 0;

    virtual T dequeue() = 0;

    virtual T peek() = 0;

    virtual bool isEmpty() = 0;
};

template<typename T>
Queue<T>::Queue() : front(nullptr), rear(nullptr) {}

template<typename T>
Queue<T>::~Queue() {
    while (front != nullptr) {
        QueueNode<T> *temp = front;
        front = front->next;
        delete temp;
    }
}
