class Solution {
public:
    static bool cmp(int x, int y)
    {
        if(__builtin_popcount(x) != __builtin_popcount(y)) 
            return __builtin_popcount(x) < __builtin_popcount(y);
        return x < y;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};