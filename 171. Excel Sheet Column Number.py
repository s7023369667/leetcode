class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        d = {'A': 1, 'B': 2, 'C': 3, 'D': 4, 'E': 5, 'F': 6, 'G': 7, 'H': 8, 'I': 9,
             'J': 10, 'K': 11, 'L': 12, 'M': 13, 'N': 14, 'O': 15, 'P': 16, 'Q': 17, 'R': 18,
             'S': 19, 'T': 20, 'U': 21, 'V': 22, 'W': 23, 'X': 24, 'Y': 25, 'Z': 26}
        addup = 0
        columnTitle = columnTitle[::-1]
        for col in range(len(columnTitle)):
            tmp = d[columnTitle[col]] * (26 ** col)
            addup += tmp
        return addup


        #'ZYY' = 26*26*26+26*25+25 = 17576+650+25 = 18251
