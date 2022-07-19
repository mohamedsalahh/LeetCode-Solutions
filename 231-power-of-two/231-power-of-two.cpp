class Solution {
public:
    bool isPowerOfTwo(int n) {
        for(int i = 1; i <= 1073741824; i*=2)
        {
            if((n^i) == 0) return true;
            if(i == 1073741824) break;
        }
        return false;
    }
};