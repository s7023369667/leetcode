from typing import List


class Solution:
    def maxArea(self, height: List[int]) -> int:
        # We cannot sort the list.
        L, R, max_sum, h = 0, len(height) - 1, 0, 0
        while L < R:
            ####Two pointers at the front and last.
            area = R - L
            if height[R] >= height[L]:
                h = height[L]
                ###left pointer is smaller than right pointer,so we move left pointer.
                L += 1
            else:
                h = height[R]
                ###right pointer is smaller than left pointer,so we move right pointer.
                R -= 1
            # Update the max_sum area.
            if h * area > max_sum:
                max_sum = h * area
        return max_sum

