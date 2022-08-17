class Solution {
public:
    int arrangeCoins(int n) {
        double x = (double) -1 + sqrt(1+4*2*(double)n);
        return x / 2;
    }
};