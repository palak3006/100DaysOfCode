// Problem: Write a program to perform addition of two matrices having the same dimensions. The sum of two matrices is obtained by adding corresponding elements of the matrices.

// Input:
// - First line: two integers m and n representing the number of rows and columns
// - Next m lines: n integers each representing the elements of the first matrix
// - Next m lines: n integers each representing the elements of the second matrix

// Output:
// - Print the resultant matrix after addition, with each row on a new line and elements separated by spaces

// Example:
// Input:
// 3 3
// 1 2 3
// 4 5 6
// 7 8 9
// 9 8 7
// 6 5 4
// 3 2 1

// Output:
// 10 10 10
// 10 10 10
// 10 10 10

// Explanation:
// Each element of the result matrix is the sum of the corresponding elements from the two input matrices.

// Test Cases:

// Test Case 1:
// Input:
// 2 2
// 1 2
// 3 4
// 5 6
// 7 8
// Output:
// 6 8
// 10 12

// Test Case 2:
// Input:
// 1 3
// 10 20 30
// 1 2 3
// Output:
// 11 22 33

// Test Case 3:
// Input:
// 3 1
// 1
// 2
// 3
// 4
// 5
// 6
// Output:
// 5
// 7
// 9

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> matrixAddition(vector<vector<int>>mat1, vector<vector<int>>mat2)
{
    vector<vector<int>>ans(mat1.size(), vector<int>(mat1[0].size()));
    for(int i=0; i<mat1.size(); i++)
    {
        for(int j=0; j<mat1[0].size(); j++)
        {
            ans[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    return ans;
}

int main()
{
    int row, col;
    cout << "Enter order of matrix: ";
    cin >> row >> col;

    vector<vector<int>> matrix1(row, vector<int>(col));
    vector<vector<int>> matrix2(row, vector<int>(col));

    cout <<"Matrix 1: " << endl;

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cout << "Enter value for index " << i << j << " :";
            cin >> matrix1[i][j];
        }
    }

    cout <<"Matrix 2: " << endl;
    
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cout << "Enter value for index " << i << j << " :";
            cin >> matrix2[i][j];
        }
    }

    vector<vector<int>> matAdd = matrixAddition(matrix1, matrix2);

    cout <<"Matrix After Addition: " << endl;

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cout << matAdd[i][j] << " ";
           
        }
        cout <<endl;
    }

    return 0;
}