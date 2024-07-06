#include <iostream>
using namespace std;

void merge(int arr[], int s, int e, int mid)
{
    int l1 = mid - s + 1;
    int l2 = e - mid;
    int *left = new int[l1];
    int *right = new int[l2];
    int k = s;
    for (int i = 0; i < l1; i++) left[i] = arr[k++];
    k = mid + 1;    
    for (int i = 0; i < l2; i++) right[i] = arr[k++];  
    int i1 = 0, i2 = 0;
    k = s;
    while (i1 < l1 && i2 < l2)
    {
        if(left[i1] < right[i2]) arr[k++] = left[i1++];
        else arr[k++] = right[i2++];
    }
    while (i1 < l1) arr[k++] = left[i1++];    
    while (i2 < l2) arr[k++] = right[i2++];    
}

void mergeSort(int arr[], int s, int e)
{
    if (s >= e) return;
    int mid = s + (e - s) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, e, mid);
}

int main()
{
    int arr[] = {4, 7, 2, 6, 8, 2, 1, 5, 8, 10};
    mergeSort(arr, 0, 9);
    for (int i = 0; i < 10; i++) cout << arr[i] << " ";
    return 0;
}