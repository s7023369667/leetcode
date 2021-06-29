from typing import List


class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        s="".join(map(str,digits)) #concate all the digits into a string: s.
        temp=[]
        t=int(s)+1  #t is the number after plus 1.
        '''Handle all the general cases.'''
        for i in str(t):
            temp.append(i)
        if len(temp) != len(s) and not t%10==0:
        # '''Only the basic cases ,e.g.[0]~[9],[0,0]~[0,9],.....
        # After we plus "1" on s ,we may get some answers that
        # the length is not equal to s,however,they are not
        # because of the carry.'''
            add = len(s)-len(temp) #How many zeros we need to add?
            for i in range(add):
                temp.insert(0,0)
        return temp