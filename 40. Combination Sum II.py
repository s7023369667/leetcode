from collections import Counter
from typing import List


class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        def counting(arr):
            ##計算數量，如果超過數量給予False的flag
            flag = True
            c = Counter(arr)
            for item, val in c.items():
                if val > counter[item]:
                    flag = False
                    break
            return flag

        def backtrack(s, start, arr):
            if s == target and counting(list(arr)) and list(arr) not in res:
                ##檢查s是否等於target且arr中的每個個數數量小於我們的要求且arr不再res中
                res.append(list(arr))
                return
            if s > target or start >= len(candidates):
                return
            s += candidates[start]
            arr.append(candidates[start])
            backtrack(s, start, arr)

            s -= candidates[start]
            arr.pop()
            backtrack(s, start + 1, arr)

        res = []
        counter = dict(Counter(candidates))
        candidates.sort()
        check = 0
        for item, val in counter.items():
            check += int(item) * val
        if not check >= target:
            return []
        backtrack(0, 0, [])
        return res
