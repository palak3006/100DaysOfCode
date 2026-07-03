// Problem: Write a recursive function fib(n) to compute the n-th Fibonacci number where fib(0)=0 and fib(1)=1.

// Input:
// - Single integer n

// Output:
// - Print the n-th Fibonacci number

// Example:
// Input:
// 6

// Output:
// 8

// Explanation: Sequence: 0,1,1,2,3,5,8 at positions 0,1,2,3,4,5,6

#include<iostream>
using namespace std;

int recursiveFibonacci(int n)
{
    if(n==0)
    {
        return 0;
    }

    else if(n==1)
    {
        return 1;
    }

    return recursiveFibonacci(n-1) + recursiveFibonacci(n-2);

}

int main()
{
    int n;
    cout <<"Enter position: ";
    cin >> n;

    int ans = recursiveFibonacci(n);

    cout <<"Value at position " << n <<" is: " << ans;
    return 0;
}