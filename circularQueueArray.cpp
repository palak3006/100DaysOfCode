// Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of elements to enqueue)
// - Second line: n space-separated integers
// - Third line: integer m (number of dequeue operations)

// Output:
// - Print queue elements from front to rear after operations, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 30 40 50 10 20

// Explanation:
// Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.

#include<bits/stdc++.h>
using namespace std;

int front = -1;
int rear = -1;

void enqueue(vector<int>&arr, int val)
{
    if((rear+1) % arr.size() == front)
    cout << "Queue is Full";

    else if(front == -1)
    {
        front = rear = 0;
        arr[front] = val;
    }

    else 
    {
        rear = (rear + 1)%arr.size();
        arr[rear] = val;
    }
}

void traverse(vector<int>&arr, int index)
{
    for(int i = 0; i<arr.size(); i++)
    {
        cout << arr[index] << " ";
        
        index = (index + 1) % arr.size();
    
    }
}

int main()
{
    int size;
    cin >> size;

    vector<int> dq(size);

    for(int i=0; i<size; i++)
    {
        int x;
        cin >> x;
        
        enqueue(dq, x);
    }

    int k;
    cin>>k;

    traverse(dq, k);
    return 0;
}