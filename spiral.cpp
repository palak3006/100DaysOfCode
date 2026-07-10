// Problem: You are given a rectangular matrix of integers. Starting from the outer boundary, traverse the matrix in a clockwise manner and continue moving inward layer by layer until all elements are visited.

// Input:
// - First line: two integers r and c representing the number of rows and columns
// - Next r lines: c integers each representing the matrix elements

// Output:
// - Print all visited elements in the order of traversal, separated by spaces

// Example:
// Input:
// 3 3
// 1 2 3
// 4 5 6
// 7 8 9

// Output:
// 1 2 3 6 9 8 7 4 5

// Explanation:
// The traversal begins along the top row, proceeds down the rightmost column, then moves across the bottom row in reverse, and finally goes up the leftmost column. The same pattern repeats for the inner submatrix.

// Test Cases:

// Test Case 1:
// Input:
// 2 3
// 1 2 3
// 4 5 6
// Output:
// 1 2 3 6 5 4

// Test Case 2:
// Input:
// 3 1
// 7
// 8
// 9
// Output:
// 7 8 9

#include<bits/stdc++.h>
using namespace std;


vector<int> spiral(vector<vector<int>>matrix)
{
    vector<int> ans;

    int top = 0;
    int bottom = matrix.size()-1;

    int left = 0;
    int right = matrix[0].size()-1;

    while(top <= bottom && left <= right)
    {
        //Top row
        for(int i=left; i<=right; i++)
        {
            ans.push_back(matrix[top][i]);
        }
        top++;

        //Right column
        for(int i=top; i<=bottom; i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;

        //bottom row
        if(top <= bottom)
        {
            for(int i=right; i>=left; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        //left column
        if(left <= right)
        {
            for(int i=bottom; i>=top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}

int main()
{
   int row, col;
   cout <<"Enter order of matrix: ";
   cin >> row >> col;

   vector<vector<int>>matrix(row, vector<int> (col));

   cout <<"Enter values for matrix" <<endl;

   for(int i=0; i<row; i++)
   {
    for(int j=0; j<col; j++)
    {
        cout <<"Enter value for index " << i << j << " :";
        cin >> matrix[i][j];
    }
   }

   vector<int> ans = spiral(matrix);

   for(int i=0; i<ans.size(); i++)
   {
    cout << ans[i] << " ";
   }

   return 0;
}

