from typing import List


class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        n = len(nums)
        nums = sorted(nums)
        sum3 = 0
        L1 = 0
        R1 = n - 1
        ans = 10 ** 3
        out = 0
        while L1 < R1:
            L2 = L1 + 1
            R1 = n - 1
            while L2 < R1:
                sum3 = nums[L1] + nums[L2] + nums[R1]
                if sum3 < target:
                    L2 += 1
                else:
                    R1 -= 1
                if abs(sum3 - target) < ans:
                    ans = abs(sum3 - target)
                    out = sum3
            L1 += 1
        return out

