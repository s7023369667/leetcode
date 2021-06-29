from typing import List


class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = [[]]
        for n in nums:
            for i in range(len(res)):
                if not res[i] + [n] in res:
                    res.append(res[i] + [n])
        return res

