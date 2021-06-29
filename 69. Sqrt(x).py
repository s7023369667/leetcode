class Solution:
    def mySqrt(self, x: int) -> int:
        # Use Binary Search to find square root
        left, right = 0, x
        while left <= right:
            # if left is over than right ,than "left-1" is the answer.
            mid = (left + right) // 2
            if mid * mid < x:  # lower bound
                left = mid + 1
            elif mid * mid == x:
                return mid
            else:  # upper bound
                right = mid - 1
        return left - 1







