class Solution:
    def reverse(self, x: int) -> int:
        # if x<2147483648 and x>-2147483649:
        #     if x>=0:
        #         x=str(x)
        #         l=[]
        #         for i in x:
        #             l.append(i)
        #         l=l[::-1]
        #         ans=""
        #         for i in l:
        #             ans=ans+i
        #         if int(ans)<2147483648:
        #             return int(ans)
        #         else:
        #             return 0
        #     else:
        #         x=str(x)
        #         l=[]
        #         for i in x:
        #             l.append(i)
        #         l=l[::-1]
        #         l=l[:-1]
        #         ans=""
        #         for i in l:
        #             ans=ans+i
        #         if -int(ans)>-2147483649:
        #             return -int(ans)
        #         else:
        #             return 0
        # else:
        #     return 0

        min_ans = -2 ** 31
        max_ans = 2 ** 31 - 1
        # convert into strings and invert back with integer return
        # x is positive or zero:
        if x >= 0:
            ans = int(str(x)[::-1])
        # x is negative:
        else:
            ans = -1 * int(str(x * (-1))[::-1])
        # check wheather ans in the range of the requestion
        if ans not in range(min_ans, max_ans):
            return 0
        else:
            return ans






