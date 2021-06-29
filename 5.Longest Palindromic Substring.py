def longestPalindrome( s: str):
    pal = ""
    long = 0
    if len(s) == 1:
        return s
    else:
        for i in range(len(s)):
            temp = []
            temp.append(s[i])
            for j in range(i + 1, len(s)):
                t = len(temp)
                temp.append(s[j])
                if temp[::1] == temp[::-1] and t >= long:
                    pal = "".join(temp)
                    long = len(pal)
    if pal == "":
        return s[1]

    return pal

ans=longestPalindrome("dsdssalelfefwvwfsa")
print(ans)