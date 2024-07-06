#include <iostream>
#include <stack>
#include <string>
using namespace std;

int prec(char c)
{
    if(c == '^') return 3;
    else if(c == '*' || c == '/') return 2;
    else if(c == '+' || c == '-') return 1;
    return -1;
}

void reverse(string &s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        st.push(s[i]);
    }
    s = "";
    while (!st.empty()) 
    {
        s += st.top();
        st.pop(); 
    }
}

string InfixToPrefix(string s)
{
    reverse(s);
    stack<char> st;
    string res;
    for (int i = 0; i < s.length(); i++) 
    {
       if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) res+=s[i];  // char k lye
       //if (isalnum(s[i])) res += s[i]; // digits k lye
       else if(s[i] == ')') st.push(s[i]);
       else if(s[i] == '(')
       {
           while(!st.empty() && st.top() != ')')
           {
               res+=st.top();
               st.pop();
           }
           if(!st.empty()) st.pop();
       }
       else
       {
           while(!st.empty() && prec(st.top()) > prec(s[i]))
           {
               res+=st.top();
               st.pop();
           }
           st.push(s[i]);
       }
    }
    while(!st.empty())
    {
        res+=st.top();
        st.pop();
    }
    reverse(res);
    return res;
}

int main()
{
    cout << InfixToPrefix("(a-b/c)*(a/k-l)");
    //cout << InfixToPrefix("6+3-5+8");
    return 0;
}