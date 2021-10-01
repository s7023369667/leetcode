class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        dp =[[0 for i in range(len(text1)+1)] for j in range(len(text2)+1)]

        for i in range(len(text2)):
            for j in range(len(text1)):
                if text1[j] == text2[i] :
                    dp[i+1][j+1] = dp[i][j]+1
                else:
                    dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1])
        return dp[-1][-1]