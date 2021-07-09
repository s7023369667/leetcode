from typing import List

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        start,end=0,len(nums)-1
        if target not in nums:
            return [-1,-1]
        for i in range(len(nums)):
            if nums[i]==target:
                start += i
                break
        nums = nums[::-1]
        for i in range(len(nums)):
            if nums[i]==target:
                end-=i
                break
        return [start,end]