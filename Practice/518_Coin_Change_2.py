from typing import List

class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        cache = {}

        def dfs(i, a):
            if a == amount:
                return 1

            if a > amount or i == len(coins):
                return 0
            
            if (i, a) in cache:
                return cache[(i, a)]

            # Consider using the current coin and move to the next index
            use_coin = dfs(i, a + coins[i])
            
            # Skip using the current coin and move to the next index
            skip_coin = dfs(i + 1, a)
            
            # Store the result in the cache and return
            cache[(i, a)] = use_coin + skip_coin
            return cache[(i, a)]

        return dfs(0, 0)

