class Solution:
    def longestCommonPrefix(self, strs: 'List[str]') -> 'str':
        # problem
        # base case:
        if not strs: return ""
        # find the largest strings in strs
        s_max = max(strs)
        print("max", s_max)
        # finde the smallest strings in strs
        s_min = min(strs)
        print("min", s_min)
        """
        max,min help as to find :
                alphabetical order The smallest and largest strings.
        We only need the check the common between the largest and the                     smallest string to get the longest common prefix
            for example:
            s_max="flower"
            s_min="flight"
        """
        # i is the index of s_min,char is s_min[i]
        for i, char in enumerate(s_min):
            """   because we give the alphabetical order The smallest and largest                    strings,so if the char are the same means the substring is the                    same"""
            if char != s_max[i]:
                # 任一個char不同時，回傳substring表示前面皆相同
                return s_min[:i]
            continue  # 相同時跳下一個比
        # 除非s_max和s_min完全相同
        return s_min
