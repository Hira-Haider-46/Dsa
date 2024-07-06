#include<iostream>
#include<stack>
using namespace std;

bool search(stack<int> s, int key)
{
    stack<int> temp;
    bool found = false;
    while(!s.empty())
    {
        if(s.top() == key) found = true;
        temp.push(s.top());
        s.pop();
    }
    while(!temp.empty())
    {
        s.push(temp.top());
        temp.pop();   
    }
    return found;
}

int main()
{
    stack<int> myStack;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    myStack.push(50);
    cout << search(myStack, 60);
    return 0;
}