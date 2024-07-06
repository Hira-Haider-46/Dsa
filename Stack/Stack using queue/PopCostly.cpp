#include <iostream>
#include <queue>
using namespace std;

template <class T>
class Stack
{
private:
    queue<T> left;
    queue<T> right;
    int n;

public:
    Stack() : n(0) {}
    void push(T value);
    void pop();
    T top();
    int size();
    ~Stack() {}
};

template <class T>
void Stack<T>::push(T value)
{
    left.push(value);
    n++;
}


template <class T>
void Stack<T>::pop()
{
    if (left.empty())
    {
        cout << "Stack is empty" << endl;
        return;
    }
    while(left.size() != 1)
    {
        right.push(left.front());
        left.pop();
    }
    left.pop();
    n--;
    swap(left,right);
}

template <class T>
T Stack<T>::top()
{
    if (left.empty())
    {
        cout << "Stack is empty" << endl;
        return T();
    }
    while(left.size() != 1)
    {
        right.push(left.front());
        left.pop();
    }
    T ans = left.front();
    right.push(ans);
    swap(left,right);
    return ans;
}

template <class T>
int Stack<T>::size()
{
    return n;
}

int main()
{
    Stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << "Size of stack: " << st.size() << endl;
    cout << "Top element: " << st.top() << endl;
    st.pop();
    cout << "Top element: " << st.top() << endl;
    st.pop();
    cout << "Size of stack after popping: " << st.size() << endl;
    st.push(4);
    st.push(5);
    cout << "Size of stack: " << st.size() << endl;
    cout << "Top element: " << st.top() << endl;
    return 0;
}