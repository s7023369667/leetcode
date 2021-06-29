from typing import List


class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        # L:left pointer
        L = 0
        # R:right pointer
        R = len(matrix) - 1
        # if left pointer is over than right pointer,we know we are done.
        while L < R:
            self._rotate(matrix, L, R)
            L += 1
            R -= 1

    def _rotate(self, matrix: List[List[int]], L: int, R: int) -> List[List[int]]:
        # Give 4 pointer
        # T:Top
        # B:Bottom
        T, B = L, R
        '''
        ---L+1-->        <---R-1--
        |                       ^
        v                       |
        T+1                    B-1
        '''
        for i in range(R - L):
            # Doing the rotation by "reverst order" to make code easily.
            # save the (top,left)
            TOPLEFT = matrix[T][L + i]
            # move the (bottom,left) to (top,left)
            matrix[T][L + i] = matrix[B - i][L]
            # move the (bottom,right) to (bottom,left)
            matrix[B - i][L] = matrix[B][R - i]
            # move the (top,right) to (bottom,right)
            matrix[B][R - i] = matrix[T + i][R]
            # move TOPLEFT to (top,left)
            matrix[T + i][R] = TOPLEFT
        return matrix



