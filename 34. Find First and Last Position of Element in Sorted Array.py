from typing import List


class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        l = [0] * 2
        if target not in nums:
            l[0] = -1
            l[1] = -1
            return l
        end = 0
        # for i in nums:
        #     for j in range(i + 1, len(nums)):
        #         if i == nums[j]:

