// Problem: Given an array of integers, count the frequency of each distinct element and print the result.

// Input:
// - First line: integer n (size of array)
// - Second line: n integers

// Output:
// - Print each element followed by its frequency in the format element:count

// Example:
// Input:
// 5
// 1 2 2 3 1

// Output:
// 1:2 2:2 3:1

#include<bits/stdc++.h>
using namespace std;

void frequency(vector<int>arr)
{
    map<int,int> freq;

    for(int i=0; i<arr.size(); i++)
    {
        if(freq.find(arr[i]) != freq.end())
        {
            freq[arr[i]]++;
        }
        else
        {
            freq[arr[i]] = 1;
        }
    }

    cout <<"Frequency of each element is: " <<endl;

    for(auto it = freq.begin(); it != freq.end(); it++)
    {
        cout << it->first <<":" << it->second << " ";
    } 

}
int main()
{
    int n;
    cout <<"Enter size: ";
    cin >> n;

    vector<int> arr(n);

    for(int i=0; i<n; i++)
    {
        cout <<"Enter value for index " << i << " :";
        cin >> arr[i];
    }

    frequency(arr);
    return 0;
}