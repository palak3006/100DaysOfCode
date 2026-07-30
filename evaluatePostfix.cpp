// Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

// Input:
// - Postfix expression with operands and operators

// Output:
// - Print the integer result

// Example:
// Input:
// 2 3 1 * + 9 -

// Output:
// -4

// Explanation:
// Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.

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

void push(int data, Node* &top)
{
    Node* newNode = new Node(data);

    if(top == NULL)
    top = newNode;

    else
    {
        newNode->next = top;
        top = newNode;
    }
}

int pop(Node* &top)
{
    int value = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return value;
}

int evaluate(vector <string> post)
{
    int i=0;
    Node* top = NULL;
    
    while(i < post.size())
    {
        if(post[i] != "+" && post[i] != "-" && post[i] != "*" && post[i] != "/")
        {
            push(stoi(post[i]), top);
        }

        else 
        {
            int n1 = pop(top);
            int n2 = pop(top);

            if(post[i] == "+")
            {
                int ans = n2 + n1;

                push(ans, top);
            }

            else if(post[i] == "-")
            {
                int ans = n2 - n1;

                push(ans, top);
            }

            else if(post[i] == "*")
            {
                int ans = n2 * n1;

                push(ans, top);
            }

            else 
            {
                int ans = n2 / n1;

                push(ans, top);
            }
        }

        i++;
    }

    return top->data;
}

int main()
{
   vector<string> post = {"2", "3", "1", "*", "+", "9", "-"};
   cout << evaluate(post);
   return 0;
}