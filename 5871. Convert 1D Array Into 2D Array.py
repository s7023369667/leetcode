from typing import List


class Solution:
    def construct2DArray(self, original: List[int], m: int, n: int) -> List[List[int]]:
        ans = []
        if not m*n==len(original):
            return ans
        for row in range(m):
            ans.append(original[:n])
            original = original[n:]
        return ans



if __name__ == '__main__':
    original = [1,2]
    m = 1
    n = 1
    s=Solution()
    print(s.construct2DArray(original,m,n))