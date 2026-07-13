// Problem: Write a program to find the maximum and minimum values present in a given array of integers.

// Input:
// - First line: integer n
// - Second line: n integers

// Output:
// - Print the maximum and minimum elements

// Example:
// Input:
// 6
// 3 5 1 9 2 8

// Output:
// Max: 9
// Min: 1

#include<bits/stdc++.h>
using namespace std;

// void max_min(vector<int>&num)
// {
//     sort(num.begin(), num.end());
// }
// int main()
// {
//     int n;
//     cout <<"Enter size: ";
//     cin >> n;

//     vector<int> arr(n);
//     for(int i=0; i<n; i++)
//     {
//         cin >> arr[i];
//     }

//     max_min(arr);
//     cout <<"Max and Min element are: " << arr[n-1] << "," << arr[0];
//     return 0;
// }

//OR

int main()
{

    int n;
    cout <<"Enter size: ";
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
int maxi = arr[0];
int mini = arr[0];

for(int i = 1; i < arr.size(); i++)
{
    maxi = max(maxi, arr[i]);
    mini = min(mini, arr[i]);
}

cout << "Max: " << maxi << endl;
cout << "Min: " << mini << endl;

return 0;
}