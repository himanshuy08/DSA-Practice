#include<iostream>
#include<vector>
using namespace std;

int unboundedKnapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<int> dp(W + 1, 0); // Initialize dp array

    for (int w = 1; w <= W; w++) {
        for (int i = 0; i < n; i++) {
            if (wt[i] <= w) {
                dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
            }
        }
    }
    return dp[W]; // Return the maximum value for the knapsack of capacity W
}

int main() {
    int W = 50; // Maximum weight
    vector<int> wt = {10, 20, 30}; // Weights of items
    vector<int> val = {60, 100, 120}; // Values of items
    int n = val.size(); // Number of items

    cout << "Maximum value in Unbounded Knapsack = " << unboundedKnapsack(W, wt, val, n) << endl;
    return 0;
}

// Time Complexity: O(n * W)
// Space Complexity: O(W) for the dp array
// Note: The code above implements the Unbounded Knapsack problem.
// It uses a 1D array to store the maximum values for each weight capacity.
