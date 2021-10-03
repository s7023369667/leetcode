class Solution:
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:

        def convert_k(answerKey, k, pattern):
            maxx = 0
            j = 0
            for i in range(len(answerKey)):
                if not answerKey[i] == pattern:
                    k -= 1
                while k < 0:
                    if not answerKey[j] == pattern:
                        k += 1
                    j += 1
                maxx = max(maxx, i - j + 1)
            return maxx

        return max(convert_k(answerKey, k, 'T'), convert_k(answerKey, k, 'F'))

