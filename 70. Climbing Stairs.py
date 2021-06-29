class Solution:
    def climbStairs_1(self, n: int) -> int:
        if n == 1:
            return 1
        elif n == 2:
            return 2
        else:
            l = [0, 1]
            for i in range(n):
                add = l[-2] + l[-1]
                l.append(add)
            return l[-1]
    #     '''5=1+1+1+1+1         8=1+...+1
    #      =1+2+2              =2+2+2+2
    #      =2+2+1              =1+1+2+2+2
    #      =2+1+2
    #      =1+1+1+2'''
    def climbStairs_2(self, n: int) -> int:
        ways=0
        temp=n//2
        t=temp
        separt=1
        if n%2 != 0 :#n is odd.
            for i in range(temp+1,n+1):
                w=self.step(i+1)
                p=self.step(separt*2+1)
                q=self.step(t-1)
                ways = ways + w//(q*p)
                t=t-1
                separt=separt+1
            print(ways)
            return ways+temp+1
        else:#n is even.
            for i in range(temp+1,n+1):
                w=self.step(i)
                p=self.step(separt*2)
                q=self.step(t-1)
                ways = ways + w//(q*p)
                t=t-1
                separt=separt+1
            print(ways)
            return ways+1 #At least could be sperate by 2.
    def step(self,x):
        w=1
        while (x>0):
            w *= x
            x -= 1
        return w



