class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Sort the array to bring duplicates next to each other
        sort(nums.begin(), nums.end());
        
        // Check for duplicates in sorted array
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                return true; // Found a duplicate
            }
        }
        return false; // No duplicates found
    }
};

