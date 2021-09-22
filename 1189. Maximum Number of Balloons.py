class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        d={'b':0,'a':0,'l':0,'o':0,'n':0}
        for txt in text:
            if txt in d:
                d[txt]+=1
        d['l']//=2
        d['o']//=2
        return min(d.values())