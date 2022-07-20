class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        int idx = 0;
        while(num)
        {
            if((num & 1) == 0) ans |= 1<<idx;
            num >>= 1;
            idx++;
        }
        return ans;
    }
};