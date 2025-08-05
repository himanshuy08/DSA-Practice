#include<iostream>
#include<vector>
using namespace std;

int knapsack(int W, vector<int>& wt, vector<int>& val, int n){
    int dp[n+1][W+1];

    if(W == 0 || n == 0) return 0; // Base case
    for(int i = 0; i <= n; i++) {
        for(int w = 0; w <= W; w++) {
            if(i == 0 || w == 0) {
                dp[i][w] = 0; // Base case
            } else if(wt[i-1] > w) {
                dp[i][w] = dp[i-1][w]; // Item can't be included
            } else {
                // Return the maximum of including or excluding the item
                dp[i][w] = max(val[i-1] + dp[i-1][w - wt[i-1]], dp[i-1][w]);
            }
        }
    }
} 

int main() {
    int W = 50; // Maximum weight
    vector<int> wt = {10, 20, 30}; // Weights of items
    vector<int> val = {60, 100, 120}; // Values of items
    int n = val.size(); // Number of items

    cout << "Maximum value in Knapsack = " << knapsack(W, wt, val, n) << endl;
    return 0;
}

// Time Complexity: O(n * W)
// Space Complexity: O(n * W) for the dp array
// Note: The code above is a memoized version of the Knapsack problem.
// It uses a 2D array to store the results of subproblems to avoid recomputation.
// The function returns the maximum value that can be put in a knapsack of capacity W.
