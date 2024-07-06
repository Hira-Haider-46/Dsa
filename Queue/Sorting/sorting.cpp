#include <iostream>
#include <queue>
using namespace std;

void mergeQueues(queue<int> &left, queue<int> &right, queue<int> &q)
{
    while (!left.empty() && !right.empty())
    {
        if (left.front() <= right.front())
        {
            q.push(left.front());
            left.pop();
        }
        else
        {
            q.push(right.front());
            right.pop();
        }
    }
    while (!left.empty())
    {
        q.push(left.front());
        left.pop();
    }
    while (!right.empty())
    {
        q.push(right.front());
        right.pop();
    }
}

void mergeSort(queue<int> &q)
{
    if (q.size() <= 1) return;
    queue<int> left, right;
    int halfSize = q.size() / 2;
    for (int i = 0; i < halfSize; ++i)
    {
        left.push(q.front());
        q.pop();
    }
    while (!q.empty())
    {
        right.push(q.front());
        q.pop();
    }
    mergeSort(left);
    mergeSort(right);
    mergeQueues(left, right, q);
}

void printQueue(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> myQueue;
    myQueue.push(5);
    myQueue.push(3);
    myQueue.push(8);
    myQueue.push(1);
    myQueue.push(4);
    printQueue(myQueue);
    mergeSort(myQueue);
    cout << "Sorted Queue: ";
    printQueue(myQueue);
    return 0;
}
