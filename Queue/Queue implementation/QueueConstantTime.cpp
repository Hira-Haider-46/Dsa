#include <iostream>
using namespace std;

template <class T>
class Queue
{
protected:
    T *arr;
    int front;
    int back;
    int max;

public:
    Queue() : front(-1), back(-1), max(5)
    {
        arr = new T[max];
    }
    virtual void enqueue(T value) = 0;
    virtual T dequeue() = 0;
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
    T dequeue();
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
    return Queue<T>::front < 0 || (Queue<T>::front > Queue<T>::back);
}

template <class T>
void MyQueue<T>::enqueue(T value)
{
    if (Queue<T>::front == -1)
    {
        Queue<T>::arr[++(Queue<T>::back)] = value;
        (Queue<T>::front)++;
        return;
    }
    if (!isFull()) Queue<T>::arr[++(Queue<T>::back)] = value;
    else cout << "Queue is full cannot enqueue more values" << endl;
}

template <class T>
T MyQueue<T>::dequeue()
{
    if(!isEmpty() && Queue<T>::front == Queue<T>::back)
    {
        T temp = Queue<T>::arr[(Queue<T>::front)];
        Queue<T>::front = Queue<T>::back = -1;
        return temp;
    }
    if(!isEmpty()) return Queue<T>::arr[(Queue<T>::front)++];
    else
    {
        cout << "Queue is empty cannot dequeue more values" << endl;
        return T();
    }
}

template <class T>
T MyQueue<T>::peek()
{
    if(!isEmpty()) return Queue<T>::arr[(Queue<T>::front)];
    else cout << "Queue is empty cannot display peek value" << endl;
}

template <class T>
int MyQueue<T>::size()
{
    if(Queue<T>::front == -1) return 0;
    return (Queue<T>::back - Queue<T>::front) + 1;
}

template <class T>
void MyQueue<T>::display()
{
    if(!isEmpty())
    {
        cout << "Queue Values" << endl;
        for (int i = Queue<T>::front; i <= Queue<T>::back; i++) cout << Queue<T>::arr[i] << " ";
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
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Size of queue after dequeue: " << q.size() << endl;
    q.display();
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    cout << "Size of queue: " << q.size() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    q.display();
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    q.display();
    cout << "Size of queue: " << q.size() << endl;
    return 0;
}
