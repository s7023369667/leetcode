class Solution:
    def convert(self, s: str, numRows: int) -> str:
        res = []
        space = numRows - 1
        idx = 0
        while idx < len(s):
            tmp = []
            for i in range(numRows):
                if idx + i >= len(s):
                    tmp += [' '] * (numRows - len(tmp))
                    break
                else:
                    tmp += [s[idx + i]]
            res.append(tmp)
            idx += numRows
            for k in range(space - 1, 0, -1):
                if idx >= len(s):
                    break
                else:
                    print(idx)
                    mid = [' '] * numRows
                    mid[k] = s[idx]
                    res.append(mid)
                    idx += 1
        # for row in res:
        #     print(row)
        string = ''
        for i in range(numRows):
            for j in range(len(res)):
                if res[j][i] != ' ':
                    string += res[j][i]
        return string

    '''
    PAY                             PAYP
     P                                A
    ALI                              L
     S      ->  PAHNAPLSIIGYIR      ISHI    -> PINALSIGYAHRPI
    HIR                               R
     I                               I
    NG                              NG
    '''

