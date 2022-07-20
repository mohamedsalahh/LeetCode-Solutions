class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0)
            return 1;
        int ans = 0;
        int idx = 0;
        while(n)
        {
            if((n & 1) == 0) 
                ans |= 1 << idx;
            n >>= 1;
            idx++;
        }
        return ans;
    }
};