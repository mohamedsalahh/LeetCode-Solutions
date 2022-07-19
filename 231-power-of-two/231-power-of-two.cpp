class Solution {
public:
    bool isPowerOfTwo(int n) {
        for(int i = 0; i < 31; i++)
        {
            if((n^(1<<i)) == 0) return true;
        }
        return false;
    }
};