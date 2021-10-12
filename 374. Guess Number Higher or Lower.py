# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
def guess(num: int) -> int:
    ##pre-defined
    pass

class Solution:
    def guessNumber(self, n: int) -> int:
        def _bs(l, r):
            mid = (l + r) // 2
            if guess(mid) == 0:
                return mid
            elif guess(mid) == -1:
                return _bs(l, mid - 1)
            elif guess(mid) == 1:
                return _bs(mid + 1, r)

        return _bs(1, n)
