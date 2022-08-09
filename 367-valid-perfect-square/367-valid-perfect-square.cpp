class Solution {
public:
    bool isPerfectSquare(int num) {
        for(long long i = 1; i < 50000; ++i)
            if(i * i == num)
                return true;
        return false;
    }
};