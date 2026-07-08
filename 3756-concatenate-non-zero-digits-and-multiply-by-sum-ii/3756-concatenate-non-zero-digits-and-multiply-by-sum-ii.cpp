class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        long long MOD = 1000000007;

        // Precompute arrays (1-based indexing for easier prefix calculations)
        vector<long long> pow10(n + 1, 1);
        vector<long long> prefixSum(n + 1, 0);
        vector<int> nonZeroCount(n + 1, 0);
        vector<long long> val(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pow10[i + 1] = (pow10[i] * 10) % MOD;
            int digit = s[i] - '0';
            
            prefixSum[i + 1] = prefixSum[i] + digit;
            
            if (digit != 0) {
                nonZeroCount[i + 1] = nonZeroCount[i] + 1;
                // Append digit to the running concatenated number
                val[i + 1] = (val[i] * 10 + digit) % MOD;
            } else {
                nonZeroCount[i + 1] = nonZeroCount[i];
                val[i + 1] = val[i]; // Value doesn't change on '0'
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            
            // 1. Calculate sum of digits in O(1)
            long long sum = prefixSum[r + 1] - prefixSum[l];
            
            // 2. Number of non-zero digits in this substring
            int k = nonZeroCount[r + 1] - nonZeroCount[l];
            
            // 3. Calculate x using modular arithmetic
            long long x = (val[r + 1] - (val[l] * pow10[k]) % MOD) % MOD;
            
            // In C++, modulo of a negative number is negative, so we adjust it
            if (x < 0) {
                x += MOD;
            }
            
            // 4. Multiply and push to answer
            long long currentAns = (x * (sum % MOD)) % MOD;
            ans.push_back(currentAns);
        }

        return ans;
    }
};