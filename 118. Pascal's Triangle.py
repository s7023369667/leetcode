class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 1:
            return [[1]]
        if numRows == 2:
            return [[1], [1, 1]]
        output = [[1], [1, 1]]
        for i in range(2, numRows):
            tmp, fill = output[-1], [1, 1]
            for j in range(1, i):
                fill.insert(j, tmp[j - 1] + tmp[j])
            output.append(fill)
        return output

        # '''
        # 1
        # 1   1
        # 1   2   1
        # 1   3   3   1
        # 1   4   6   4   1
        # 1   5   10  10  5   1
        # .
        # .
        # .'''
