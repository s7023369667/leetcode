class Solution:
    def addBinary(self, a: str, b: str) -> str:
        # turn a into decimal
        int_a = 0
        a = a[::-1]
        for i in range(len(a)):
            if int(a[i]) == 1:
                int_a = int_a + 2 ** i
                # turn b into decimal
        int_b = 0
        b = b[::-1]
        for i in range(len(b)):
            if int(b[i]) == 1:
                int_b = int_b + 2 ** i
        # summary a and b
        summary = int_a + int_b
        # basic case
        if summary == 0:
            return "0"
        # general cases
        s = ""
        while summary // 2 != 0:
            s = s + str(summary % 2)
            summary = summary // 2
        # always gets "1" remain
        s = s + "1"
        # return s in backwards
        return s[::-1]


