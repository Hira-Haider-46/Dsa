#include <iostream>
using namespace std;

void MaxHeapify(int arr[], int i, int N)
{
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int root = i;
	if (l < N && arr[l] > arr[root]) root = l;
	if (r < N && arr[r] > arr[root]) root = r;
	if (root != i) 
	{
		swap(arr[i], arr[root]);
		MaxHeapify(arr, root, N);
	}
}

void convertMaxHeap(int arr[], int N)
{
	for (int i = (N - 2) / 2; i >= 0; --i) MaxHeapify(arr, i, N);
}

void printArray(int* arr, int size)
{
	for (int i = 0; i < size; ++i) cout << arr[i] << " ";
}

int main()
{
	int arr[] = { 3, 5, 9, 6, 8, 20, 10, 12, 18, 9 };
	int N = sizeof(arr) / sizeof(arr[0]);
	cout << "Min Heap array : ";
	printArray(arr, N);
	convertMaxHeap(arr, N);
	cout << "\nMax Heap array : ";
	printArray(arr, N);
	return 0;
}