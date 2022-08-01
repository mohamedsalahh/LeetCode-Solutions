class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0, idx = 0;
        
        for(int i = columnTitle.size()-1; i >= 0; --i, ++idx)
            ans += pow(26, idx) * (columnTitle[i] - 'A' + 1);

        return ans;
    }
};