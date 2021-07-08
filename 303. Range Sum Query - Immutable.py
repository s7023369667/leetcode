from typing import List


class NumArray:
    # Your NumArray object will be instantiated and called as such:
    # obj = NumArray(nums)
    # param_1 = obj.sumRange(left,right)

    def __init__(self, nums: List[int]):
        self.nums = nums
        self.arr = [0] * len(self.nums)
        self.arr[0] = self.nums[0]
        ##arr is going to save the val addup from index 0 to i
        for i in range(1, len(self.nums)):
            self.arr[i] = self.nums[i] + self.arr[i - 1]
        # print(self.arr)

    def sumRange(self, left: int, right: int) -> int:
        if left - 1 < 0:
            return self.arr[right]
        ##sumRange(2,5) = arr[5]-arr[2-1]
        return self.arr[right] - self.arr[left - 1]

    def sumRange_native(self, left: int, right: int) -> int:
        addup = 0
        for idx in range(left, right + 1):
            addup += self.nums[idx]
        return addup

