class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> prevIdx(226, -1);
        int ans = 0;
        int cnt = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(prevIdx[s[i]] != -1)
            {
                ans = max(ans, cnt);
                cnt = i - prevIdx[s[i]] - 1;
                for(int k = 0; k < 226; ++k)
                    if(prevIdx[k] < prevIdx[s[i]])
                        prevIdx[k] = -1;
            }
            cnt++;
            prevIdx[s[i]] = i;
        }
        ans = max(ans, cnt);
        return ans;
    }
};