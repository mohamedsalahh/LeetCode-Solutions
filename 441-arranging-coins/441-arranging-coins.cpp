class Solution {
public:
    int arrangeCoins(int n) {
        double x = sqrt(1+4*2*(double)n) - 1;
        return x / 2;
    }
};