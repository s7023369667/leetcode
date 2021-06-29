class Solution:
    def numTrees(self, n: int) -> int:
        return self.CatalanNumber(n)

    def CatalanNumber(self, n):
        '''
        𝐶𝑛=1/(𝑛+1)*C(2n,n)=(2𝑛)!/(𝑛+1)!𝑛!
        ⟹ 𝐶𝑛=[2(2𝑛−1)/n+1]𝐶𝑛−1.
        '''
        if n <= 1:
            return 1
        return int((2 * (2 * n - 1) / (n + 1)) * self.CatalanNumber(n - 1))

