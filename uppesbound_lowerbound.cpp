// Problem: Given a sorted array of integers and a target value x, implement the Lower Bound and Upper Bound operations using Binary Search.

// Lower Bound: The index of the first element in the array that is greater than or equal to x.
// Upper Bound: The index of the first element in the array that is strictly greater than x.

// Input:
// - First line: integer n representing the size of the array
// - Second line: n space-separated sorted integers
// - Third line: integer x (the target value)

// Output:
// - Print two integers:
//   1) Index of the lower bound of x
//   2) Index of the upper bound of x

// Example:
// Input:
// 7
// 1 2 4 4 4 5 7
// 4

// Output:
// 2 5

// Explanation:
// For the given array [1, 2, 4, 4, 4, 5, 7] and x = 4:
// - The lower bound is at index 2, which is the first occurrence of 4.
// - The upper bound is at index 5, which is the first element greater than 4 (i.e., 5).
// Binary Search is used to find both bounds efficiently in O(log n) time.

#include<bits/stdc++.h>
using namespace std;

int lowerbound(vector<int>&arr, int target)
{
    int s =0;
    int e = arr.size()-1;
    int ans = arr.size();

    while(s <= e)
    {
        int mid = (s+e)/2;

        if(arr[mid] >= target)
        {
            ans= mid;
            e = mid - 1; //to check ki jo index hume mila h ye first occurence hi h target ki ni
        }

        else
        {
            s = mid + 1;
        }
    }

    return ans;
}

int upperbound(vector<int>&arr, int target)
{
    int s =0;
    int e = arr.size()-1;
    int ans = arr.size();

    while(s <= e)
    {
        int mid = (s+e)/2;

        if(arr[mid] > target)
        {
            ans = mid;
            e = mid - 1; //to check ki jo index hume mila h kya yahi first greater element h ya nhi
        }

        else
        {
            s = mid + 1;
        }
    }

    return ans;
}

int main()
{
   int size;
   cin >> size;

   vector<int> arr;

   for(int i=0; i<size; i++)
   {
    int x;
    cin >> x;

    arr.push_back(x);
   }

   int target;
   cin >> target;

   cout << lowerbound(arr,target) << " " << upperbound(arr,target) << endl;

   return 0;

}