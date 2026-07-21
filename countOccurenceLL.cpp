// Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of nodes)
// - Second line: n space-separated integers (linked list elements)
// - Third line: integer key (element to be counted)

// Output:
// - Print the number of times the key appears in the linked list

// Example:
// Input:
// 6
// 10 20 30 20 40 20
// 20

// Output:
// 3

// Explanation:
// Traverse the linked list from head to end. Each time a node's data matches the given key, increment a counter. After traversal, print the final count.

#include<bits/stdc++.h>
using namespace std;

struct Node 
{
    int val;
    Node* next;

    Node(int data)
    {
        val = data;
        next = NULL;
    }
};


int occurrence(Node* head, int element)
{
    Node* temp = head;
    int occurrence = 0;

    while(temp != NULL)
    {
        if(temp->val == element)
        {
            occurrence++;
        }

        temp = temp->next;
    }

    return occurrence;
}

int main()
{
   int n;
   cout <<"Enter number of nodes to enter: ";
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

   int element;
   cout <<"Enter element of which occurrence has to be counted: ";
   cin >> element;

   int count = occurrence(head, element);

   cout << element <<" occurs " << count << " times" << endl;
   return 0;

   
}