#include <iostream>
#include <limits>
#include <vector>
#include <climits>
#include <algorithm>
// This program implements the divide and conquer algorithm to find the maximum subarray sum in a given array of integers. The main function reads the input array and calls the solve function.
// The program divides the array into halves until it reaches the base case of a single element. 
// The bridge function is used to find the maximum sum that crosses the midpoint of the current segment. Finally, the program outputs the maximum subarray sum found.

using namespace std; 
using num = long long; // to avoid overflow, we use long long instead of int

num bridge(const vector<num>& v, int a, int b, int c) // a, b, c where  a < b < c
{
    num L = LLONG_MIN; // we initialize L and M to the smallest possible value to handle cases where all numbers are negative
    num actual = 0; 

    for (int i = b; i > a; --i) // start from b and go down to a + 1 
    {
        actual += v[i]; // we add the current element to actual
        if (actual > L) L = actual; // if actual is greater than L, we update L
    }
    num M = LLONG_MIN; 
    actual = 0; 
    for (int i = b + 1; i <= c; i++) // start from b + 1 and go up to c
    {
        actual += v[i]; 
        if (actual > M) M = actual; // if actual is greater than M, we update M
    }

    return L + M; // the maximum sum of the left and right parts that cross the midpoint b
}

num solve(const vector<num>& v, int a, int b)
{
    if (a == b) return v[a]; // base case: if there is only one element, return that element

    int c = (a + b) / 2; // we find the midpoint of the current segment
    num L = solve(v, a, c); // solve the left and right halves
    num R = solve(v, c + 1, b); // solve the left and right halves 
    num M = bridge(v, a, c, b); // finding the maximum sum that crosses the midpoint c

    return max({L, R, M}); 
}

int main()
{
    int n; 
    cin >> n; 
    vector<num> v(n); // creating a vector of size n to store the input array
    for (int i = 0; i < n; i++) cin >> v[i]; // read inputing array 

    cout << solve(v, 0, n - 1) << endl; // call the solve function with the entire array and print the result

    return 0;
}



