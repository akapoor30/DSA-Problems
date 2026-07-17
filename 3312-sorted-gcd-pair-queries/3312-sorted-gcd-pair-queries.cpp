class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int max_val = 0;
        for (int num : nums) {
            max_val = max(max_val, num);
        }

        // Step 1: Count frequencies of each number
        vector<long long> count(max_val + 1, 0);
        for (int num : nums) {
            count[num]++;
        }

        // gcd_pairs[i] will store the exact number of pairs with GCD == i
        vector<long long> gcd_pairs(max_val + 1, 0);

        // Step 2 & 3: Iterate backwards to compute exact GCDs
        for (int i = max_val; i >= 1; i--) {
            long long multiples_count = 0;
            // Count how many numbers are multiples of i
            for (int j = i; j <= max_val; j += i) {
                multiples_count += count[j];
            }
            
            // Total pairs where both elements are multiples of i
            long long pairs = multiples_count * (multiples_count - 1) / 2;
            
            // Subtract the pairs whose GCD is a strict multiple of i
            for (int j = 2 * i; j <= max_val; j += i) {
                pairs -= gcd_pairs[j];
            }
            
            gcd_pairs[i] = pairs;
        }

        // Step 4: Prefix sums to find ranges
        vector<long long> prefix_sums(max_val + 1, 0);
        for (int i = 1; i <= max_val; i++) {
            prefix_sums[i] = prefix_sums[i - 1] + gcd_pairs[i];
        }

        // Step 5: Answer queries using binary search
        vector<int> ans;
        for (long long q : queries) {
            // Find the first index where prefix_sums > q
            int l = 1, r = max_val;
            int res = max_val;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (prefix_sums[mid] > q) {
                    res = mid;
                    r = mid - 1; // Try to find a smaller valid GCD
                } else {
                    l = mid + 1; // Go higher
                }
            }
            ans.push_back(res);
        }

        return ans;
    }
};