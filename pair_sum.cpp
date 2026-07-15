// Problem: Given an array of integers, find two elements whose sum is closest to zero.

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the pair of elements whose sum is closest to zero

// Example:
// Input:
// 5
// 1 60 -10 70 -80

// Output:
// -10 1

// Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.

#include<bits/stdc++.h>
using namespace std;

pair<int,int> sumPair(vector<int>&nums)
{
    sort(nums.begin(), nums.end());
    
    int i=0;
    int j = nums.size()-1;

    int sum = 0;
    int bestSum = INT_MAX;

    pair<int,int> ans;

    while(i < j)
    {
        sum = nums[i] + nums[j];
        
        if(abs(sum) < abs(bestSum))
        {
            bestSum = sum;
            ans.first = nums[i];
            ans.second = nums[j];
        }

        if(sum < 0)
        i++;

        else 
        j--;
    }
    return ans;
}

int main()
{
    int size;
    cout <<"Enter size: ";
    cin >> size;

    vector<int> arr(size);
    for(int i=0; i<size; i++)
    {
        cout <<"Enter value for index " << i <<" :";
        cin >> arr[i];
    }

    pair<int,int> pair_sum = sumPair(arr);

    cout <<"pair of elements whose sum is closest to zero: " << pair_sum.first << " " << pair_sum.second;
    return 0;
}