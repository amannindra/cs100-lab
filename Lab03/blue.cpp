#include <iostream>
#include <climits>
using namespace std;

// find max sum crossing the midpoint
int maxCrossingSum(int arr[], int left, int mid, int right) {
    int sum = 0;
    int leftMax = INT_MIN;

    for (int i = mid; i >= left; i--) {
        sum += arr[i];
        if (sum > leftMax)
            leftMax = sum;
    }

    sum = 0;
    int rightMax = INT_MIN;

    for (int j = mid + 1; j <= right; j++) {
        sum += arr[j];
        if (sum > rightMax)
            rightMax = sum;
    }

    return leftMax + rightMax;
}

// divide & conquer max subarray
int maxSubarray(int arr[], int left, int right) {
    if (left == right)
        return arr[left];

    int mid = (left + right) / 2;

    int leftSum = maxSubarray(arr, left, mid);
    int rightSum = maxSubarray(arr, mid + 1, right);
    int crossSum = maxCrossingSum(arr, left, mid, right);

    if (leftSum >= rightSum && leftSum >= crossSum)
        return leftSum;
    else if (rightSum >= leftSum && rightSum >= crossSum)
        return rightSum;
    else
        return crossSum;
}

int main() {
    int n;
    cin >> n;

    // dynamic allocation
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = maxSubarray(arr, 0, n - 1);

    cout << result;   // output only one number

    delete[] arr;
    return 0;
}