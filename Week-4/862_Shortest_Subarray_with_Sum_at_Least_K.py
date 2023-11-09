class Solution:
    def shortestSubarray(self, nums: List[int], k: int) -> int:
        loc = {0: -1}
        stack = [0] # increasing stack
        ans, prefix = inf, 0
        for i, x in enumerate(nums): 
            prefix += x
            ii = bisect_right(stack, prefix - k)
            if ii: ans = min(ans, i - loc[stack[ii-1]])
            loc[prefix] = i
            while stack and stack[-1] >= prefix: stack.pop()
            stack.append(prefix)
        return ans if ans < inf else -1
