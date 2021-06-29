from typing import List


class Solution:
    def jump(self, nums: List[int]) -> int:
        ####Find the minimum number of jumps to reach the last index?
        step, place = 0, 0
        jump = True
        if len(nums) < 2:
            return step
        while place < len(nums) and jump:
            jump_index = nums[place]
            if jump_index > len(nums) - 1:
                step += 1
                break
            else:
                if jump_index > 0 and jump_index < len(nums) - place:
                    temp, p, jump = -1, 0, True
                    step += 1
                    print("TTT")
                    ###for each move from 1 to jump_index,find the maximum moving method.
                    for i in range(1, jump_index + 1):
                        if nums[i + place] > temp:
                            temp = nums[i + place]
                            p = i
                    place = p + place
                    print(place)
                    if place > len(nums) - 1:
                        break
                else:
                    jump = False
        print(step)
        return step




