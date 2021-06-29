from typing import List


class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        #binary search for finding the index of the exist target
        if target in nums:
            return nums.index(target)
        else:
            l = len(nums)
            mid = nums[l // 2]
            temp = nums
            while l !=  1:
                if target < mid:
                    temp = temp[:temp.index(mid)]
                    l = len(temp)
                    mid = temp[l // 2]
                else:
                    temp = temp[temp.index(mid):]
                    l = len(temp)
                    mid = temp[l // 2]
            if target>=mid:
                return nums.index(mid) + 1
            else:
                return nums.index(mid)
