// Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (first list)
// - Third line: integer m
// - Fourth line: m space-separated integers (second list)

// Output:
// - Print the merged linked list elements, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 4
// 15 25 35 45

// Output:
// 10 15 20 25 30 35 40 45 50

// Explanation:
// Compare nodes of both lists, append smaller to result, continue until all nodes are merged.

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

Node* mergeLists(Node* head1, Node* head2)
{

    if(head1 == NULL)
    return head2;

    if(head2 == NULL)
    return head1;

    Node* l1 = head1;
    Node* l2 = head2;

    Node* newHead = NULL;
    Node* newTail = NULL;

    while(l1 != NULL && l2!= NULL)
    {
        if(l1->data > l2->data)
        {
            if(newHead == NULL)
            {
                newHead = l2;
                newTail = l2;

            }

            else
            {
                newTail->next = l2;
                newTail = l2;
            }

            l2 = l2->next;
        }

        else
        {
            if(newHead == NULL)
            {
                newHead = l1;
                newTail = l1;

            }

            else
            {
                newTail->next = l1;
                newTail = l1;
            }

            l1 = l1->next;
        }
    }

    while(l1 != NULL)
    {
        newTail->next = l1;
        newTail = l1;
        l1 = l1->next;
    }

    while(l2 != NULL)
    {
        newTail->next = l2;
        newTail = l2;
        l2 = l2->next;
    }

    return newHead;
}

int main()
{
   int n;
   cout <<"Number of nodes for List 1: ";
   cin >> n;

   Node* head1 = NULL;
   Node* tail1 = NULL;

   cout <<"Enter values for list 1" << endl;

    //Linked List 1
   for(int i=0; i<n; i++)
   {
      int x;
      cin >> x;

      Node* newNode = new Node(x);
      //first node
      if(head1 == NULL)
      {
        head1 = newNode;
        tail1 = newNode;
      }

      else 
      {
        tail1->next = newNode;
        tail1 = newNode;
      }
   }

   int m;
   cout <<"Enter number of nodes for list 2: ";
   cin >> m;

   //Linked List 2
   Node* head2 = NULL;
   Node* tail2 = NULL;

   cout <<"Enter values for list 2" << endl;
   for(int i=0; i<m; i++)
   {
      int x;
      cin >> x;

      Node* newNode = new Node(x);
      //first node
      if(head2 == NULL)
      {
        head2 = newNode;
        tail2 = newNode;
      }

      else 
      {
        tail2->next = newNode;
        tail2 = newNode;
      }
   }

   Node* newHead = mergeLists(head1, head2);

   Node * temp = newHead;

   while(temp != NULL)
   {
    cout << temp->data << " ";
    temp = temp->next;
   }

   return 0;
}