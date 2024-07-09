#include<iostream>
using namespace std;

void heapify(int arr[], int N, int i)
{
    int root = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    // If left child is smaller than root
    if (l < N && arr[l] < arr[root]) root = l;
    // If right child is smaller than root so far
    if (r < N && arr[r] < arr[root]) root = r;
    // If root is not root
    if (root != i)
    {
        swap(arr[i], arr[root]);
        heapify(arr, N, root);
    }
}

// Function to build a Min-Heap from the given array
void buildHeap(int arr[], int N)
{
    // Index of last non-leaf node
    int startIdx = (N / 2) - 1;
    for (int i = startIdx; i >= 0; i--) heapify(arr, N, i);
}

void printHeap(int arr[], int N)
{
    cout << "Heap: ";
    for (int i = 0; i < N; ++i) cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    // Binary Tree Representation
    // of input array
    //                17
    //             /    \
    //           15      13
    //         /  \    /  \
    //       9     6  5   10
    //      / \   / \
    //     4   8 3   1
    int arr[] = {17, 15, 13, 9, 6, 5, 10, 4, 8, 3, 1};
    int N = sizeof(arr) / sizeof(arr[0]);
    buildHeap(arr, N);
    printHeap(arr, N);
    // Final Heap:
    //                1
    //             /    \
    //           3      5
    //         /  \    /  \
    //       4     6 13   10
    //      / \   / \
    //     9  8  15  17
    return 0;
}