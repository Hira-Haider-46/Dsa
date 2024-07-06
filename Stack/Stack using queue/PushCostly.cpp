#include <iostream>
#include <queue>
using namespace std;

template <class T>
class Stack
{
private:
    queue<T> q1;
    queue<T> q2;
    int n;

public:
    Stack() : n(0) {}
    void push(T value);
    T pop();
    T top();
    int size();
    ~Stack() {}
};

template <class T>
void Stack<T>::push(T value)
{
    q2.push(value);
    n++;
    while (!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }
    swap(q1, q2);
}


template <class T>
T Stack<T>::pop()
{
    if (!q1.empty())
    {
        T temp = q1.front();
        q1.pop();
        n--;
        return temp;
    }
    else cout << "Stack is empty" << endl;
    return T();
}

template <class T>
T Stack<T>::top()
{
    if (!q1.empty()) return q1.front();
    else cout << "Stack is empty" << endl;
    return T();
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
    cout << "Top element after push: " << st.top() << endl;
    st.push(2);
    cout << "Top element after push: " << st.top() << endl;
    st.push(3);
    cout << "Top element after push: " << st.top() << endl;
    st.push(4);
    cout << "Top element after push: " << st.top() << endl;
    st.push(5);
    cout << "Stack size: " << st.size() << endl;
    cout << "Top element: " << st.top() << endl;
    cout << "Popped element: " << st.pop() << endl;
    cout << "Top element after pop: " << st.top() << endl;
    cout << "Popped element: " << st.pop() << endl;
    cout << "Top element after pop: " << st.top() << endl;
    return 0;
}

