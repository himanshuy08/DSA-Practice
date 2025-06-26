#include <iostream>
#include <climits>  // for INT_MIN
using namespace std;

int maxSumSubarray(int arr[], int n, int k) {
    int currentSum = 0, start = 0, end = 0;
    int maxSum = INT_MIN;

    while (end < n) {
        currentSum += arr[end];

        if (end - start + 1 < k) {
            end++;
        } else if (end - start + 1 == k) {
            maxSum = max(maxSum, currentSum);
            currentSum -= arr[start];
            start++;
            end++;
        }
    }

    return maxSum;
}

int main() {
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;

    cout << "Enter the size of the subarray: ";
    cin >> k;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = maxSumSubarray(arr, n, k);
    cout << "Maximum sum of subarray of size " << k << " is: " << result << endl;

    return 0;
}
