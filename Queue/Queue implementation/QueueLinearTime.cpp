#include <iostream>
using namespace std;

template <class T>
class Queue
{
protected:
    T *arr;
    int back;
    int max;

public:
    Queue() : back(-1), max(5)
    {
        arr = new T[max];
    }
    virtual void enqueue(T value) = 0;
    virtual void dequeue() = 0;
    virtual ~Queue()
    {
        delete[] arr;
    }
};

template <class T>
class MyQueue : public Queue<T>
{
public:
    MyQueue() {}
    bool isFull();
    bool isEmpty();
    void enqueue(T value);
    void dequeue();
    T peek();
    int size();
    void display();
    ~MyQueue() {}
};

template <class T>
bool MyQueue<T>::isFull()
{
    return Queue<T>::back >= Queue<T>::max - 1;
}

template <class T>
bool MyQueue<T>::isEmpty()
{
    return Queue<T>::back < 0;
}

template <class T>
void MyQueue<T>::enqueue(T value)
{
    if (!isFull()) Queue<T>::arr[++(Queue<T>::back)] = value;
    else cout << "Queue is full cannot enqueue more values" << endl;
}

template <class T>
void MyQueue<T>::dequeue()
{
    if(!isEmpty())
    {
        cout << Queue<T>::arr[0] << " is dequeued from index 0" << endl;
        Queue<T>::back--;
        if(!isEmpty())
        {
            for (int i = 0; i <= Queue<T>::back; i++) Queue<T>::arr[i] = Queue<T>::arr[i + 1];
        }
    }
    else cout << "Queue is empty cannot dequeue more values" << endl;
}

template <class T>
T MyQueue<T>::peek()
{
    return Queue<T>::arr[0];
}

template <class T>
int MyQueue<T>::size()
{
    return (Queue<T>::back) + 1;
}

template <class T>
void MyQueue<T>::display()
{
    if(!isEmpty())
    {
        cout << "Queue Values" << endl;
        for (int i = 0; i <= Queue<T>::back; i++) cout << Queue<T>::arr[i] << " ";
        cout << endl;
    }
    else cout << "Queue is Empty cannot display values" << endl;
}

int main()
{
    MyQueue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    cout << "Size of queue: " << q.size() << endl;
    cout << "Front element: " << q.peek() << endl;
    q.dequeue();
    cout << "Size of queue after dequeue: " << q.size() << endl;
    q.display();
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    cout << "Size of queue: " << q.size() << endl;
    q.dequeue();
    q.dequeue();
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();
    cout << "Size of queue: " << q.size() << endl;
    return 0;
}