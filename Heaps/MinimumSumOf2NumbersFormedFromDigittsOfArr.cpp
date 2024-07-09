#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int N)
{
    sort(arr, arr + N); // sort it by using min heap in ascending order  arr = 2,3,4,5,6,8
    int a = 0, b = 0;
    for (int i = 0; i < N; i++)
    {
        if (i % 2 == 0) b = b * 10 + arr[i];
        else a = a * 10 + arr[i];
    }
    return a + b;
}

int main()
{
    int arr[] = {6, 8, 4, 5, 2, 3};
    int N = sizeof(arr) / sizeof(arr[0]);
    cout << "Sum is " << solve(arr, N);
    return 0;
}