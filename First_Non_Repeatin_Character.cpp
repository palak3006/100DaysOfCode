// Problem Statement
// Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string. If all characters repeat, return '$'.

// Input Format
// A single string s.

// Output Format
// Print the first non-repeating character or '$' if none exists.

// Sample Input
// geeksforgeeks

// Sample Output
// f

// Explanation
// The character 'f' occurs only once in the string and appears before any other non-repeating character.

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    map<char,int>mpp;


    for(int i=0; i<s.length(); i++)
    {
        mpp[s[i]]++;
    }

    for(int j=0; j<s.length(); j++)
    {
        if(mpp[s[j]] == 1)
        {
            cout << s[j];
            break;
        }
    }

    return 0;
}