from typing import List

class Solution:
    ans = []

    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        def backtrack(s, start, arr):
            # print(arr)
            if s == target:
                return res.append(list(arr))
            if s > target or start >= len(candidates):
                return
            ##每次都先重複做自己
            s += candidates[start]
            arr.append(candidates[start])
            backtrack(s, start, arr)
            ##發現自己不能完成target後慢慢加進其他人來試看看
            s -= candidates[start]
            arr.pop()
            backtrack(s, start + 1, arr)

        res = []
        backtrack(0, 0, [])
        return res
        # [2,3,4,5]
        # 9
        # [[2,2,2,3],[2,2,5],[2,3,4],[3,3,3],[4,5]]

