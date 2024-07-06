#include <iostream>
#include <stack>
using namespace std;

int *nextGreaterElement(int arr[], int n)
{
    int *res = new int[n];
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        while(!s.empty() && arr[i] >= s.top()) s.pop();
        if(s.empty()) res[i] = -1;
        else res[i] = s.top();
        s.push(arr[i]);
    }
    return res;
}

int main()
{
    int arr[] = {4, 2, 7, 3, 1, 8, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int *nextGreater = nextGreaterElement(arr, n);
    cout << "Original array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    cout << "Next greater elements: ";
    for (int i = 0; i < n; i++) cout << nextGreater[i] << " ";
    cout << endl;
    delete[] nextGreater;
    return 0;
}