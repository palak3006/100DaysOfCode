// Problem: Read a string and check if it is a palindrome using two-pointer comparison.

// Input:
// - Single line: string s

// Output:
// - Print YES if palindrome, otherwise NO

// Example:
// Input:
// level

// Output:
// YES

// Explanation: String reads same forwards and backwards

#include<bits/stdc++.h>
using namespace std;

bool palindrome(string s)
{
    int i=0;
    int j= s.length()-1;

    while(i != j)
    {
        if(s[i] != s[j])
        {
            return false;
        }

        i++;
        j--;
    }

    return true;
}

int main()
{
    string s;
    cout <<"Enter string: ";
    cin >> s;

    if(palindrome(s))
    {
        cout << "Is entered string palindrome: Yes";
    }

    else
    {
        cout << "Is entered string palindrome: No";
    }

    return 0;
}