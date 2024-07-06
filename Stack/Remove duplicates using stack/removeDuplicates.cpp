#include <iostream>
#include <stack>
using namespace std;

int search(stack<int> s, int key)
{
    stack<int> temp;
    bool found = false;
    while (!s.empty())
    {
        if (s.top() == key) found = true;
        temp.push(s.top());
        s.pop();
    }
    while (!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }
    return found;
}

void removeDuplicates(stack<int> &s)
{
    stack<int> temp;
    while (!s.empty())
    {
        int current = s.top();
        s.pop();
        if (!search(temp, current)) temp.push(current);
    }
    while (!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }
}

void display(stack<int> s)
{
    cout << "Stack values: ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(1);
    s.push(1);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(2);
    s.push(4);
    s.push(2);
    s.push(4);
    display(s);
    removeDuplicates(s);
    display(s);
    return 0;
}