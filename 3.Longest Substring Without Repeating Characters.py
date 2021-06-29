# def lengthOfLongestSubstring( s):
#     """
#     :type s: str
#     :rtype: int
#     """
#     output = 0
#     s = s.lower()
#     for i in range(len(s)):
#         out = []
#         ii = s[i]
#
#         out.append(i)
#         for j in range(i + 1, len(s)):
#             if s[i] == s[j]:
#                 output=1
#                 continue
#             out.append(j)
#
#             if output < len(out):
#                 output = len(out)
#
#     return output
#
# """
# problem:
# 1.如果i和大多數j不相同
# 2.如果str是同個char組成
# """
#
# ans=lengthOfLongestSubstring("bbbbb")
# print(ans)
#
#
#
#
#

def lengthOfLongestSubstring( s):
    """
    :type s: str
    :rtype: int
    """
    temp = []
    ans = []
    for i in range(len(s)):
        if s[i] not in temp:
            temp.append(s[i])
        else:
            index=temp.index(s[i])
            temp = temp[index+1:]
            temp.append(s[i])
            print(temp)
        if len(temp) >= len(ans):
            ans = temp
            #ans和temp會在第一run之後變成一模一樣

    return len(ans)

"""
problem:
1.如果i和大多數j不相同
 """
# ans=lengthOfLongestSubstring("pwwkew")
# ans=lengthOfLongestSubstring("abcabcab")
ans=lengthOfLongestSubstring("dvdf")
print(ans)






