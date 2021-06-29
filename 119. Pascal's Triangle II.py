class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        ans = [1]
        for i in range(1, rowIndex + 1):
            tmp = ans[i - 1] * (rowIndex + 1 - i) // i
            print(tmp)
            ans.append(tmp)
        return ans

     # '''
     # 5|   1   5   10  10  5   1
     # 4|   1   4   6   4   1
     # 3|   1   3   3   1
     # 2|   1   2   1
     # 1|   1   1
     # 0|   1
     # '''