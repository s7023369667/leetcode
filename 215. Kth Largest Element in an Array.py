from typing import List

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        return self.quick_sort(nums, 0, len(nums) - 1)[-k]

    def middle_of_three(self, nums, front, end) -> int:
        ##The goal is to find the best pivot to avoid the worst case.
        m, f, e = 0, 0, 0
        middle = (front + end) // 2
        pivot = nums[end]
        if pivot > nums[middle]:
            m = 1
            pivot = nums[middle]
        elif pivot > nums[front]:
            m = 0
            f = 1
            pivot = nums[front]
        else:
            m = 0
            f = 0
            e = 1
        if m:
            nums[middle], nums[end] = nums[end], nums[middle]
        elif f:
            nums[front], nums[end] = nums[end], nums[front]
        return nums[end]

    def partition(self, nums, front, end) -> int:
        pivot = self.middle_of_three(nums, front, end)
        i = front - 1
        for j in range(front, end):
            if nums[j] < pivot:
                i += 1
                nums[i], nums[j] = nums[j], nums[i]
        nums[i + 1], nums[end] = pivot, nums[i + 1]
        return i + 1

    def quick_sort(self, nums, front, end) -> List[int]:
        if front < end:
            pivot_index = self.partition(nums, front, end)
            self.quick_sort(nums, front, pivot_index - 1)
            self.quick_sort(nums, pivot_index + 1, end)
        return nums



'''
Middle-of-Three 方法

(1) 令 middle = (front + end) //2

(2) 比較 nums[front]、nums[middle] 與 nums[end] 這三筆資料，排出中間值。

(3) 將此中間值再與 nums[end] 做交換，作為新的 pivot
'''