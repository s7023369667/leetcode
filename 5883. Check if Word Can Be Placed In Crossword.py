from typing import List


class Solution:
    def placeWordInCrossword(self, board: List[List[str]], word: str) -> bool:
        # def _help(sub_board,word):
        #     for row in range(len(sub_board)):
        #         for col in range(len(sub_board[row])):
        #
        #             # if sub_board[row][col] == " " :
        #

            return True

if __name__ == '__main__':
    board = [["#", " ", "#"], [" ", " ", "#"], ["#", " ", "c"]]
    word = "ca"
    s= Solution()
    print(s.placeWordInCrossword(board,word))

