class Solution:
    def romanToInt(self, s: str) -> int:
        d={"I":1,"V":5,"X":10,"L":50,"C":100,"D":500,"M":1000}
        ans = d[s[-1]]
        for i in range(len(s)-1):
            if d[s[i]]>=d[s[i+1]]:
                ans = ans + d[s[i]]
            else:
                ans = ans - d[s[i]]
        return ans

        # M"CM""XC""IV"
        # 1000+(1000-100)+(100-10)+(5-1)=1994
        # if the case is minus this char
