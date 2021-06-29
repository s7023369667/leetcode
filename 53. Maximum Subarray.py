from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # DP solution
        # case1 : "I" am the best solution.
        # case2 : "The last solution + Me" would be the best solution.
        '''Initialize the DP Table '''
        dp = [0] * len(nums)
        dp[0] = nums[0]
        max_sum = dp[0]
        for i in range(1, len(nums)):
            if nums[i] >= max_sum:
                max_sum = nums[i]
                if nums[i] < max_sum:
                    dp[i] = nums[i]
                else:
                    if nums[i] >= nums[i] + dp[i - 1]:
                        dp[i] = nums[i]
                    else:
                        max_sum = nums[i] + dp[i - 1]
                        dp[i] = nums[i] + dp[i - 1]
            else:
                if nums[i] + dp[i - 1] < max_sum:
                    # max_sum remain the same
                    if nums[i] + dp[i - 1] >= nums[i]:
                        dp[i] = nums[i] + dp[i - 1]
                    else:
                        dp[i] = nums[i]
                else:
                    max_sum = nums[i] + dp[i - 1]
                    dp[i] = nums[i] + dp[i - 1]
        return max_sum
