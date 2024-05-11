/*
  ><><>< BURAK DENIZ KARAKAYA ><><><
  ><><>< 221504036 ><><><

*/
#include <iostream>
#include <vector>
using namespace std;

// Function to find the number of sequences
int sequenceCount(int rows, int cols) {
    vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));
    
    // Initialize the first column
    for (int i = 1; i <= rows; i++) {
        dp[i][1] = 1;
    }
    
    // Fill the DP table
    for (int i = 2; i <= cols; i++) {
        for (int j = 1; j <= rows; j++) {
            for (int k = 1; k <= j / 2; k++) {
                dp[j][i] += dp[k][i - 1];
            }
        }
    }
    
    // Calculate the total number of sequences
    int totalCount = 0;
    for (int i = 1; i <= rows; i++) {
        totalCount += dp[i][cols];
    }
    
    return totalCount;
}

int main() {
    int rows1 = 10, cols1 = 4;
    cout << "Output for rows = 10, cols = 4: " << sequenceCount(rows1, cols1) << endl;

    int rows2 = 5, cols2 = 2;
    cout << "Output for rows = 5, cols = 2: " << sequenceCount(rows2, cols2) << endl;

    return 0;
}
