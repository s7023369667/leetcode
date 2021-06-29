from typing import List


class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        if obstacleGrid[0][0] == 1:
            return 0
        rows, cols = len(obstacleGrid), len(obstacleGrid[0])
        ####initial the start place as "1".
        obstacleGrid[0][0] = 1
        for i in range(1, cols):
            if obstacleGrid[0][i] == 0:
                ###equal to the top of itself.
                obstacleGrid[0][i] = obstacleGrid[0][i - 1]
            else:
                ###if it is a wall,then we give "0".
                obstacleGrid[0][i] = 0
        for j in range(1, rows):
            if obstacleGrid[j][0] == 0:
                ###equal to the left of itself.
                obstacleGrid[j][0] = obstacleGrid[j - 1][0]
            else:
                obstacleGrid[j][0] = 0
        print(obstacleGrid)
        for i in range(1, rows):
            for j in range(1, cols):
                if obstacleGrid[i][j] == 0:
                    ###equal to the left plus the top of itself.
                    obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1]
                else:
                    obstacleGrid[i][j] = 0
        print(obstacleGrid)
        return obstacleGrid[rows - 1][cols - 1]

        # [[8, 4, 4,  1],
        #  [4,-1, 3,  1],
        #  [4, 3, 2,  1],
        #  [1, 1, 1,  0]

