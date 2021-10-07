class Solution:
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        def _help(answerKey,index,k):
            maxx_con = 1
            cnt=1
            tmp = answerKey[0]
            while index < len(answerKey):
                if answerKey[index] == tmp:
                    cnt+=1
                else:
                    if k>0:
                        if answerKey[index]=='T':
                            change = answerKey[:index] + 'F' + answerKey[index+1:]
                        else:
                            change = answerKey[:index] + 'T' + answerKey[index + 1:]
                        print(change)
                        _help(change,index,k-1)
                    else:
                        tmp=answerKey[index]
                        cnt=1
                if cnt>maxx_con:
                    maxx_con=cnt
                print("maxx_con",maxx_con)
                index+=1
            return maxx_con
        _help(answerKey,0,k)

if __name__ == '__main__':
    answerKey = "TFFT"
    k = 1
    s = Solution()
    print(s.maxConsecutiveAnswers(answerKey,k))