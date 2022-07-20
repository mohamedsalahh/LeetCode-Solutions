class Solution {
public:
    int binaryGap(int n) {
        int ans = 0;
        int pIdx = 0, cIdx = 0;
        while((n & 1) == 0)
        {
            n >>= 1;
            cIdx++;
        }
        pIdx = cIdx;
        cIdx++;
        n >>= 1;
        while(n)
        {
            if(n & 1)
            {
                ans = max(ans, cIdx-pIdx);
                pIdx = cIdx;
            }
            cIdx++;
            n >>= 1;
        }
        return ans;
    }
};