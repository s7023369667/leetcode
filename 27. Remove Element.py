from typing import List


class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        #         if not val in nums:
        #             return len(nums)
        #         else:
        #             while True:
        #                 if val in nums:
        #                     for i in nums:
        #                         if i==val:
        #                             x=nums.pop(nums.index(i))
        #                         else:
        #                             continue
        #                 else:
        #                     break
        #             return len(nums)
        cnt = 0
        for i in range(len(nums)):
            if nums[i] != val:
                # give the brand new nums by replace the different numbers
                nums[cnt] = nums[i]
                print("nums[cnt]:", nums[cnt])
                print("nums[i]:", nums[i])
                cnt += 1
        return cnt

# [0,1,2,2,3,0,4,2]
# 2
# nums[cnt]: 0
# nums[i]: 0
# nums[cnt]: 1
# nums[i]: 1
# nums[cnt]: 3
# nums[i]: 3
# nums[cnt]: 0
# nums[i]: 0
# nums[cnt]: 4
# nums[i]: 4
#
# [0,1,3,0,4]

