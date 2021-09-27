class Solution:
    def tribonacci(self, n: int) -> int:
        if n == 1:
            return 1

        a, b, c = 0, 1, 1
        dp = [a, b, c]
        for i in range(n):
            dp.append(b + c)
            a, b, c = b, c, a + b + c
        ans = 0
        for i in range(n):
            ans += dp[i]
        return ans