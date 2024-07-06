#include <iostream>
#include <queue>
using namespace std;

bool search(queue<int> q, int key)
{
    queue<int> temp;
    bool found = false;
    while(!q.empty())
    {
        if(q.front() == key) found = true;
        temp.push(q.front());
        q.pop();
    }
    while(!temp.empty())
    {
        q.push(temp.front());
        temp.pop();
    }
    return found;
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout << "Found or not: " << search(q,5) << endl;
    cout << "Found or not: " << search(q,1) << endl;
    cout << "Found or not: " << search(q,2) << endl;
    cout << "Found or not: " << search(q,3) << endl;
    cout << "Found or not: " << search(q,4) << endl;
    return 0;
}