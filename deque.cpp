// Problem: Deque (Double-Ended Queue)

// A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

// Common Operations:
// 1. push_front(value): Insert an element at the front of the deque.
// 2. push_back(value): Insert an element at the rear of the deque.
// 3. pop_front(): Remove an element from the front of the deque.
// 4. pop_back(): Remove an element from the rear of the deque.
// 5. front(): Return the front element of the deque.
// 6. back(): Return the rear element of the deque.
// 7. empty(): Check whether the deque is empty.
// 8. size(): Return the number of elements in the deque.

// Additional Operations:
// - clear(): Remove all elements from the deque.
// - erase(): Remove one or more elements from the deque.
// - swap(): Swap contents of two deques.
// - emplace_front(): Insert an element at the front without copying.
// - emplace_back(): Insert an element at the rear without copying.
// - resize(): Change the size of the deque.
// - assign(): Replace elements with new values.
// - reverse(): Reverse the order of elements.
// - sort(): Sort the elements in ascending order.

// Time Complexity:
// - push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
// - clear, erase, resize, assign, reverse: O(n)
// - sort: O(n log n)

// Input:
// - Sequence of deque operations with values (if applicable)

// Output:
// - Results of operations such as front, back, size, or the final state of the deque after all operations

#include<bits/stdc++.h>
using namespace std;

struct Node 
{
    Node* prev;
    int data;
    Node* next;

    Node(int val)
    {
        prev = NULL;
        data = val;
        next = NULL;
    }
};


int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    int n;
    cin >> n;   // number of operations

    while(n--)
    {
        string operation;
        cin >> operation;

        if(operation == "push_back")
        {
            int x;
            cin >> x;

            Node* newNode = new Node(x);

            if(head == NULL)
            {
                head = tail = newNode;
            }
            else
            {
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            }
        }


        else if(operation == "push_front")
        {
            int x;
            cin >> x;

            Node* newNode = new Node(x);

            if(head == NULL)
            {
                head = tail = newNode;
            }
            else
            {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        }


        else if(operation == "pop_back")
        {
            if(tail == NULL)
            {
                cout << "Deque is empty\n";
            }
            else
            {
                Node* temp = tail;

                tail = tail->prev;

                if(tail == NULL)   // only one element
                    head = NULL;
                else
                    tail->next = NULL;

                delete temp;
            }
        }


        else if(operation == "pop_front")
        {
            if(head == NULL)
            {
                cout << "Deque is empty\n";
            }
            else
            {
                Node* temp = head;

                head = head->next;

                if(head == NULL)
                    tail = NULL;
                else
                    head->prev = NULL;

                delete temp;
            }
        }


        else if(operation == "front")
        {
            if(head == NULL)
                cout << -1 << endl;
            else
                cout << head->data << endl;
        }


        else if(operation == "back")
        {
            if(tail == NULL)
                cout << -1 << endl;
            else
                cout << tail->data << endl;
        }


        else if(operation == "empty")
        {
            if(head == NULL)
                cout << "true\n";
            else
                cout << "false\n";
        }


        else if(operation == "size")
        {
            int count = 0;

            Node* temp = head;

            while(temp != NULL)
            {
                count++;
                temp = temp->next;
            }

            cout << count << endl;
        }
    }

    return 0;
}