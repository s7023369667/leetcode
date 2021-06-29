import collections
from collections import ValuesView
from typing import List


class Solution:
    def groupAnagrams_1(self, strs: List[str]) -> ValuesView[list]:
        # creat a default dictionary with list data type.
        ans = collections.defaultdict(list)
        for each in strs:
            hash_table = [0] * 26
            for char in each:
                hash_table[ord(char) - ord('a')] += 1
            ans[tuple(hash_table)].append(each)
        return ans.values()
# '''defaultdict(<class 'list'>,
#         {(1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0):       ['eat', 'tea', 'ate'],
#         (1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0): ['tan', 'nat'],
#         (1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0): ['bat']})'''

    def groupAnagrams_2(self, strs: List[str]) :
        res=[]
        #Find the ord of each strings in strs
        d={}
        for i in range(len(strs)):
            num=0
            for j in strs[i]:
                num+=ord(j)
            d[strs[i]]=str(num)
        #d={'eat': '314', 'tea': '314', 'tan': '323',
        #   'ate': '314', 'nat': '323', 'bat': '311'}
        #Arrange strs by the accsi code
        #相同Accsi放在同一個list並加入另一個list中
        for i in d:
            l=[]
            l.append(i)
            for j in d:
                if i != j and d[i]==d[j]:
                    l.append(j)
            if sorted(l) not in res:
                res.append(sorted(l))
            #[['ate', 'eat', 'tea'], ['nat', 'tan'], ['bat']]
        return res
#         i just realize i misunderstanding the meaning of the problem













