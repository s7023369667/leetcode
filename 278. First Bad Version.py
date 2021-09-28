# The isBadVersion API is already defined for you.
# @param version, an integer
# @return an integer
def isBadVersion(version):
    ##This API gived from the question to check the bad version.
    pass

class Solution:
    def firstBadVersion(self, n):

        def BS(left, right):
            if not left <= right:
                return left
            midd = (left + right) // 2
            if isBadVersion(midd):
                return BS(left, midd - 1)
            else:
                return BS(midd + 1, right)

        return BS(0, n - 1)
