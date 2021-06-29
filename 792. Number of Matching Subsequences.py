class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        match = 0
        for word in words:
            start = 0
            found_word = True
            for char in word:
                at = s.find(char, start)
                if at == -1:
                    found_word = False
                    break
                start = at + 1
            if found_word:
                match += 1
        return match
