from typing import List


class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        return self._permuteUnique(nums)

    def _permuteUnique(self, nums: List[int]) -> List[List[int]]:
        if len(nums) == 0:
            return []
        if len(nums) == 1:
            return [nums]
        if len(nums) == 2:
            if nums[0] == nums[1]:
                return [nums]
            else:
                return [[nums[0], nums[1]], [nums[1], nums[0]]]
        else:
            ans = []
            for i in range(len(nums) - 1, -1, -1):
                nums[-1], nums[i] = nums[i], nums[-1]
                for each in self._permuteUnique(nums[:len(nums) - 1]):
                    each.append(nums[-1])
                    if not each in ans:
                        ans.append(each)
            return ans