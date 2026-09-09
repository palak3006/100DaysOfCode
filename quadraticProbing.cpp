// Problem Statement
// Implement a hash table using quadratic probing with formula:

// h(k, i) = (h(k) + i*i) % m

// Input Format
// Same as previous.

// Output Format
// Result of SEARCH operations.

// Sample Input
// 7
// 4
// INSERT 49
// INSERT 56
// SEARCH 49
// SEARCH 15

// Sample Output
// FOUND
// NOT FOUND

// Explanation
// Collisions resolved using i² jumps.

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int size;
    cin >> size;

    vector<int> hash(size, -1);

    int operations;
    cin >> operations;

    for(int i = 0; i < operations; i++)
    {
        string operation;
        cin >> operation;

        // INSERT
        if(operation == "INSERT")
        {
            int x;
            cin >> x;

            int collision = 0;
            int index = x % size;

            while(hash[index] != -1)
            {
                collision++;

                index = (x % size + collision * collision) % size;
            }

            hash[index] = x;
        }

        // SEARCH
        else if(operation == "SEARCH")
        {
            int x;
            cin >> x;

            int collision = 0;
            bool found = false;

            while(collision < size)
            {
                int index = (x % size + collision * collision) % size;

                if(hash[index] == -1)
                    break;

                if(hash[index] == x)
                {
                    found = true;
                    break;
                }

                collision++;
            }

            if(found)
                cout << "FOUND\n";
            else
                cout << "NOT FOUND\n";
        }
    }

    return 0;
}