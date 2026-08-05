// Implement Heap Sort using a Max Heap to sort an array in ascending order. First build a max heap, then repeatedly extract the maximum element and place it at the end of the array.

#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>& arr, int n, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr)
{
    int n = arr.size();

    // Build Max Heap
    for(int i = n/2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // Heap Sort
    for(int i = n-1; i > 0; i--)
    {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}

int main()
{
    vector<int> arr = {4,10,3,5,1};

    heapSort(arr);

    for(int x : arr)
        cout << x << " ";

    return 0;
}