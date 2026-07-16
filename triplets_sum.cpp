// Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

// Input:
// - First line: integer n
// - Second line: n integers

// Output:
// - Print the count of subarrays having sum zero

// Example:
// Input:
// 6
// 1 -1 2 -2 3 -3

// Output:
// 6

// Explanation: A subarray is a continuous part of the array. For the input array 1 -1 2 -2 3 -3, the following subarrays have sum zero: [1, -1], [2, -2], [3, -3], [1, -1, 2, -2], [2, -2, 3, -3], and [1, -1, 2, -2, 3, -3]. Since there are 6 such subarrays, the output is 6.

#include<bits/stdc++.h>
using namespace std;

int countZeroSumSubarrays(vector<int>& arr)
{
    unordered_map<int,int> mp;

    int prefixSum = 0;
    int count = 0;

    // Important: prefix sum 0 exists before starting
    mp[0] = 1;

    for(int i = 0; i < arr.size(); i++)
    {
        prefixSum += arr[i];

        // If this prefix sum was seen before
        if(mp.find(prefixSum) != mp.end())
        {
            count += mp[prefixSum];
        }

        // Store/update frequency
        mp[prefixSum]++;
    }

    return count;
}


int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Number of zero sum subarrays: "
         << countZeroSumSubarrays(arr);

    return 0;
}