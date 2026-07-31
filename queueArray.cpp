// Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of elements)
// - Second line: n space-separated integers

// Output:
// - Print queue elements from front to rear, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 10 20 30 40 50

// Explanation:
// Use array and front/rear pointers. Enqueue inserts at rear, dequeue removes from front. Display from front to rear.

#include<bits/stdc++.h>
using namespace std;

int front = -1;
int rear = -1;

void enqueue(int x, vector<int>&arr)
{

    if(front == -1)
    {
        front = 0;
        rear = 0;
    }

    else 
    {
        rear++;
    }

    arr[rear] = x;
}

void traverse(vector<int>&arr)
{
    int i=front;

    while(i <= rear)
    {
        cout << arr[i] << " ";
        i++;
    }
}

int main()
{
    int size;
    cin >> size;

    vector<int> arr(size);

    for(int i=0; i<size; i++)
    {
        int x;
        cin >> x;
        enqueue(x, arr);
    }

    traverse(arr);
    
}