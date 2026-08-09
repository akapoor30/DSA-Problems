#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int stoneGameII(std::vector<int>& piles) {
        int n = piles.size();
        
        // Memoization table: memo[i][M]
        // i ranges from 0 to n, M ranges from 1 to n
        std::vector<std::vector<int>> memo(n + 1, std::vector<int>(n + 1, -1));
        
        // Precompute suffix sums to easily get sum of piles from i to end
        std::vector<int> suffixSum(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }
        
        return solve(0, 1, n, suffixSum, memo);
    }

private:
    int solve(int i, int M, int n, const std::vector<int>& suffixSum, std::vector<std::vector<int>>& memo) {
        // Base case: If remaining piles can all be taken in one turn
        if (i + 2 * M >= n) {
            return suffixSum[i];
        }
        
        if (memo[i][M] != -1) {
            return memo[i][M];
        }
        
        int maxStones = 0;
        
        // Try taking X piles where 1 <= X <= 2 * M
        for (int X = 1; X <= 2 * M; ++X) {
            // Current player's score = Total remaining stones - Next player's optimal score
            int currentStones = suffixSum[i] - solve(i + X, std::max(M, X), n, suffixSum, memo);
            maxStones = std::max(maxStones, currentStones);
        }
        
        return memo[i][M] = maxStones;
    }
};