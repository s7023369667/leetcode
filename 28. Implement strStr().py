class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        # 找出str2出現在str1的第一個index
        if needle == "" and not haystack == "":
            return 0
        elif needle == haystack:
            return 0
        else:
            for i in range(len(haystack)):
                if haystack[i:i + len(needle)] == needle:
                    return i
        return -1



