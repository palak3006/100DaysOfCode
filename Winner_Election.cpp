// Problem Statement
// Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

// Input Format
// First line contains an integer n representing number of votes.
// Second line contains n space-separated strings representing candidate names.

// Output Format
// Print the name of the winning candidate followed by the number of votes received.

// Sample Input
// 13
// john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

// Sample Output
// john 4

// Explanation
// Both john and johnny receive 4 votes, but john is lexicographically smaller, so john is declared the winner.

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int votes;
    cin >> votes;

    map<string,int> mpp;

    for(int i=0; i<votes; i++)
    {
        string name;
        cin >> name;

        mpp[name]++;
    }

    int maxVotes = 0;
    string candidate;

    for(auto it : mpp)
    {
        if(it.second > maxVotes)
        {
            candidate = it.first;
            maxVotes = it.second;
        }
    }
    
    cout << candidate << ":" << maxVotes; 
    return 0;
}