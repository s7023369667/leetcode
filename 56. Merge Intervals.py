from typing import List


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        L = 0
        R = 1
        i = 0
        intervals = sorted(intervals)
        while i < len(intervals) - 1:
            temp = []
            while i + 1 < len(intervals) and intervals[i][R] >= intervals[i + 1][L]:
                ###Determinate left side of temp.
                if intervals[i][L] <= intervals[i + 1][L]:
                    temp = [intervals[i][L]]
                else:
                    temp = [intervals[i + 1][L]]
                ###Determinate right side of temp.
                if intervals[i][R] <= intervals[i + 1][R]:
                    temp += [intervals[i + 1][R]]
                else:
                    temp += [intervals[i][R]]
                intervals[i] = temp
                intervals = intervals[:i + 1] + intervals[i + 2:]
            i += 1
        return intervals

        # 1,2,3,...,i,"i+1",i+2,i+3,...,i+k
        # intervale[:i+1] :  1,2,3,...,i
        # intervals[i+2:] : i+2,i+3,...,i+k






