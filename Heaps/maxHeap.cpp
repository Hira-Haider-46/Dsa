#include <iostream>
using namespace std;

// Max heap (largest value stored in root) is used to sort data in ascending order
class heaps
{
private:
    int arr[100];
    int size;

public:
    heaps()
    {
        arr[0] = -1;
        size = 0;
    }
    void insert(int value)
    {
        size++;
        int index = size;
        arr[index] = value;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else return;
        }
    }

    void remove()
    {
        if (size == 0) return;
        arr[1] = arr[size];
        size--;
        int i = 1;
        while (i <= size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;
            int parent = i;
            if (leftIndex <= size && arr[parent] < arr[leftIndex]) parent = leftIndex;
            if (rightIndex <= size && arr[parent] < arr[rightIndex]) parent = rightIndex;
            if (parent != i)
            {
                swap(arr[i], arr[parent]);
                i = parent;
            }
            else return;
        }
    }
    void display()
    {
        cout << "Max Heap: ";
        for (int i = 1; i <= size; i++) cout << arr[i] << " ";
        cout << endl;
    }
    ~heaps() {}
};

void heapify(int arr[], int n, int i)
{
    int parent = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[parent]) parent = left;
    if (right < n && arr[right] > arr[parent]) parent = right;
    if (parent != i)
    {
        swap(arr[i], arr[parent]);
        heapify(arr, n, parent);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    // heaps h;
    // h.insert(50);
    // h.insert(55);
    // h.insert(53);
    // h.insert(52);
    // h.insert(54);
    // h.display();
    // h.remove();
    // h.remove();
    // h.display();
    int arr[8] = {54, 53, 55, 52, 50, 60, 19, 20};
    heapSort(arr, 8);
    cout << "Sorted array(ascending order): ";
    for (int i = 0; i < 8; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}