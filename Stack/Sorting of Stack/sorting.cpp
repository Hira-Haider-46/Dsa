#include <iostream>
#include <stack>
using namespace std;

void sortStack(stack<int> &s)
{
    stack<int> temp;
    while(!s.empty())
    {
        int current = s.top();
        s.pop();
        while(!temp.empty() && temp.top() > current)
        {
            s.push(temp.top());
            temp.pop();
        }
        temp.push(current);
    }
    while(!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }
}

void displayStack(stack<int> s)
{
    cout << "Stack: ";
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
    s.push(30);
    s.push(5);
    s.push(18);
    s.push(14);
    s.push(3);
    displayStack(s);
    sortStack(s);
    displayStack(s);
    return 0;
}
