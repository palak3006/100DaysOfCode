// Problem Statement
// Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

// Input Format
// An integer array arr[].

// Output Format
// Print the length of the longest subarray with sum equal to zero.

// Sample Input
// 15 -2 2 -8 1 7 10 23

// Sample Output
// 5

// Explanation
// The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.

#include<bits/stdc++.h>
using namespace std;

int main()
{
    //{sum,index}
    unordered_map<int,int> mpp;

    int n;
    cin >> n;
    
    vector<int> element;
    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;

        element.push_back(x);
    }

    int sum = 0;
    int maxi = 0;

    for(int i=0; i<n; i++)
    {
        sum += element[i];
        
        if(sum == 0)
        maxi = i + 1;

        else if(mpp.find(sum) != mpp.end())
        {
            maxi = max(maxi, i - mpp[sum]);
        }

        else
        mpp[sum] = i;
    }

    cout << maxi;
    return 0;
}
