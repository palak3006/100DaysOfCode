// Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

// Input:
// - First line: integer n (array size)
// - Second line: n space-separated integers
// - Third line: integer k (key to search)

// Output:
// - Line 1: "Found at index i" OR "Not Found"
// Line 2: "Comparisons = c"

// Example:
// Input:
// 5
// 10 20 30 40 50
// 30

// Output:
// Found at index 2
// Comparisons = 3

// Explanation: Compared with 10, 20, 30 (found at index 2 with 3 comparisons)


#include<iostream>
using namespace std;

int main()
{
    int size;
    cout <<"Enter number of elements in Array: ";
    cin >> size;

    int arr[size];

    for(int i=0; i<size; i++)
    {
        cout <<"Enter value for index " << i << ": ";
        cin >> arr[i];
    }

    int searchElement;

    cout <<"Enter element to search: ";
    cin >> searchElement;

    int count = 0;
    bool search = false;

    for(int j=0; j<size; j++)
    {
        count++;
        if(searchElement == arr[j])
        {
            search = true;
            cout << searchElement << " Found at index " << j << endl;
            break;
        }
    }

    if(search == false)
    {
        cout << searchElement << " Not Found"<< endl;
    }

    cout << "Total Comaprisons: " << count << endl;
    return 0;
}