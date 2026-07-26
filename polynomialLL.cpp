// Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of terms)
// - Next n lines: two integers (coefficient and exponent)

// Output:
// - Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

// Example:
// Input:
// 5
// 10 4
// 20 3
// 30 2
// 40 1
// 50 0

// Output:
// 10x^4 + 20x^3 + 30x^2 + 40x + 50

// Explanation:
// Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order.

#include<bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    int power;
    Node* next;

    Node(int val, int exp)
    {
        data = val;
        power = exp;
        next = NULL;
    }
};

int main()
{
   int n;
   cout <<"Number of inputs: ";
   cin >> n;

   Node* head = NULL;
   Node* tail = NULL;

   for(int i=0; i<n; i++)
   {
     int x;
     cin >> x;
     int y;
     cin >> y;

     Node* newNode = new Node(x, y);

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

   //traverse
   Node* temp = head;

   while(temp != NULL)
   {
    if(temp->next == NULL)
    cout << temp->data << " ";

    else
    cout << temp->data << "^" << temp->power << " + " << " ";
    temp = temp->next;
   }

   return 0;
}