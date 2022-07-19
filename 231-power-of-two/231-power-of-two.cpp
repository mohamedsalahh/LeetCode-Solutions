class Solution {
public:
    bool isPowerOfTwo(int n) {
        for(int i = 1; i <= 31; i++)
        {
            if((n^(1<<(i-1))) == 0) return true;
        }
        return false;
    }
};