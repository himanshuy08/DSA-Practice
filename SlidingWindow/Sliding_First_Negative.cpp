#include <iostream>
#include <deque>
#include <vector>
using namespace std;

// Function to find first negative number in every window of size k
vector<int> firstNegativeInWindow(int arr[], int n, int k) {
    vector<int> result;
    deque<int> dq; // stores indices of negative numbers

    int start = 0, end = 0;

    while (end < n) {
        // Step 1: Add current element if it's negative
        if (arr[end] < 0) {
            dq.push_back(end);
        }

        // Step 2: Check if window size < k → expand window
        if (end - start + 1 < k) {
            end++;
        }

        // Step 3: When window size == k → process and slide
        else if (end - start + 1 == k) {
            // Add first negative number to result
            if (!dq.empty()) {
                result.push_back(arr[dq.front()]);
            } else {
                result.push_back(0);
            }

            // Step 4: Remove element going out of the window
            if (!dq.empty() && dq.front() == start) {
                dq.pop_front();
            }

            // Slide the window
            start++;
            end++;
        }
    }

    return result;
}

int main() {
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    vector<int> result = firstNegativeInWindow(arr, n, k);

    cout << "First negative number in every window of size " << k << ":\n";
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
