#include "StackNode.h"
template<typename T>
class Stack {
protected:
    StackNode<T> *top;

public:
    Stack();

    virtual ~Stack();

    virtual void push(T data) = 0;

    virtual T pop() = 0;

    virtual T peek() = 0;

    virtual bool isEmpty() = 0;
};

template<typename T>
Stack<T>::Stack() : top(nullptr) {}

template<typename T>
Stack<T>::~Stack() {
    while (top != nullptr) {
        StackNode<T> *temp = top;
        top = top->next;
        delete temp;
    }
}
