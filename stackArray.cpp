// Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.

// Input:
// - First line: integer n (number of operations)
// - Next n lines: operation type and value (if applicable)
//   - 1 value: push value
//   - 2: pop
//   - 3: display

// Output:
// - For display: print stack elements from top to bottom
// - For pop: print popped element or 'Stack Underflow'

// Example:
// Input:
// 5
// 1 10
// 1 20
// 3
// 2
// 3

// Output:
// 20 10
// 20
// 10

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cout <<"Enter number of operations: ";
    cin >> n;

    cout << "1 value : push value" << endl << "2 : pop value" << endl << "3 : Display" << endl;
    int input;
    
    vector<int> st;

    for(int i=0; i<n; i++)
    {
        cin >> input;

        switch(input)
    {
        case 1:
        {
            int x;
            cin >> x;
            st.push_back(x);
            break;
        }

        case 2:
        {
            if(st.size() == 0)
            cout << "Underflow" << endl;
        
            else
            {
                cout <<"Popped Element is: " << st[st.size()-1];
                st.pop_back();
            }
            break;
        }

        case 3 : 
        {
            if(st.empty())
            {
              cout << "Stack is Empty";
            }

            else {
            for(int i = st.size()-1; i>=0; i--)
            {
                cout << st[i] << " ";
            }
            break;
        }
        }

        default:
        cout <<"Wrong input";

    }
    }


    return 0;
}