from typing import List


class Solution:
    def shiftingLetters(self, s: str, shifts: List[int]) -> str:
        for i in range(len(shifts) - 2, -1, -1):
            shifts[i] += shifts[i + 1]
            shifts[i] = shifts[i] % 26

        ans = ''
        for i in range(len(s)):
            tmp = ord('a') + (ord(s[i]) - ord('a') + shifts[i]) % 26
            ans += chr(tmp)
        return ans
