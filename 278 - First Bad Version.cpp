// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        int begin = 1;
        int end = n;
        int m;
        while (begin <= end) {
            m = end + (begin-end)/2;
            if (isBadVersion(m) && !isBadVersion(m-1)) {
                return m;
            }
            if (isBadVersion(m)) {
                end = m-1;
            }
            else {
                begin = m+1;
            }
        }
        return m;
    }
};
