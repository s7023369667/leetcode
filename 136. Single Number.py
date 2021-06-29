from collections import Counter
from typing import List


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ##Collections中有一個容器，專門用對字串、list做hash table且回傳的是一個字典
        cnt = Counter(nums)
        # print(cnt)
        for item, val in cnt.items():
            print(type(item))
            # print(f'{item}:{val}')
            if val == 1:
                return item



