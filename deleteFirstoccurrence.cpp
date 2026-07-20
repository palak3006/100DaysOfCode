// Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer key

// Output:
// - Print the linked list elements after deletion, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 30

// Output:
// 10 20 40 50

// Explanation:
// Traverse list, find first node with key, remove it by adjusting previous node's next pointer.

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

Node* remove(Node* head, int val)
{
    Node* dummy = new Node(0);
    dummy->next = head;

    Node* curr = dummy;

    while(curr->next != NULL)
    {
        if(curr->next->data == val)
        {
            curr->next = curr->next->next;
            break;
        }
        else 
        {
            curr = curr->next;
        }
    }

    return dummy->next;
}
int main()
{
    int n;
    cout <<"Enter number of nodes: ";
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

    int val;
    cout <<"Enter value to remover: ";
    cin >> val;

    Node* newHead = remove(head, val);

    Node* temp = newHead;

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}