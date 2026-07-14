// Problem: Given an array of integers, rotate the array to the right by k positions.

// Input:
// - First line: integer n
// - Second line: n integers
// - Third line: integer k

// Output:
// - Print the rotated array

// Example:
// Input:
// 5
// 1 2 3 4 5
// 2

// Output:
// 4 5 1 2 3

#include<bits/stdc++.h>
using namespace std;

void reverse(vector<int>& arr, int left, int right)
{
    while(left < right)
    {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

void rotateArray(vector<int>& arr, int k)
{
    int n = arr.size();

    k = k % n;

    reverse(arr, 0, n-1);

    reverse(arr, 0, k-1);

    reverse(arr, k, n-1);
}

int main()
{
    int n,k;
    cout <<"Enter size: ";
    cin >> n;
    cout <<"Enter number by how which array has to be rotated: ";
    cin >> k;


    vector<int> arr(n);

    for(int i=0; i<n; i++)
        cin >> arr[i];

    

    rotateArray(arr, k);

    for(int x : arr)
        cout << x << " ";
}