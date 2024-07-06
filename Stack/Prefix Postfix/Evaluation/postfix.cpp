#include <iostream>
#include <stack>
#include <string>
using namespace std;

int evaluatePrefix(string s)
{
    stack<int> st;
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        if (ch >= '0' && ch <= '9') st.push(ch - '0');
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();
            switch (ch)
            {
            case '+':
                st.push(op1 + op2);
                break;
            case '-':
                st.push(op1 - op2);
                break;
            case '*':
                st.push(op1 * op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            }
        }
    }
    return st.top();
}

int main()
{
    cout << evaluatePrefix("54*62/-") << endl;
    return 0;
}
