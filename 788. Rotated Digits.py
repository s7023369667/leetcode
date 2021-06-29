class Solution:
    def rotatedDigits(self, n: int) -> int:
        d = {'good': '2569',
             'null': '018',
             'bad': '347'}
        cnt = 0
        for num in range(1, n + 1):
            GOOD = False
            num = str(num)
            for char in num:
                if char in d['bad']:
                    GOOD = False
                    break
                elif char in d['good']:
                    GOOD = True

            if GOOD:
                print(num)
                cnt += 1

        return cnt


'''
n=20

2,5,6,9
11(X),12,15,16,19,20

'''

