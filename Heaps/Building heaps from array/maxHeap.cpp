#include<iostream>
using namespace std;

void heapify(int arr[], int N, int i)
{
	int root = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2; 
	if (l < N && arr[l] > arr[root]) root = l; // If left child is larger than root
	if (r < N && arr[r] > arr[root]) root = r; // If right child is larger than root so far
	if (root != i) 
    {
		swap(arr[i], arr[root]);
		heapify(arr, N, root);
	}
}

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
	//			 1
	//		 / \
	//		 3	 5
	//	 / \	 / \
	//	 4	 6 13 10
	// / \ / \
	// 9 8 15 17
	int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
	int N = sizeof(arr) / sizeof(arr[0]);
	buildHeap(arr, N);
	printHeap(arr, N);
	// Final Heap:
	//			 17
	//		 / \
	//		 15	 13
	//		 / \	 / \
	//	 9	 6 5 10
	//	 / \ / \
	//	 4 8 3 1
	return 0;
}