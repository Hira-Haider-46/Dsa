#include <bits/stdc++.h>
using namespace std;

int kthLargestSum(int arr[], int N, int K)
{
    vector<int> result;
    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        for (int j = i; j < N; j++) sum += arr[j];
        result.push_back(sum);
    }
    // Sort in decreasing order use max heap
    sort(result.begin(), result.end(), greater<int>());
    return result[K - 1];
}

int main()
{
    int a[] = {20, -5, -1, 3, 11, 4, 6};
    int N = sizeof(a) / sizeof(a[0]);
    int K = 2;
    cout << kthLargestSum(a, N, K);
    return 0;
}