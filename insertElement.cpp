// Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (the array)
// - Third line: integer pos (1-based position)
// - Fourth line: integer x (element to insert)

// Output:
// - Print the updated array (n+1 integers) in a single line, space-separated

// Example:
// Input:
// 5
// 1 2 4 5 6
// 3
// 3

// Output:
// 1 2 3 4 5 6

// Explanation: Insert 3 at position 3, elements [4,5,6] shift right

//I have written in C++

#include <iostream>
#include<vector>

using namespace std;

int main()
{
    cout << "Enter size of the Array: ";
    
    int size;

    cin >> size;

    vector<int> arr(size);

    for(int i=0; i<size; i++)
    {
        cout << "Enter value for index " << i << ": ";
        cin >> arr[i];
    }

    int index;
    int newElement; 

    cout << "Enter index for new element: ";
    cin >> index;

    cout << "Enter new element: ";
    cin >> newElement;

    arr.push_back(0);//To increase the size

    for(int j=size; j>index; j--)
    {
        arr[j] = arr[j-1];
    }

    arr[index] = newElement;

    cout << "Updated Array: " << endl;

    for(int i=0; i<arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

