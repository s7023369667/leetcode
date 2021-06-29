class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x > 0:
            temp = []
            while x % 10 != 0 or x // 10 != 0:
                temp.append(x % 10)
                x = x // 10
            if temp == temp[::-1]:
                return True
        elif x == 0:
            return True
        else:
            return False

