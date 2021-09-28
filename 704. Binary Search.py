from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        def BS(nums, target, left, right):
            if not left <= right:
                return -1
            midd = (left + right) // 2
            if nums[midd] > target:
                return BS(nums, target, left, midd - 1)
            elif nums[midd] < target:
                return BS(nums, target, midd + 1, right)
            elif nums[midd] == target:
                return midd

        return BS(nums, target, 0, len(nums) - 1)

