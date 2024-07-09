#include <iostream>
using namespace std;

void printKMax(int arr[], int N, int K)
{
    int j, max;
    for (int i = 0; i <= N - K; i++)
    {
        max = arr[i];
        for (j = 0; j < K; j++)
        {
            if (arr[i + j] > max) max = arr[i + j];
            cout << arr[i + j] << " ";
        }
        cout << ":- Max: " << max << endl;
    }
}

int main()
{
    int arr[] = {2, 5, 1, 9, 10, 6, 7, 18, 19, 0};
    int N = sizeof(arr) / sizeof(arr[0]);
    int K = 3;
    printKMax(arr, N, K);
    return 0;
}