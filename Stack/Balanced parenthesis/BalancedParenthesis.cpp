#include <iostream>
#include <stack>
using namespace std;

bool isValid(char *s)
{
    stack<char> stack;
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') stack.push(s[i]);
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            if (stack.empty() || (s[i] == ')' && stack.top() != '(') || (s[i] == ']' && stack.top() != '[') || (s[i] == '}' && stack.top() != '{')) return false;
            stack.pop();
        }
        i++;
    }
    return stack.empty();
}

int main()
{
    char s[] = "((a+c)+b)";
    if (isValid(s)) cout << "Valid" << endl;
    else cout << "Invalid" << endl;
    return 0;
}