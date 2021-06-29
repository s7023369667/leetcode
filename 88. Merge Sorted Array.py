from typing import List


class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        i = j = 0
        while i < m and n > 0:
            if nums1[i] > nums2[j]:
                nums1[i], nums2[j] = nums2[j], nums1[i]  # switch two items.
                for k in range(1, n):  # we always have to sort nums2
                    if nums2[k - 1] > nums2[k]:
                        nums2[k - 1], nums2[k] = nums2[k], nums2[k - 1]
                    else:
                        break
                print(nums1)
            i += 1
            print(nums1)
            print("nums2:", nums2)
        for j in range(n):
            nums1[i + j] = nums2[j]

