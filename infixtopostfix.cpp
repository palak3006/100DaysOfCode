// Problem: Convert an infix expression to postfix notation using stack.

// Input:
// - Single line: infix expression (operands are single characters)

// Output:
// - Print the postfix expression

// Example:
// Input:
// A+B*C

// Output:
// ABC*+

// Explanation:
// Operator precedence: * > +
// Use stack to handle operator precedence and associativity

#include<bits/stdc++.h>
using namespace std;

void postfix (string infix)
{
    int i = 0;
     
    stack <char> op;
    string ans = "";

    while(i < infix.size())
    {
        if(infix[i] == '+')
        {
            if(op.empty() == true)
            op.push(infix[i]);

            else 
            {
                if(op.top() == '*' || op.top() == '+')
                {
                    ans += op.top();
                    op.pop();
                    op.push(infix[i]);
                }
            }
        }

        else if(infix[i] == '*')
        {
            if(op.empty() == true)
            op.push(infix[i]);

            else 
            {
                if(op.top() == '+')
                {
                    op.push(infix[i]);
                }

                else
                {
                    ans += op.top();
                    op.pop();
                    op.push(infix[i]);
                }
            }
        }

        else 
        {
            ans += infix[i];
        }
        i++;
    }

    cout << ans;
    while(!op.empty())
    {
        cout << op.top();
        op.pop();
    }
}

int main()
{
    string infix = "A+B*C";

    postfix(infix);
    return 0;
}