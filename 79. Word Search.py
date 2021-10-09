from typing import List


class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:

        def _track(i, j, idx):
            '''
            print(i,j,idx)
            for k in is_visited:
                print(k)
            '''
            if i < 0 or j < 0 or i >= row or j >= col or idx >= w_len:
                return False
            if is_visited[i][j] or board[i][j] != word[idx]:
                return False
            if idx == w_len - 1:
                return True
            is_visited[i][j] = True
            if _track(i, j + 1, idx + 1) or _track(i, j - 1, idx + 1) or _track(i - 1, j, idx + 1) or _track(i + 1, j,
                                                                                                             idx + 1):
                return True
            is_visited[i][j] = False
            return False

        row, col, w_len = len(board), len(board[0]), len(word)
        is_visited = [[False] * col for _ in range(row)]
        for i in range(row):
            for j in range(col):
                if _track(i, j, 0):
                    return True
        return False

