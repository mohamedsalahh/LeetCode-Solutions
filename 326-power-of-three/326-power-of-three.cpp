class Solution {
public:
    bool isPowerOfThree(int n) {
        cout << log(n) / log(3) << " " << ceil(log(n) / log(3));
        if(n == 0)
            return false;
        return ceil(log(n) / log(3)) - log(n) / log(3) <= 0.000000000009;
    }
};