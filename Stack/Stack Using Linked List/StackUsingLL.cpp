#include <iostream>
using namespace std;

template<class T>
class Node
{
public:
    T data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int value) : data(value), next(nullptr) {}
    ~Node() {}
};

template<class T>
class Stack
{
protected:
    Node<T> *head;

public:
    Stack() : head(nullptr) {}
    Stack(T value) : Node<T>(value) {}
    void push(T value);
    void pop();
    int size();
    ~Stack() {}
};

template<class T>
void Stack<T>::push(T value) 
{
    Node<T> *n = new Node<T>(value);
    cout << n->data << " is pushed on stack" << endl;
    if(head == nullptr)
    {
        head = n;
        return;
    }
    Node<T> *temp = head;
    head = n;
    n->next = temp;
}

template<class T>
void Stack<T>::pop() 
{
    if(head == nullptr)
    {
        cout << "Already empty" << endl;
        return;
    }
    cout << head->data << " is popped from stack" << endl;
    Node<T> *temp = head->next;
    delete head;
    head = temp;
}

template <class T>
int Stack<T>::size()
{
    int count = 0;
    Node<T> *temp = head;
    while(temp != nullptr)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

int main()
{
    Stack<int> myStack;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    cout << endl;
    myStack.pop();
    myStack.pop();
    myStack.pop();
    cout << "\nSize of the stack: " << myStack.size() << endl;
    return 0;
}