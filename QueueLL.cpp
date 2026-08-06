// Problem Statement:
// Implement a Queue using a linked list supporting enqueue and dequeue operations.

// Input Format:
// - First line contains integer N
// - Next N lines contain queue operations

// Output Format:
// - Print dequeued elements
// - Print -1 if dequeue is attempted on an empty queue

#include<bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};


int main()
{
   int n;
   cin >> n;

   Node* head = NULL;
   Node* tail = NULL;

   for(int i=0; i<n; i++)
   {
    string operation;
    cin >> operation;

    if(operation == "enqueue")
    {
        int x;
        cin >> x;

        Node* newNode = new Node(x);

        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }

        else 
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    else if(operation == "dequeue")
    {
        if(head == NULL)
        cout << "Queue is empty" << endl;

        else 
        {
           cout << head->data << endl;
           Node* temp = head;
           head = head->next;
           delete temp;

           if(head == NULL)
           {
              tail = NULL;
           }
        }
    }
   }

   return 0;
}