from typing import List


class Solution:
    def advantageCount(self, A: List[int], B: List[int]) -> List[int]:
        #Step1:sorted A and B(with the original index accompany)
        sortedA = sorted(A)
        sortedB = sorted([(b, i) for i, b in enumerate(B)])
        print(sortedA)
        print(sortedB)
        tmp = [-1] * len(A)
        notMatch = []
        i, j = 0, 0
        ##Give two pointer form the very first start.
        while i < len(A) and j < len(A):
            ##Use Greedy Strategy !
            if sortedA[i] > sortedB[j][0]:
                tmp[sortedB[j][1]] = sortedA[i]
                i += 1
                j += 1
            else:
                ##if we meet the unmatch numbers,don't worry just skip,so how it will be done .
                notMatch.append(sortedA[i])
                i += 1
        ##Deal with the unmatched number by append in any order.
        for i in range(len(A)):
            if tmp[i] == -1:
                tmp[i] = notMatch.pop()
        return tmp





















