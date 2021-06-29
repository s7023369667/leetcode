from typing import List


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        return self._permute(nums)

    def _permute(self, nums: List[int]) -> List[List[int]]:
        if len(nums) == 0:
            return []
        if len(nums) == 1:
            return [nums]
        if len(nums) == 2:
            return [[nums[0], nums[1]], [nums[1], nums[0]]]
        else:
            ans = []
            for i in range(len(nums) - 1, -1, -1):
                nums[-1], nums[i] = nums[i], nums[-1]  # swap the last one and  nums[i]
                for each in self._permute(nums[:len(nums) - 1]):
                    # we do sub_permutation without the one with swapped,
                    # and add it back to the answer list
                    each.append(nums[-1])
                    ans.append(each)
            return ans












