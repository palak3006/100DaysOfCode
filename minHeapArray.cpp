// Problem Statement:
// Implement a Min Heap using an array where the smallest element is always at the root.

// Supported Operations:
// - insert x
// - extractMin
// - peek

// Input Format:
// - First line contains integer N
// - Next N lines contain heap operations

// Output Format:
// - Print results of extractMin and peek
// - Print -1 if operation cannot be performed

// Example:
// Input:
// 6
// insert 40
// insert 10
// insert 30
// peek
// extractMin
// peek

// Output:
// 10
// 10
// 30

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    string operation;
    vector<int> arr;

    for(int i=0; i<n; i++)
    {
        cin >> operation;

        if(operation == "insert")
        {
           int x;
           cin >> x;

           if(arr.empty())
           arr.push_back(x);

           else 
           {
            arr.push_back(x);
            int child = arr.size()-1;

            while(child > 0)
            {
                int parent = (child-1)/2;

                if(arr[parent] > arr[child])
                {
                  swap(arr[parent], arr[child]);
                  child = parent;
                }

                else 
                break;
            }
           }
        }

        else if(operation == "peek")
        {
            if(arr.empty())
            cout << "Array is empty";
            
            else 
            cout << arr[0] << endl;
        }

        else if(operation == "extractMin")
        {
            if(arr.empty())
            {
                cout << -1 << endl;
                continue;
            }

            cout << arr[0] << endl;

            // Move last element to root
            arr[0] = arr.back();
            arr.pop_back();

            // Heapify Down
            int parent = 0;

            while(true)
            {
                int left = 2 * parent + 1;
                int right = 2 * parent + 2;

                int smallest = parent;

                if(left < arr.size() && arr[left] < arr[smallest])
                    smallest = left;

                if(right < arr.size() && arr[right] < arr[smallest])
                    smallest = right;

                if(smallest != parent)
                {
                    swap(arr[parent], arr[smallest]);
                    parent = smallest;
                }
                else
                    break;
            }
        }
        else 
        {
            cout <<"Wrong operation";
        }
    }

    return 0;
}