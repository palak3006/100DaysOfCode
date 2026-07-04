// Problem: Given integers a and b, compute a^b using recursion without using pow() function.

// Input:
// - Two space-separated integers a and b

// Output:
// - Print a raised to power b

// Example:
// Input:
// 2 5

// Output:
// 32

// Explanation: 2^5 = 2 * 2 * 2 * 2 * 2 = 32

#include<iostream>
using namespace std;

int power(int a, int b)
{
    if(b==0)
    return 1;
    else if(b % 2 == 0)
    {
        int ans = power(a, b/2);
        return ans * ans;
    }

    else if(b % 2 !=0)
    {
        int ans2 = power(a, b/2);
        return ans2 * ans2 * a;
    }

}

int main()
{
    int a, b;
    cout <<"Enter two numbers: ";
    cin >> a >> b;

    int ans = power(a,b);

    cout << ans;
    return 0;
}