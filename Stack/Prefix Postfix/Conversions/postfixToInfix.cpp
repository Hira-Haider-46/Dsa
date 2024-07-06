#include <iostream>
#include <string>
#include <stack>
using namespace std;

void reverse(string &s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++) st.push(s[i]);
    s = "";
    while (!st.empty()) 
    {
        s += st.top();
        st.pop(); 
    }
}

string postfixToInfix(string s)
{
    stack<string> st;
    string op1, op2, res;
    for (int i = 0; i < s.length(); i++)
    {
        if(isalnum(s[i]))
        {
            string op(1,s[i]);
            st.push(op);
        }
        else
        {
            op1 = st.top();
            st.pop();
            op2 = st.top();
            st.pop();
            res = ")" + op1 + s[i] + op2 + "(";
            st.push(res);
        }
    }
    reverse(st.top());
    return st.top();
}

int main()
{
    cout << postfixToInfix("ab-cd/+e+f-") << endl;
    return 0;
}