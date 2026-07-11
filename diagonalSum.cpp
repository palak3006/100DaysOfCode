// Problem: Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.

// Input:
// - First line: two integers m and n
// - Next m lines: n integers each

// Output:
// - Print the sum of the primary diagonal elements

// Example:
// Input:
// 3 3
// 1 2 3
// 4 5 6
// 7 8 9

// Output:
// 15

// Explanation:
// 1 + 5 + 9 = 15

#include<bits/stdc++.h>
using namespace std;

int diagonalSum(vector<vector<int>>matrix)
{
    int sum = 0;

    for(int i=0 ;i<matrix.size(); i++)
    {
        sum += matrix[i][i];
    }

    return sum;
}

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int row, col;
    cout <<"Enter rows and cols: ";
    cin >> row >> col;

    vector<vector<int>>matrix(row, vector<int>(col));

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cout <<"Enter value for index " << i << j <<" :";
            cin >> matrix[i][j];
        }
    }

    int sum = diagonalSum(matrix);

    cout <<"Sum of Primary Diagonal Elements is: " << sum << endl;
    return 0;

}