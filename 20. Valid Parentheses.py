class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        d = {'(': 0, ')': 0,
             '[': 1, ']': 1,
             '{': 2, '}': 2}
        for i in s:
            # if we visit the left Parentheses push into stack.
            if i == "(" or i == "[" or i == "{":
                stack.append(i)
            else:
                # we have case that only contain right Parentheses.
                # so it's mean nothing in stack of the case.
                if stack:
                    # pop the last one
                    x = stack.pop()
                    # check if they could combine into a vaild pair.
                    if d[i] == d[x]:
                        continue
                    else:
                        return False
                # nothing in stack so return false.
                else:
                    return False
        # check if any remains in stack.
        # stack is empty then vaild.
        if not stack:
            return True
        # stack is not empty then invaild.
        else:
            return False
