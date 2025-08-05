#include<iostream>
#include<vector>
#include<string>
using namespace std;

void printLCS(vector<vector<int>>& dp, string X, string Y) {
    int i = X.length();
    int j = Y.length();
    string lcs = "";

    // Simple Code to print LCS
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs = X[i - 1] + lcs; // Append current character to LCS
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--; // Move up in the table
        } else {
            j--; // Move left in the table
        }
    }
    cout << "LCS: " << lcs << endl;
}

int LCS(string X, string Y) {
    int m = X.length();
    int n = Y.length();

    // Create a 2D table to store LCS length
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // Build the table in bottom-up fashion
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Print the DP table
    cout << "LCS DP Table:\n";
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }

    printLCS(dp, X, Y); // Call to print the LCS

    return dp[m][n]; // LCS length
}

int main() {
    string X = "AGGTAB";
    string Y = "GXTXAYB";

    int lcs_length = LCS(X, Y);
    cout << "Length of LCS: " << lcs_length << endl;

    return 0;
}

