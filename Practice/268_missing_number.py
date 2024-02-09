class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        total = n * (n + 1) // 2  # Sum of first n natural numbers
        actual_sum = sum(nums)    # Sum of elements in the list
        return total - actual_sum  # The difference is the missing number
