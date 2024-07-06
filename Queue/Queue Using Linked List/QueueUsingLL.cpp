#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int value) : data(value), next(nullptr) {}
    ~Node() {}
};

class Queue
{
protected:
    Node *front;
    Node *back;

public:
    Queue() : front(nullptr), back(nullptr) {}
    void enqueue(int value);
    void dequeue();
    int peek();
    bool empty();
    ~Queue() {}
};

void Queue::enqueue(int value)
{
    // insert at back
    Node *n = new Node(value);
    cout << n->data << " is enqueued" << endl;
    if(front == nullptr)
    {
        back = n;
        front = n;
        return;
    }
    back->next = n;
    back = n;
}

void Queue::dequeue()
{
    // delete from front
    if(front == nullptr)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    else if(front == back)
    {
        cout << front->data << " is dequeued" << endl;
        front = back = nullptr;
        return;
    }
    cout << front->data << " is dequeued" << endl;
    Node *temp = front->next;
    delete front;
    front = temp;
}

int Queue::peek()
{
    if(front == nullptr)
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    return front->data;
}

bool Queue::empty()
{
    return front == nullptr;
}

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    cout << endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    return 0;
}