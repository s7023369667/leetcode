from typing import List

class NumMatrix:
    # Your NumMatrix object will be instantiated and called as such:
    # obj = NumMatrix(matrix)
    # param_1 = obj.sumRegion(row1,col1,row2,col2)
    def __init__(self, matrix: List[List[int]]):
        ##padding with zeros
        matrix = [[0]*(len(matrix[0])+1)]+matrix
        for i in range(1,len(matrix)):
            matrix[i] = [0]+matrix[i]
        ##addup the arezs
        for row in range(1,len(matrix)):
            matrix[row][0] += matrix[row-1][0]
        for col in range(1,len(matrix[0])):
            matrix[0][col] += matrix[0][col-1]
        for row in range(1,len(matrix)):
            for col in range(1,len(matrix[0])):
                yourself = matrix[row][col]
                up = matrix[row-1][col]
                left = matrix[row][col-1]
                overlap = matrix[row-1][col-1]
                matrix[row][col] = yourself+up+left-overlap
        self.matrix = matrix

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        row1,row2,col1,col2=row1+1,row2+1,col1+1,col2+1
        up=self.matrix[row1-1][col2]
        left = self.matrix[row2][col1-1]
        overlap=self.matrix[row1-1][col1-1]
        sum_region = self.matrix[row2][col2]-up-left+overlap
        return sum_region


