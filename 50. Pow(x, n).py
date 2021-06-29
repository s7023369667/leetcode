class Solution:
    def myPow(self, x: float, n: int) -> float:

        if n == 0:
            return 1
        return self.fastPow(x, n)

    def fastPow(self, x, n):
        res = 1
        if n > 0:
            sign = "+"
        else:
            sign = "-"
        n = abs(n)
        while n >= 1:
            i = 0  # 從0次項開始
            temp_res = x  # x=2
            while n >= (2 << i):  # n=10 #如果還在範圍內#(2<<i) :代表2*(2^i),e.g.12<<2 =48
                temp_res = temp_res * temp_res
                i += 1
                if n >= (2 << i):
                    continue
                else:  # 已經超出範圍
                    i = i - 1  # 扣一個回來
                    break
            res = res * temp_res
            n = n - (2 << i)  # 把值扣掉繼續做 #13^11 =13^(2^3+2^1+2^0)
        if n == 1:  # odd
            res = res * x
        if sign == "+":
            return res
        else:
            return 1 / res











