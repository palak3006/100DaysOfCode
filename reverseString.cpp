// Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

// Input:
// - Single line: a lowercase string containing only alphabetic characters (no spaces)

// Output:
// - Print the transformed code name after applying the mirror operation

// Example:
// Input:
// hello

// Output:
// olleh

// Explanation: The first character moves to the last position, the second to the second-last, and so on until the entire string is mirrored


#include<bits/stdc++.h>
using namespace std;


void reverseString(string s)
{
    for(int i=0; i<s.size()/2; i++)
    {
        swap(s[i], s[s.size()-1-i]);
    }

    cout <<"String after Reversing: " << s;
}

int main()
{
    string s;
    cout <<"Enter srting: ";
    cin >> s;

    reverseString(s);

    return 0;
}