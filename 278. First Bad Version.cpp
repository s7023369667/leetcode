// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long l=0, r=n;
        while (l<=r){
            long mid = (l+r)/2;
            if (isBadVersion(mid)){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};
