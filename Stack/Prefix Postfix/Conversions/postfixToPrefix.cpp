#include <iostream>
#include <string>
#include <stack>
using namespace std;

// // postfix -> infix -> prefix

// int prec(char c)
// {
//     if(c == '^') return 3;
//     else if(c == '*' || c == '/') return 2;
//     else if(c == '+' || c == '-') return 1;
//     return -1;
// }

// void reverse(string &s)
// {
//     stack<char> st;
//     for (int i = 0; i < s.length(); i++)
//     {
//         st.push(s[i]);
//     }
//     s = "";
//     while (!st.empty())
//     {
//         s += st.top();
//         st.pop();
//     }
// }

// string InfixToPrefix(string s)
// {
//     reverse(s);
//     stack<char> st;
//     string res;
//     for (int i = 0; i < s.length(); i++)
//     {
//        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) res+=s[i];  // char k lye
//        //if (isalnum(s[i])) res += s[i]; // digits k lye
//        else if(s[i] == ')') st.push(s[i]);
//        else if(s[i] == '(')
//        {
//            while(!st.empty() && st.top() != ')')
//            {
//                res+=st.top();
//                st.pop();
//            }
//            if(!st.empty()) st.pop();
//        }
//        else
//        {
//            while(!st.empty() && prec(st.top()) > prec(s[i]))
//            {
//                res+=st.top();
//                st.pop();
//            }
//            st.push(s[i]);
//        }
//     }
//     while(!st.empty())
//     {
//         res+=st.top();
//         st.pop();
//     }
//     reverse(res);
//     return res;
// }

// string postfixToInfix(string s)
// {
//     stack<string> st;
//     string op1, op2, res;
//     for (int i = 0; i < s.length(); i++)
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
//             res = ")" + op1 + s[i] + op2 + "(";
//             st.push(res);
//         }
//     }
//     reverse(st.top());
//     return st.top();
// }

// string postfixToPrefix(string s)
// {
//     string a = postfixToInfix(s);
//     return InfixToPrefix(a);
// }

// int main()
// {
//     cout << postfixToPrefix("ab-cd/+e+f-") << endl;
//     // -++-ab/cdef
//     return 0;
// }

// or

string postfixToPrefix(string s)
{
    stack<string> st;
    string op1, op2, res;
    for (int i = 0; i < s.length(); i++)
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
            res = s[i] + op2 + op1;
            st.push(res);
        }
    }
    // string ans = "";
    // while (!st.empty()) 
    // {
    //     ans += st.top();
    //     st.pop();
    // }
    // return ans;
    return st.top();
}

int main()
{
    cout << postfixToPrefix("abc/-ak/l-*");
    // *-a/bc-/akl
    return 0;
}