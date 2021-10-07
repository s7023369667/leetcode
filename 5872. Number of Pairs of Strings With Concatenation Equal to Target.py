from typing import List


class Solution:
    def numOfPairs(self, nums: List[str], target: str) -> int:
        cnt=0
        for i in range(len(nums)):
            for j in range(len(nums)):
                if j==i:
                    continue
                if nums[i]+nums[j] == target:
                    cnt+=1

        return cnt


if __name__ == '__main__':
    # nums =  ["777","7","77","77"]
    # target = "7777"
    # nums =  ["123","4","12","34"]
    # target = "1234"
    nums = ["74","1","67","1","74"]
    target = "174"
    s=Solution()
    print(s.numOfPairs(nums,target))