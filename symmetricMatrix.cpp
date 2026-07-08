// Problem: Write a program to check whether a given matrix is symmetric. A matrix is said to be symmetric if it is a square matrix and is equal to its transpose (i.e., element at position [i][j] is equal to element at position [j][i] for all valid i and j).

// Input:
// - First line: two integers m and n representing the number of rows and columns
// - Next m lines: n integers each representing the elements of the matrix

// Output:
// - Print "Symmetric Matrix" if the given matrix is symmetric
// - Otherwise, print "Not a Symmetric Matrix"

// Example:
// Input:
// 3 3
// 1 2 3
// 2 4 5
// 3 5 6

// Output:
// Symmetric Matrix

// Explanation:
// The matrix is square (3 × 3) and for every i and j, element[i][j] = element[j][i].

// Test Cases:

// Test Case 1:
// Input:
// 2 2
// 1 2
// 2 1
// Output:
// Symmetric Matrix

// Test Case 2:
// Input:
// 3 3
// 1 0 1
// 2 3 4
// 1 4 5
// Output:
// Not a Symmetric Matrix

// Test Case 3:
// Input:
// 2 3
// 1 2 3
// 4 5 6
// Output:
// Not a Symmetric Matrix

#include<bits/stdc++.h>
using namespace std;

bool symmetric(vector<vector<int>>mat)
{
    for(int i=0; i<mat.size(); i++)
    {
        for(int j=0; j<mat[0].size(); j++)
        {
            if(mat[i][j] != mat[j][i])
            return false;
        }
    }
    return true;
}

int main()
{
    int row, col;
    cout <<"Enter row and col for matrix: ";
    cin >> row >>col;

    vector<vector<int>>mat(row, vector<int>(col));

    cout <<"Enter elements of matrix: " << endl;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cout <<"Enter value for index " << i << j << " :";
            cin >> mat[i][j];
        }
    }

    if(symmetric(mat))
    {
        cout <<"Yes matrix is symmetric";
    }
    else 
    {
        cout <<"Matrix is not Symmetric";
    }
    return 0;
}