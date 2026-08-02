// Problem Statement:
// Implement a Priority Queue using an array. An element with smaller value has higher priority.

// Supported Operations:
// - insert x
// - delete
// - peek

// Input Format:
// - First line contains integer N
// - Next N lines contain operations

// Output Format:
// - Print the deleted or peeked element
// - Print -1 if the queue is empty

// Example:
// Input:
// 5
// insert 30
// insert 10
// insert 20
// delete
// peek

// Output:
// 10
// 20

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> pq;

    string operation;

    for(int i=0; i<n; i++)
    {
        cin >> operation;

        if (operation == "insert")
        {
        
            int x;
            cin >> x;

            pq.push_back(x);

        }

        else if(operation == "delete")
        {

            if(pq.empty())
            {
                cout << -1;
            }

            else {
            int minIndex = 0;

            for(int i=1; i<pq.size(); i++)
            {
                if(pq[i] < pq[minIndex])
                minIndex = i;
            }

            cout << pq[minIndex] << endl;

            pq.erase(pq.begin() + minIndex);
           }

        }

        else if (operation == "peek")
        {
            if(pq.empty())
            {
                cout << "-1";
            }

            else 
            {
                int minIndex = 0;

              for(int i=1; i<pq.size(); i++)
            {
                if(pq[i] < pq[minIndex])
                minIndex = i;
            }

            cout << pq[minIndex] <<endl;;
            }
        }

        else
        {
            cout <<"Wrong Input";
        }
}

return 0;
}
    
