#include <iostream>
#include <stack>
#include <string>
using namespace std;

int prec(char c)
{
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    return -1;
}

string InfixToPostfix(string s) 
{
    stack<char> st;
    string res;
    for (int i = 0; i < s.length(); i++)
    {
        //if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) res += s[i]; // characters k lye
        if (isalnum(s[i])) res += s[i];
        else if (s[i] == '(') st.push(s[i]);
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        }
        else
        {
            while (!st.empty() && (prec(st.top()) >= prec(s[i])))
            {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    return res;
}

int main()
{
    cout << InfixToPostfix("3*5-1^6+(2^3)/6*3+2*5+1");
    // 35*16^-23^6/3*+25*+1+
    //cout << endl << InfixToPostfix("a+b+c");
    //abc++
    return 0;
}