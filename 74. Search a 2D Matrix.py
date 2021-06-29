from typing import List


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        B, R = len(matrix), len(matrix[0])
        T = 0
        while T < B:
            if target >= matrix[T][0] and target <= matrix[T][R - 1]:
                L = 0
                while L < R:
                    if matrix[T][L] == target:
                        return True
                    L += 1
            T += 1

