#include <iostream>
using namespace std;

template <class T>
class Stack
{
protected:
    T *arr;
    int max;
    int top;

public:
    Stack() : max(5), top(-1)
    {
        arr = new T[max];
    }
    virtual void push(T value) = 0;
    virtual T pop() = 0;
    ~Stack()
    {
        delete[] arr;
    }
};

template <class T>
class MyStack : public Stack<T>
{
public:
    MyStack() : Stack<T>() {}
    void push(T value);
    T pop();
    bool isEmpty();
    bool isFull();
    int size();
    T peek();
    void display();
    void reverse(MyStack<T> &s);
    ~MyStack() {}
};

template <class T>
void MyStack<T>::push(T value)
{
    if (!isFull()) Stack<T>::arr[++(Stack<T>::top)] = value;
    else cout << "Stack is full" << endl;
}

template <class T>
T MyStack<T>::pop()
{
    if (!isEmpty()) return Stack<T>::arr[(Stack<T>::top)--];
    cout << "Stack is empty" << endl;
    return T();
}

template <class T>
bool MyStack<T>::isEmpty()
{
    return Stack<T>::top < 0;
}

template <class T>
bool MyStack<T>::isFull()
{
    return Stack<T>::top >= Stack<T>::max - 1;
}

template <class T>
int MyStack<T>::size()
{
    return Stack<T>::top + 1;
}

template <class T>
T MyStack<T>::peek()
{
    if (!isEmpty()) return Stack<T>::arr[Stack<T>::top];
    return T();
}

template <class T>
void MyStack<T>::display()
{
    if (!isEmpty())
    {
        cout << "Stack values" << endl;
        for (int i = 0; i < MyStack<T>::size(); i++) cout << Stack<T>::arr[i] << " ";
        cout << endl;
    }
    else cout << "Stack is empty" << endl;
}

template <class T>
void MyStack<T>::reverse(MyStack<T> &s)
{
    MyStack<T> temp;
    MyStack<T> temp1;
    while(!s.isEmpty()) temp.push(s.pop());
    while (!temp.isEmpty()) temp1.push(temp.pop());
    while (!temp1.isEmpty()) s.push(temp1.pop());
}


int main()
{
    MyStack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.display();
    cout << "Popping one element: " << stack.pop() << endl;
    cout << "Popping one element: " << stack.pop() << endl;
    stack.display();
    stack.reverse(stack);
    stack.display();
    if (stack.isEmpty()) cout << "Stack is empty" << endl;
    else cout << "Stack is not empty" << endl;
    cout << "Top element of the stack: " << stack.peek() << endl;
    cout << "Size of the stack: " << stack.size() << endl;
    return 0;
}
