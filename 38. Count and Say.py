class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return "1"
        '''
        "1">>>"11">>>"21">>>"12"+"11">>>111221
        #case1: 11 >> "2"+"1"
        #case2: 21 >> "1"+"2"+"1"+"1"
        '''
        # recursion form n to 1
        say = self.countAndSay(n - 1)
        ans = ""  # answer string
        cnt = 1  # count the same digital in say
        i = 1  # the run of the say

        # find how many exactly of your neighbors are the same.
        while i < len(say) + 1:  # how times we have to do in this run.

            # let's count the numbers of the same digital
            if i < len(say) and say[i] == say[i - 1]:
                cnt += 1
            # not the same anymore ,so lets combine the digital and say
            else:
                ans = ans + str(cnt) + say[i - 1]
                # reset the cnt for next digital in say
                cnt = 1
            # next digital of this say
            i += 1
        print(ans)
        return ans












