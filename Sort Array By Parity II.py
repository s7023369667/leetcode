from typing import List


class Solution:
    def sortArrayByParityII(self, nums: List[int]) -> List[int]:
        odd, even = [], []
        for n in nums:
            if n % 2 == 0:
                even.append(n)
            else:
                odd.append(n)
        ans = []
        for i in range(len(nums)):
            if (i % 2) == 0:
                ans.append(even.pop())
            else:
                ans.append(odd.pop())
        return ans
