from typing import List


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        '''
    Each element in the array represents your maximum jump length at that position.
        so if element is 3: you can jump 1,2,3 to reach the last index of nums.
        '''
        if len(nums) == 1:
            return True
        maxx = 0
        ###Our maximum moving distance is the length of nums.
        for i in range(len(nums)):
            maxx = max(maxx, i + nums[i])
            # i represent as the previous moving index.
            # i+nums[i] represent as the current moving index.
            if maxx >= len(nums) - 1:
                # if we could reach to the last element,we are done.
                return True
            if maxx == i:
                # if the current move is same as the previous moving distance,
                # which means we are not moving
                print("Fatal Error.")
                return False
        return False

        #     ###TRUE CONDITION:
        # if len(nums)==1:
        #     #Reach to the last element.
        #     return True
        # if nums[0]>=len(nums)-1:
        #     #We can easy move to the last element.
        #     print("True Move")
        #     return True
        #     #Checking each steps.
        # for i in range(nums[0],0,-1):
        #     print("nums",nums[i:])
        #     if self.canJump(nums[i:]):
        #         print("True Trying")
        #         return True
        #     ###FALSE CONDITION:
        #     print("False Move")
        #     # continue
        #     # return False
        # return False






