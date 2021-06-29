from typing import List


class Solution:
    ##參考維基百科：https://zh.wikipedia.org/wiki/%E6%A0%BC%E9%9B%B7%E7%A0%81
    def grayCode(self, n: int) -> List[int]:
        ans = []
        for i in self._help(n):
            ##把二進位轉回10進位到ans
            ans.append(int(i, 2))
        return ans

    def _help(self, n: int):
        if n == 1:
            return ['0', '1']
        upp, down = [], []
        for i in self._help(n - 1):
            upp.append('0' + i)
        for j in self._help(n - 1)[::-1]:
            down.append('1' + j)
        # print("upp:",upp)
        # print("down",down)
        return upp + down

    '''
    鏡射編碼：
        0   [0]0    [0]00
        1   [0]1    [0]01
            [1]1    [0]11
            [1]0    [0]10
                    [1]10
                    [1]11
                    [1]01
                    [1]00'''
