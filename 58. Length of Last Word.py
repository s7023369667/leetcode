class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        if not s:
            return 0
        else:
            temp = s.split()  # After split the string will be store in list.
            if temp:
                return len(temp[-1])
            else:
                return 0

