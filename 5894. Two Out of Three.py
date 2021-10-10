from typing import List


class Solution:
    def twoOutOfThree(self, nums1: List[int], nums2: List[int], nums3: List[int]) -> List[int]:
        sets = [set(nums1),set(nums2),set(nums3)]
        ans=[]
        d={}
        for s in sets:
            for i in s:
                if i not in d:
                    d[i]=1
                else:
                    d[i]+=1
        for key,val in d.items():
            if val>=2:
                ans.append(key)
        return ans


if __name__ == '__main__':
    nums1 = [1, 2,2]
    nums2 = [4,3,3]
    nums3 = [5]
    s = Solution()
    s.twoOutOfThree(nums1,nums2,nums3)