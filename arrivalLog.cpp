// Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

// Input:
// - First line: integer p (number of entries in server log 1)
// - Second line: p sorted integers representing arrival times from server 1
// - Third line: integer q (number of entries in server log 2)
// - Fourth line: q sorted integers representing arrival times from server 2)

// Output:
// - Print a single line containing all arrival times in chronological order, separated by spaces

// Example:
// Input:
// 5
// 10 20 30 50 70
// 4
// 15 25 40 60

// Output:
// 10 15 20 25 30 40 50 60 70

// Explanation: Compare the next unprocessed arrival time from both logs and append the earlier one to the final log until all entries are processed

#include<iostream>
#include<vector>
using namespace std;

void chronologicalOrder(vector<int> log1, vector<int> log2)
{
    int i = log1.size()-1;
    int j = log2.size()-1;

    int k = log1.size() + log2.size() - 1;

    vector<int> merge(log1.size() + log2.size());

    while(i>=0 && j>=0)
    {
        if(log1[i] >= log2[j])
        {
            merge[k--] = log1[i--];
        }

        else
        {
            merge[k--] = log2[j--];
        }
    }

    while(i >=0)
    {
         merge[k--] = log1[i--];
    }

    while(j>=0)
    {
        merge[k--] = log2[j--];
    }

    cout <<"all arrival times in chronological order: " << endl;

    for(int m=0; m<merge.size(); m++)
    {
        cout << merge[m] << " ";
    }
}

int main()
{
    int s1;
    cout << "Number of entries in log 1: ";
    cin >> s1;

    vector<int> log1(s1);

    for(int i=0; i<s1; i++)
    {
        cout <<"Enter entry for index " << i << " :";
        cin >> log1[i];
    }
    cout  << endl;

    int s2;
    cout <<"Number of entries in log 2: ";
    cin >> s2;

    vector<int> log2(s2);

    for(int i=0; i<s2; i++)
    {
        cout <<"Enter entry for index " << i << " :";
        cin >> log2[i];
    }
    cout  << endl;

    chronologicalOrder(log1, log2);
    

    return 0;

}