// Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (first list)
// - Third line: integer m
// - Fourth line: m space-separated integers (second list)

// Output:
// - Print value of intersection node or 'No Intersection'

// Example:
// Input:
// 5
// 10 20 30 40 50
// 4
// 15 25 30 40 50

// Output:
// 30

// Explanation:
// Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.

#include<iostream>
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

int intersection(Node* head1, Node* head2)
{
    Node* temp1 = head1;
    Node* temp2 = head2;

    int len1 = 0;
    while(temp1 != NULL)
    {
       len1++;
       temp1 = temp1->next;
    }

    int len2 = 0;
    while(temp2 != NULL)
    {
       len2++;
       temp2 = temp2->next;
    }

    int diff = abs(len2 - len1);

    temp1 = head1;
    temp2 = head2;

    if(len2 > len1)
    {
        while(diff != 0)
        {
            temp2 = temp2->next;
            diff--;
        }
    }

    else if(len1 > len2)
    {
        while(diff != 0) {
            temp1 = temp1->next;
            diff--;
        }
    }


    while(temp1 != NULL && temp2 != NULL)
    {
        if(temp1 == temp2)
        return temp1->data;

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return -1;
}

int main()
{
    int n, m;

    cout << "Enter number of nodes for Linked List 1: ";
    cin >> n;

    Node* head1 = NULL;
    Node* tail1 = NULL;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        Node* newNode = new Node(x);

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

    cout << "Enter number of nodes for Linked List 2 (before intersection): ";
    cin >> m;

    Node* head2 = NULL;
    Node* tail2 = NULL;

    for(int i = 0; i < m; i++)
    {
        int x;
        cin >> x;

        Node* newNode = new Node(x);

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

    // Ask user where the intersection should occur
    int val;
    cout << "Enter value in List1 where List2 should intersect (-1 for no intersection): ";
    cin >> val;

    if(val != -1)
    {
        Node* temp = head1;

        while(temp != NULL && temp->data != val)
        {
            temp = temp->next;
        }

        if(temp != NULL)
        {
            tail2->next = temp;   // Create actual intersection
        }
    }

    int ans = intersection(head1, head2);

    if(ans != -1)
        cout << "Intersection point is: " << ans << endl;
    else
        cout << "No Intersection" << endl;

    return 0;
}