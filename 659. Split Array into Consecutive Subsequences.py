class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        freq, need = collections.Counter(nums), collections.Counter()

        for i in nums:
            # print('freq', freq)
            # print('need', need)
            if not freq[i]:
                continue
            freq[i] -= 1
            if need[i - 1] > 0:
                # print('case1')
                need[i - 1] -= 1
                need[i] += 1
            elif freq[i + 1] and freq[i + 2]:
                # print('case2')
                freq[i + 1] -= 1
                freq[i + 2] -= 1
                need[i + 2] += 1
            else:
                # print('case3')
                return False
        return True
