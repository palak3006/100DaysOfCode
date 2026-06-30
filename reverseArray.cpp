// Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the reversed array, space-separated

// Example:
// Input:
// 5
// 1 2 3 4 5

// Output:
// 5 4 3 2 1

// Explanation: Swap pairs from both ends: (1,5), (2,4), middle 3 stays

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void reverseArray(vector<int> &arr)
{
    int i=0;
    int j = arr.size()-1;

    while(i != j)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

int main()
{
    int size;
    cout << "Enter size of the array: ";
    cin >> size;

    vector<int> arr(size);

    for(int i=0; i<arr.size(); i++)
    {
        cout << "Enter value for index " << i << " :";
        cin >> arr[i];
    }

    cout << "Array before Reverse:" << endl;

    for(int i=0; i<arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    cout <<endl;

    reverseArray(arr);

    cout << "Array after Reverse:" << endl;

    for(int i=0; i<arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    cout <<endl;

    return 0;

}