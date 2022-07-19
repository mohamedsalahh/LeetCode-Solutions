class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans = 0, x = n;
        for(int i = 0; i < 32; ++i)
        {
            ans |= (((x >> i) & 1) << (31-i));
        }
        return ans;
    }
};