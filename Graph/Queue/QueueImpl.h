#pragma once

#include "Queue.h"
#include <iostream>

using namespace std;

template<typename T>
class QueueImpl : public Queue<T> {
public:
    void enqueue(T data) override;

    T dequeue() override;

    T peek() override;

    bool isEmpty() override;
};

template<typename T>
void QueueImpl<T>::enqueue(T data) {
    QueueNode<T> *newNode = new QueueNode<T>(data);
    if (this->isEmpty()) {
        this->front = this->rear = newNode;
    } else {
        this->rear->next = newNode;
        this->rear = newNode;
    }
}

template<typename T>
T QueueImpl<T>::dequeue() {
    if (this->isEmpty()) {
        cout << "Queue is empty\n";
        return T();
    }
    QueueNode<T> *temp = this->front;
    this->front = this->front->next;
    if (this->front == nullptr) {
        this->rear = nullptr;
    }
    T dequeuedData = temp->data;
    delete temp;
    return dequeuedData;
}

template<typename T>
T QueueImpl<T>::peek() {
    if (this->isEmpty()) {
        cout << "Queue is empty\n";
        return T();
    }
    return this->front->data;
}

template<typename T>
bool QueueImpl<T>::isEmpty() {
    return this->front == nullptr;
}
