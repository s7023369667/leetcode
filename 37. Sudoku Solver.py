from typing import List


class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        self.backtracking(board, 0, 0)

    def backtracking(self, board: List[List[int]], row, col) -> bool:
        full_set = {"1", "2", "3", "4", "5", "6", "7", "8", "9"}
        if row == 9:
            return True
        if col == 9:
            return self.backtracking(board, row + 1, 0)
        for r in range(row, 9):
            for c in range(col, 9):
                if board[r][c] != ".":
                    return self.backtracking(board, r, c + 1)
                else:
                    ####check the subbox find out it's possible value.
                    subbox_set, flag_ = self.CheckSubBox(board, r, c)
                    # subbox_set is the set with the possible value of this blank in the subbox.
                    if not flag_:
                        # going to update the wrong answer.
                        return False
                    else:
                        ####check row:
                        _row_set = set()
                        # _row_set is the set with the possible value of this blank in the row.
                        for i in range(9):
                            if not board[r][i] == ".":
                                if board[r][i] not in _row_set:
                                    _row_set.add(board[r][i])
                                else:
                                    # going to update the wrong answer.
                                    return False
                        ####check line:
                        _line_set = set()
                        # _line_set is the set with the possible value of this blank in the line.
                        for i in range(9):
                            if not board[i][c] == ".":
                                if board[i][c] not in _line_set:
                                    _line_set.add(board[i][c])
                                else:
                                    # going to update the wrong answer.
                                    return False
                        # Find the possible_set
                        possible_set = full_set - subbox_set - _row_set - _line_set
                        ####Now filling the possible value into blank position
                        for value in possible_set:
                            board[r][c] = value
                            # Always check the neighbor,if they are vaild.
                            if self.backtracking(board, r, c + 1):
                                return True
                            else:
                                # not a vaild vlaue,so update to '.'
                                board[r][c] = "."
                        return False

        return True

    def CheckSubBox(self, board: List[List[int]], row: int, col: int):
        # Giving the specific position,return the subbox_set
        subbox_set = set()
        flag = True
        ####check square:
        i1 = i2 = j1 = j2 = 0
        ###determinate the index of the subbox.
        if row % 3 == 2:
            if col % 3 == 2:
                i1 = row - 2
                i2 = row + 1
                j1 = col - 2
                j2 = col + 1
            elif col % 3 == 1:
                i1 = row - 2
                i2 = row + 1
                j1 = col - 1
                j2 = col + 2
            elif col % 3 == 0:
                i1 = row - 2
                i2 = row + 1
                j1 = col
                j2 = col + 3
        elif row % 3 == 1:
            if col % 3 == 2:
                i1 = row - 1
                i2 = row + 2
                j1 = col - 2
                j2 = col + 1
            elif col % 3 == 1:
                i1 = row - 1
                i2 = row + 2
                j1 = col - 1
                j2 = col + 2
            elif col % 3 == 0:
                i1 = row - 1
                i2 = row + 2
                j1 = col
                j2 = col + 3
        elif row % 3 == 2:
            if col % 3 == 2:
                i1 = row
                i2 = row + 3
                j1 = col - 2
                j2 = col + 1
            elif col % 3 == 1:
                i1 = row
                i2 = row + 3
                j1 = col - 1
                j2 = col + 2
            elif col % 3 == 0:
                i1 = row
                i2 = row + 3
                j1 = col
                j2 = col + 3
        for r in range(i1, i2):
            for c in range(j1, j2):
                if not board[r][c] == ".":
                    if board[r][c] not in subbox_set:
                        subbox_set.add(board[r][c])
                    else:
                        # if means we got the wrong answer here.
                        flag = False
        # print(subbox_set)
        return subbox_set, flag





