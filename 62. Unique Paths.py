from typing import List


class Solution:
    def uniquePaths(self, m: int, n: int) -> int:

        ######DP-Approach:
        matrix=[[0 for i in range(n)] for j in range(m)]
        for i in range(m):
            matrix[i][0]=1
        for i in range(n):
            matrix[0][i]=1
        for i in range(1,m):
            for j in range(1,n):
                matrix[i][j] = matrix[i-1][j] + matrix[i][j-1]
        print(matrix)
        return matrix[m-1][n-1]


            # [[0,1,1,1,1,1,1],
            #  [1,2,3,4,5,6,7],
            #  [1,3,6,10,15,21,28]]

        ######DFS-Approach:
        # matrix = [[0 for i in range(n)] for j in range(m)]
        # return self.DFS_uniquePaths(matrix, m - 1, n - 1, 0, 0)

    def DFS_uniquePaths(self, matrix: List[List[int]], B: int, R: int, T: int, L: int) -> int:
        if T > B or L > R:
            return 0
        if T == B or L == R:
            matrix[T][L] = 1
            return matrix[T][L]
        if matrix[T][L] != 0:
            return matrix[T][L]
        takeRight = self.DFS_uniquePaths(matrix, B, R, T, L + 1)
        takeDown = self.DFS_uniquePaths(matrix, B, R, T + 1, L)
        matrix[T][L] = takeRight + takeDown
        print(matrix)
        return matrix[T][L]

    '''
     matrix=[["28", 21, 15, 10, 6, 3,  1], 
             [  7 ,  6,  5,  4, 3, 2,  1], 
             [  1 ,  1,  1,  1, 1, 1, "0"]]
    '''


