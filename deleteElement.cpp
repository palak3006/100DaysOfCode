// Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer pos (1-based position to delete)

// Output:
// - Print the updated array with (n-1) elements, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 10 30 40 50

// Explanation: Delete position 2 (element 20), remaining elements shift left

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int size;
    cout << "Enter size of Array: ";
    cin >> size;

    vector<int> arr(size);

    for(int i=0; i<size; i++)
    {
        cout << "Enter value for index " << i << ":";
        cin >> arr[i];
    }

    cout << "Array: " << endl;

    for(int i = 0; i<arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int newIndex;
    cout << " Enter index to delete: ";
    cin >> newIndex;

    for(int j = newIndex; j < arr.size(); j++)
    {
        arr[j] = arr[j+1];
    }

    arr.resize(size-1);

    cout <<"Updated Array after deleting element at index: " << newIndex << endl;

    for(int k = 0; k<arr.size(); k++)
    {
        cout << arr[k] << " ";
    }

    return 0;
    
}