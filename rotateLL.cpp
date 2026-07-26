// Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer k

// Output:
// - Print the linked list elements after rotation, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 40 50 10 20 30

// Explanation:
// Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.


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

Node* rotate(Node* head, int k)
{
    if(head == NULL || head->next == NULL || k == 0)
    return head;

    int len = 0;

    Node* temp = head;
    while(temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    int step = k % len;

    for(int i=0; i<step; i++)
    {
        Node* first = head;
        Node* second = head->next;
        while(second->next != NULL)
       {
        first = first->next;
        second = second->next;
       }

       first->next = NULL;
       second->next = head;
       head = second;
    }

    return head;
}

int main()
{
     int n;
     cout <<"Enter size: ";
     cin >> n;

     Node* head = NULL;
     Node* tail = NULL;

     for(int i=0; i<n; i++)
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

     int k;
     cout <<"Enter number of rotations: ";
     cin >> k;

     Node* newHead = rotate(head, k);

     while(newHead != NULL)
     {
        cout << newHead->data << " ";
        newHead = newHead->next;
     }

     return 0;
}