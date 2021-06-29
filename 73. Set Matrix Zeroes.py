from typing import List


class Solution:
    def setZeroes_1(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        ###Method1:
        B, R = len(matrix), len(matrix[0])
        set_row, set_col = set(), set()
        for row in range(B):
            for col in range(R):
                if matrix[row][col] == 0:
                    ######save the index of the rows/cols that we need to do setting.
                    set_row.add(row)
                    set_col.add(col)
        while set_row:
            temp = set_row.pop()
            for col in range(R):
                matrix[temp][col] = 0
        while set_col:
            temp = set_col.pop()
            for row in range(B):
                matrix[row][temp] = 0

    def setZeroes_2(self, matrix: List[List[int]]) -> None:
        ####Method2:

        R,B=len(matrix[0]),len(matrix)
        mark = float('inf')
        matrix , haveMarks = self.markZeros(matrix,B,R)
        if not haveMarks:return
        for row in range(B):
            change_row = False
            for col in range(R):
                if matrix[row][col] == mark:
                    #We know this row has to be setting to zeros.
                    change_row=True
                    #Set the current visit to zero.
                    matrix[row][col]=0
                    for i in range(B):
                    ####Stop setting while we visiting the "marks",otherwise we lose our "marks".
                        if matrix[i][col]==mark:
                            break
                        else:
                            matrix[i][col]=0
            if change_row:
                for c in range(R):
                    ####Stop setting while we visiting the "marks",otherwise we lose our "marks".
                    if matrix[row][c]==mark:
                        break
                    else:
                        matrix[row][c]=0
    def markZeros(self,matrix,B,R):
        ##Quickly check if there is any "mark".
        haveMarks = False
        for row in range(B):
            for col in range(R):
                if matrix[row][col] == 0:
                    haveMarks = True
                    ##Mark it as the positive infinity.
                    matrix[row][col] = float('inf')
        return matrix , haveMarks

