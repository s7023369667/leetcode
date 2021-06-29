class Solution:
    def intToRoman(self, num: int) -> str:
        # d = {1000: "M", 900: "CM", 500: "D", 400:
        #  "CD", 100: "C", 90: "XC", 50: "L", 40:
        #  "XL", 10: "X", 9: "IX", 5: "V", 4: "IV", 1: "I"}
        # s = ''
        # for value,char in d.items():
        #     #if the value is higher than we need,s will add a blankspace instead,
        #     #otherwise, we add the char with exactly numbers.
        #     s =s + char*(num // value)
        #     #we only need to trace the remain number.
        #     num %= value
        # return s
        '''
        1994 = M*1 + CM*1 + C*1 +IN *1
        '''
        d = {"M": 1000, "CM": 900, "D": 500, "CD": 400,
             "C": 100, "XC": 90, "L": 50, "XL": 40, "X": 10,
             "IX": 9, "V": 5, "IV": 4, "I": 1}
        ans = ""
        while num != 0:
            for key, val in d.items():
                if val == num:
                    ans = ans + key
                    num = num - val
                    break
                elif val < num:
                    ans = ans + key
                    num = num - val
                    break
                else:
                    continue
        return ans


'''
2>> II
3>> III
5>> V
6>> VI
<--bigger--------smaller-->

4 >>  IV
9 >>  IX
40 >>  XL
90 >>  XC
400>>  CD
900>>  CM
<--smaller--------bigger-->
'''








