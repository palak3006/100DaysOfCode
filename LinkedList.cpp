// Problem: Create and Traverse Singly Linked List

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the result

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 10 20 30 40 50

#include<bits/stdc++.h>
using namespace std;

// Node structure
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

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        Node* newNode = new Node(x);

        // First node
        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        // Remaining nodes
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Traverse the linked list
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}