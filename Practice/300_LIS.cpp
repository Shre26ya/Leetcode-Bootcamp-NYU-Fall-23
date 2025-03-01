class Solution {
public:
    int t[2501][2501];  // Memoization table

    int solve(vector<int> &nums, int i, int P){
        // Base case: if we reach the end of the array
        if (i >= nums.size()) {
            return 0;
        }

        // Memoization check
        if (P != -1 && t[i][P] != -1) {
            return t[i][P];
        }

        int take = 0;

        // If we can take this element (it is greater than the previous one in LIS)
        if (P == -1 || nums[i] > nums[P]) {
            take = 1 + solve(nums, i + 1, i);
        }

        // Skip the current element
        int skip = solve(nums, i + 1, P);

        // Store the result in DP table only if P is valid
        if (P != -1) {
            t[i][P] = max(take, skip);
        }

        return max(take, skip);
    }

    int lengthOfLIS(vector<int> &nums) {
        memset(t, -1, sizeof(t));  // Initialize DP table with -1
        return solve(nums, 0, -1);
    }
};

