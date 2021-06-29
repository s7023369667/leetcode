from typing import List


class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        n = len(nums)
        L1 = 0  # first time index
        R2 = n - 2  # first time index
        nums = sorted(nums)
        sum4 = 0
        ans = []
        while L1 < R2:
            L2 = L1 + 1
            R1 = n - 1
            while L2 < R1:
                L2 = L1 + 1
                R2 = R1 - 1
                while L2 < R2:  # not L2=R2
                    sum4 = nums[L1] + nums[L2] + nums[R2] + nums[R1]
                    if sum4 == target:
                        temp = [nums[L1], nums[L2], nums[R2], nums[R1]]
                        if not temp in ans:
                            ans.append(temp)
                        L2 = L2 + 1
                        R2 = R2 - 1
                    elif sum4 < target:
                        L2 += 1
                    else:
                        R2 -= 1
                R1 -= 1
            L1 += 1
        return ans








