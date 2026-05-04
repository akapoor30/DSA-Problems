class Solution {
public:
    // 1. Pass by reference (&) to avoid copying the table
    // 2. Fixed the vector template <vector<int>>
    int f(int i, int j, vector<vector<int>>& dp) {
        if (i == 0 && j == 0) return 1;
        if (i < 0 || j < 0) return 0;

        // 3. Return the value ONLY if it has been previously calculated
        if (dp[i][j] != -1) return dp[i][j];

        int up = f(i - 1, j, dp);
        int left = f(i, j - 1, dp);

        // Store the result in the dp table and return it
        return dp[i][j] = up + left;
    }

    int uniquePaths(int m, int n) {
        // Correct 2D vector initialization
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m - 1, n - 1, dp);
    }
};