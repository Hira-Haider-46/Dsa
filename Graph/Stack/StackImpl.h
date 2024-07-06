#pragma once

#include "Stack.h"
#include <iostream>

using namespace std;

template<typename T>
class StackImpl : public Stack<T> {
public:
    void push(T data) override;
    T pop() override;
    T peek() override;
    bool isEmpty() override;
};

template<typename T>
void StackImpl<T>::push(T data) {
    StackNode<T>* newNode = new StackNode<T>(data);
    newNode->next = this->top;
    this->top = newNode;
}

template<typename T>
T StackImpl<T>::pop() {
    if (this->isEmpty()) {
        cout << "Stack is empty\n";
        return T();
    }
    StackNode<T>* temp = this->top;
    this->top = this->top->next;
    T poppedData = temp->data;
    delete temp;
    return poppedData;
}

template<typename T>
T StackImpl<T>::peek() {
    if (this->isEmpty()) {
        cout << "Stack is empty\n";
        return T();
    }
    return this->top->data;
}

template<typename T>
bool StackImpl<T>::isEmpty() {
    return this->top == nullptr;
}
