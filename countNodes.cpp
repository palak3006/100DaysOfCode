// Problem: Count Nodes in Linked List

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

void count(Node* head)
{
    Node* first = head;
    int count = 0;

    while(first != NULL)
    {
        cout << first->val <<" ";
        first = first->next;
        count++;
    }

    cout <<"\nTotal number of nodes are: " << count;
}

int main()
{
    int n;
    cout <<"Enter number of nodes: ";
    cin >> n;

    Node* head = NULL;
    Node* tail = NULL;

    for(int i= 0; i<n; i++)
    {
        int val;
        cin >> val;

        Node* newNode = new Node(val);

        //First node
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

    count(head);
    return 0;


}