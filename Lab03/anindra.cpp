#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int maxCrossingSum(int array[], int left_index, int midpoint, int right_index) {
    int sums = 0;
    int leftMax = -1000000000;

    for (int i = midpoint; i >= left_index; i--) {
        sums += array[i];
        if (sums > leftMax)
            leftMax = sums;
    }
    sums = 0;
    int rightMax = -1000000000;

    for (int j = midpoint + 1; j <= right_index; j++) {
        sums += array[j];
        if (sums > rightMax)
            rightMax = sums;
    }

    return leftMax + rightMax;
}


int maxSubarray(int array[], int left_index, int right_index) {
    if (left_index == right_index)
        return array[left_index];

    int midpoint = (left_index + right_index) / 2;

    int leftSum = maxSubarray(array, left_index, midpoint);
    int rightSum = maxSubarray(array, midpoint + 1, right_index);
    int crossSum = maxCrossingSum(array, left_index, midpoint, right_index);

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

    int* array = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    int result = maxSubarray(array, 0, n - 1);

    cout << result;   

    return 0;
}