from typing import List


class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        ans = set()
        for email in emails:
            l = email.split('@')
            front = l[0]
            end = "@" + l[1]
            start = ""
            if '+' in front:
                front = front.split('+')[0]
            for c in front:
                if c == '.':
                    continue
                else:
                    start += c
            final = start + end
            ans.add(final)
        return len(ans)
        ##bad method:
        # forward = set()
        # count=0
        # for email in emails:
        #     end,stop=-1,0
        #     for i in range(len(email)):
        #         if email[i]=="+" and end == -1:
        #             end = i
        #         elif email[i]=="@":
        #             stop = i
        #             break
        #         elif email[i]=='.':
        #             email = email[:i] + email[i+1:]
        #     if end != -1:
        #         email = email[:end] + email[stop:]
        #     forward.add(email)
        # return len(forward)



