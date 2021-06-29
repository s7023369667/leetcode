class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        start = 0
        found_s = True
        for char in s:
            at = t.find(char, start)
            if at == -1:
                found_s = False
                break
            start = at + 1
        return found_s

    def isSubsequence_(self, s: str, t: str) -> bool:
        if len(s) == 0:
            return True
        isSubsequence, STOP = False, False
        idx = 0
        for i in range(len(s)):
            if not STOP:
                if s[i] in t:
                    while idx < len(t):
                        # print(idx)
                        if s[i] == t[idx]:
                            at = idx
                            # print(at)
                            isSubsequence = True
                            break
                        else:
                            isSubsequence = False
                        idx += 1
                    idx = at + 1
                    if idx == len(t):
                        STOP = True
                else:
                    isSubsequence = False
                    break
            else:
                isSubsequence = False
                break
        return isSubsequence

    def isSubsequence__(self, s: str, t: str) -> bool:
        ##Brute Force
        cnt = 0
        for i in t:
            if cnt == len(s):
                return True
            if s[cnt] == i:
                cnt += 1
        return cnt == len(s)
