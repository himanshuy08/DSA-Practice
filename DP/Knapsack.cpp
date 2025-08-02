#include<iostream>
#include<vector>
using namespace std;

int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    
    if(W==0 || n==0) return 0; // Base case

    if(wt[n-1] > W){
        return knapsack(W, wt, val, n-1); // Item can't be included
    } else {
        // Return the maximum of including or excluding the item
        return max(val[n-1] + knapsack(W - wt[n-1], wt, val, n-1), 
                   knapsack(W, wt, val, n-1));
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

