'''
Given an array of integers nums and an integer target,
return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution,
and you may not use the same element twice.

You can return the answer in any order

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
'''
def twoSum( nums, target):
    idex=set()
    d=len(nums)
    for i in range(d):
        for j in range(i+1,d):
             if nums[i]+nums[j] == target:
                idex.add(i)
                idex.add(j)
                return idex



print(twoSum([0,4,3,0],0))
print(twoSum([3,3],6))
print(twoSum([1,2,3,4],7))
print(twoSum([2,7,11,15],9))

''' 
  1 2 3 4
1 X 3 4 5
2 3 X 5 6
3 6 7 X 9
4 5 6 7 X
'''

