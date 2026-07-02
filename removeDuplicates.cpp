// Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (sorted array)

// Output:
// - Print unique elements only, space-separated

// Example:
// Input:
// 6
// 1 1 2 2 3 3

// Output:
// 1 2 3

// Explanation: Keep first occurrence of each element: 1, 2, 3


#include<iostream>
#include<vector>
using namespace std;

void removeDuplicate(vector<int> &nums)
{
    int i = 0;
    int j = 1;

    while(i < nums.size() && j < nums.size())
    {
        if(nums[i] == nums[j])
        { 
            j++;
        }

        else 
        {
            i++;
            nums[i] = nums[j];
            j++;
        }
    }

    for(int k=0; k<=i; k++)
    {
        cout << nums[k] << " ";
    }
}

int main()
{
    int size;
    cout <<"Enter number of elements: ";
    cin >> size;

    vector<int> arr(size);

    for(int i=0; i<size; i++)
    {
        cout <<"Enter value for index " << i  <<" :";
        cin >> arr[i];
    }

    removeDuplicate(arr);

    
    return 0;
}