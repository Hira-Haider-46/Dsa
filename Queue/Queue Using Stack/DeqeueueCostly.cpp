#include <iostream>
#include <stack>
using namespace std;

class Queue
{
protected:
    stack<int> s1;
    stack<int> s2;

public:
    Queue() {}
    void enqueue(int value);
    int dequeue();
    bool empty();
    ~Queue() {}
};

void Queue::enqueue(int value)
{
    s1.push(value);
}

int Queue::dequeue()
{
    if(s1.empty() && s2.empty())
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    if(s2.empty())
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    int val = s2.top();
    s2.pop();
    return val;
}

bool Queue::empty()
{
    return s1.empty() && s2.empty();
}

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    return 0;
}