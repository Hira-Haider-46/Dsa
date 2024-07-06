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
    void display();
    ~MyQueue() {}
};

template <class T>
bool MyQueue<T>::isFull()
{
    return (Queue<T>::front == (Queue<T>::back + 1) % Queue<T>::max);
}

template <class T>
bool MyQueue<T>::isEmpty()
{
    return (Queue<T>::front < 0);
}

template <class T>
void MyQueue<T>::enqueue(T value)
{
    if (!isFull())
	{
		if (Queue<T>::front == -1) Queue<T>::front = 0;
		Queue<T>::back = (Queue<T>::back + 1) % Queue<T>::max;
		Queue<T>::arr[Queue<T>::back] = value;
		cout << Queue<T>::arr[Queue<T>::back] << " is enqueued at index " << Queue<T>::back << endl;
	}
	else cout << "Queue is Full\n";
}

template <class T>
T MyQueue<T>::dequeue()
{
    if (!isEmpty())
	{
		T val = Queue<T>::arr[Queue<T>::front];
		if (Queue<T>::front == Queue<T>::back) Queue<T>::front = Queue<T>::back = -1;
		else Queue<T>::front = (Queue<T>::front + 1) % Queue<T>::max;
		return val;
	}
    cout << "Queue is Empty\n";
	return T();
}

template <class T>
T MyQueue<T>::peek()
{
    return Queue<T>::arr[(Queue<T>::front)];
}

template <class T>
void MyQueue<T>::display()
{
    if (!isEmpty())
	{
		cout << "Front is " << Queue<T>::arr[Queue<T>::front] << endl;
		cout << "Elements of Queue\n";
		for (int i = Queue<T>::front; i != Queue<T>::back; i = (i + 1) % Queue<T>::max) cout << Queue<T>::arr[i] << " ";
		cout << Queue<T>::arr[Queue<T>::back] << endl;
		cout << "Back is " << Queue<T>::arr[Queue<T>::back] << endl;
	}
	else cout << "\nQueue is empty\n";
}

int main()
{
    MyQueue<int> queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    cout << endl;
    queue.display();
    cout << endl;
    cout << "Dequeued: " << queue.dequeue() << endl << endl;
    queue.display();
    return 0;
}