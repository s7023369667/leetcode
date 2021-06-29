from typing import List


class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(9):
            if not self.checkRow(board, i):
                print("Error in Row")
                return False
        for i in range(9):
            if not self.checkLine(board, i):
                print("Error in line")
                return False
        for i in range(0, 9, 3):
            for j in range(0, 9, 3):
                if not self.checkSquare(board, i, j):
                    print("Error in Square")
                    return False
        return True

    def checkSquare(self, board: List[List[int]], T: int, L: int) -> bool:
        # square=[]
        # creat a hash table to count exist digit in square.
        h_table = [0] * 10
        for i in range(T, T + 3):
            for j in range(L, L + 3):
                # square.append(board[i][j])
                if not board[i][j] == ".":
                    h_table[int(board[i][j])] += 1
        for item in h_table[1:]:
            if item > 1:
                return False
        return True

    def checkRow(self, board: List[List[int]], T: int) -> bool:
        row = []
        h_table = [0] * 10
        for col in range(9):
            row.append(board[T][col])
            if not board[T][col] == ".":
                h_table[int(board[T][col])] += 1
        print(row)
        for item in h_table[1:]:
            if item > 1:
                return False
        return True

    def checkLine(self, board: List[List[int]], L: int) -> bool:
        # line=[]
        h_table = [0] * 10
        for row in range(9):
            # line.append(board[row][L])
            if not board[row][L] == ".":
                h_table[int(board[row][L])] += 1
        # print(line)
        # print(h_table)
        for item in h_table[1:]:
            if item > 1:
                return False
        return True






