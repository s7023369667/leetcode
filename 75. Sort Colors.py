from typing import List


class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        ####Selection sort.
        for i in range(len(nums)):
            min_ = i
            print(nums[min_])
            for j in range(i + 1, len(nums)):
                if nums[j] < nums[min_]:
                    min_ = j
                    print("j:", nums[min_])
            nums[i], nums[min_] = nums[min_], nums[i]


