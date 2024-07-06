#include <iostream>
#include <string>
#include <stack>
using namespace std;

string prefixToInfix(string s)
{
    stack<string> st;
    string op1, op2, res;
    for (int i = s.length() - 1; i >= 0 ; i--)
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
            res = "(" + op1 + s[i] + op2 + ")";
            st.push(res);
        }
    }
    return st.top();
}

int main()
{
    cout << prefixToInfix("/*+ab-cde") << endl;
    // ((a+b)*(c-d)/e) 
    return 0;
}