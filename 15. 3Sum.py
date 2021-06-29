from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        nums = sorted(nums)
        sum3 = 0
        L1 = 0
        R1 = n - 1
        ans = []
        while L1 < R1:
            L2 = L1 + 1
            R1 = n - 1
            while L2 < R1:
                sum3 = nums[L1] + nums[L2] + nums[R1]
                if sum3 == 0:
                    temp = [nums[L1], nums[L2], nums[R1]]
                    if not temp in ans:
                        print(temp)
                        ans.append(temp)
                    L2 += 1
                    R1 -= 1
                elif sum3 < 0:
                    L2 += 1
                else:
                    R1 -= 1
            L1 += 1
        return ans


