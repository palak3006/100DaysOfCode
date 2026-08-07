// Problem Statement:
// Given a queue of integers, reverse the queue using a stack.

// Input Format:
// - First line contains integer N
// - Second line contains N space-separated integers

// Output Format:
// - Print the reversed queue

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 50 40 30 20 10

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<int>arr(n);

    int front = -1;
    int rear = -1;

    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;

        if(front == -1)
        {
            front = rear = 0;
            arr[front] = x;
        }

        else 
        {
            rear = rear + 1;
            arr[rear] = x;
        }
    }

    stack <int> st;

    for(int i=front; i<=rear; i++)
    {
        st.push(arr[i]);
    }

    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}