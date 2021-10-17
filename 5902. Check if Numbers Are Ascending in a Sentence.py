class Solution:
    def areNumbersAscending(self, s: str) -> bool:
        def check(string):
            for c in string:
                if ord(c) > 59 or ord(c) < 48:
                    return False
            return True

        sp = s.split(' ')
        digits = []
        for i in range(len(sp)):
            if check(sp[i]):
                digits.append(int(sp[i]))
        for i in range(len(digits)):
            for j in range(i + 1, len(digits)):
                print(digits)
                if digits[i] >= digits[j]:
                    digits[i], digits[j] = digits[j], digits[i]
                    return False
        return True
