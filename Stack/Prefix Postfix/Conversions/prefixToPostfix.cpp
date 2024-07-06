// prefix -> infix -> postfix
#include <iostream>
#include <stack>
#include <string>
using namespace std;

// string prefixToInfix(string s)
// {
//     stack<string> st;
//     string op1, op2, res;
//     for (int i = s.length() - 1; i >= 0 ; i--)
//     {
//         if(isalnum(s[i]))
//         {
//             string op(1,s[i]);
//             st.push(op);
//         }
//         else
//         {
//             op1 = st.top();
//             st.pop();
//             op2 = st.top();
//             st.pop();
//             res = "(" + op1 + s[i] + op2 + ")";
//             st.push(res);
//         }
//     }
//     return st.top();
// }

// int prec(char c)
// {
//     if (c == '^')
//         return 3;
//     else if (c == '*' || c == '/')
//         return 2;
//     else if (c == '+' || c == '-')
//         return 1;
//     return -1;
// }

// string InfixToPostfix(string s) 
// {
//     stack<char> st;
//     string res;
//     for (int i = 0; i < s.length(); i++)
//     {
//         if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) res += s[i]; // characters k lye
//         //if (isalnum(s[i])) res += s[i]; digits k lye
//         else if (s[i] == '(')
//             st.push(s[i]);
//         else if (s[i] == ')')
//         {
//             while (!st.empty() && st.top() != '(')
//             {
//                 res += st.top();
//                 st.pop();
//             }
//             if (!st.empty())
//                 st.pop();
//         }
//         else
//         {
//             while (!st.empty() && (prec(st.top()) >= prec(s[i])))
//             {
//                 res += st.top();
//                 st.pop();
//             }
//             st.push(s[i]);
//         }
//     }
//     while (!st.empty())
//     {
//         res += st.top();
//         st.pop();
//     }
//     return res;
// }

// string prefixToPostfix(string s)
// {
//     string a = prefixToInfix(s);
//     return InfixToPostfix(a);
// }

// or

string prefixToPostfix(string s)
{
    stack<string> st;
    string op1, op2;
    for (int i = s.length() - 1; i >=0 ; i--)
    {
        if (isalnum(s[i]))
        {
            string op(1, s[i]);
            st.push(op);
        }
        else
        {
            op1 = st.top();
            st.pop();
            op2 = st.top();
            st.pop();
            st.push(op1 + op2 + s[i]);
        }
    }
    string ans = "";
    while (!st.empty()) 
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}

int main()
{
    cout << prefixToPostfix("-+ab*cde");
    // ab+cd*-e
    return 0;
}