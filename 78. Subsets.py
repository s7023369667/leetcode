from typing import List


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = [[]]
        for n in nums:
            for i in range(len(res)):
                res.append(res[i] + [n])
        return res

    '''         res[i]       [n]    res[i] + [n]        res
    [1]           []         [1]        [1]            [],[1]
    -----------------------------------------------------------------------------------------------
    [1,2]         []         [2]        [2]            [],[1],[2]
                  [1]        [2]        [1,2]          [],[1],[2],[1,2]
    -----------------------------------------------------------------------------------------------
    [1,2,3]       []         [3]        [3]            [],[1],[2],[1,2],[3]
                  [1]        [3]        [1,3]          [],[1],[2],[1,2],[3],[1,3]
                  [2]        [3]        [2,3]          [],[1],[2],[1,2],[3],[1,3],[2,3]
                  [1,2]      [3]        [1,2,3]        [],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]
    -----------------------------------------------------------------------------------------------
    '''

    def subsets_recursive(self, nums: List[int]) -> List[List[int]]:
        if len(nums) == 0:
            return [[]]
        sub_solution = self.subsets(nums[:-1])
        subset=[s + [nums[-1]] for s in sub_solution]
        return sub_solution + subset

    '''
    recursive function thinking :
    1.boundary setting
    2.motivation
    3.how we return we need
    R([1,2,3,4])
        R([1,2,3])
            R([1,2])
                R([1])
                    R([])
                    return [[]]
                return [[1]] 
            return sub_solution([],[1])+[2] >> [],[1],[2],[1,2]
        return sub_solution([],[1],[2],[1,2]) +[3] >>[],[1],[2],[1,2],|[3],[1,3],[2,3],[1,2,3]
    return sub_solution([],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]) + [4]
    >>[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3],|[4],[1,4],[2,4],[1,2,4],[3,4],[1,3,4],[2,3,4],[1,2,3,4]
    '''


















