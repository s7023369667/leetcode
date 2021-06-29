from typing import List


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # 因為是兩個sorted list 所以用merget sort
        concate = []
        i = j = 0
        # 先一個一個比大小放入新的list,#假定兩者的長度相同
        while i < len(nums1) and j < len(nums2):
            if nums1[i] <= nums2[j]:
                concate.append(nums1[i])
                i += 1
            else:
                concate.append(nums2[j])
                j += 1
        # 確認是否還有剩下的
        while i != len(nums1):
            concate.append(nums1[i])
            i += 1
        while j != len(nums2):
            concate.append(nums2[j])
            j += 1
        median = 0
        if len(concate) % 2 != 0:
            median = concate[len(concate) // 2]
            median = format(median, '.5f')  # 取五位小數點
            median = float(median)  # 型態轉成浮點
            # [1,2,3,4,5]
        else:
            median = (concate[len(concate) // 2] + concate[len(concate) // 2 - 1]) / 2
            median = format(median, '.5f')
            median = float(median)
            # [1,2,3,4]
        return median






