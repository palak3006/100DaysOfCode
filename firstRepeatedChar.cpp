// Problem Statement
// Given a string s consisting of lowercase letters, find the first repeated character in the string. A character is considered repeated if it appears more than once, and among all such characters, the one whose second occurrence has the smallest index should be returned.

// Input Format
// A single string s.

// Output Format
// Print the first repeated character. If no character is repeated, print -1.

// Sample Input
// geeksforgeeks

// Sample Output
// e

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
     
    map<char,int> mpp;

    for(int i=0; i<s.size(); i++)
    {
        if(mpp[s[i]] == 1)
        {
            cout << s[i];
            break;
        }

        mpp[s[i]] = 1;
    }


    return 0;

}
