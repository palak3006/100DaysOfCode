// Problem: Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.

// Input:
// - First line: integer n representing number of rows and columns
// - Next n lines: n integers each representing the matrix elements

// Output:
// - Print "Identity Matrix" if the matrix satisfies the condition
// - Otherwise, print "Not an Identity Matrix"

// Example:
// Input:
// 3
// 1 0 0
// 0 1 0
// 0 0 1

// Output:
// Identity Matrix

#include<bits/stdc++.h>
using namespace std;

bool isIdentity(vector<vector<int>>matrix)
{
    for(int i=0; i<matrix.size(); i++)
    {
        for(int j=i; j<matrix.size(); j++)
        {
            if(matrix[i][j] != 1)
            return false;
             
            break;
        }
    }

    return true;
}

int main()
{
    int row;
    cout <<"Enter order of matrix: ";
    cin >> row;

    vector<vector<int>> matrix(row, vector<int>(row));

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<row; j++)
        {
            cout <<"Enter value for index " << i << j << " :";
         
           cin >> matrix[i][j];
        }
    }


    if(isIdentity(matrix))
    {
        cout <<"Identity Matrix";
    }
    else 
    {
        cout <<"Not Identity Matrix";
    }
    return 0;
}